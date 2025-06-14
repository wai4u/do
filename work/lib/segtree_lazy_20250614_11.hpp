//https://atcoder.jp/contests/practice2/submissions/66711875
//https://atcoder.jp/contests/practice2/submissions/66711863
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
//https://judge.yosupo.jp/submission/292924
//https://atcoder.jp/contests/practice2/submissions/66714342
template<class X,X(*op)(X,X),X(*e)(),class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>
struct segtree_lazy{
	int n=0,w=0,h=0;
	vector<X>d;vector<F>lz;
	bool built=0,hung=0;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	template<class G>
	segtree_lazy(int n,G f){init(n,f);}
	template<class U>
	segtree_lazy(const vector<U>&a){init(a);}
	void init(int n){
		this->n=n;
		w=h=1;while(w<n)w<<=1,++h;
		d.assign(w+w,e());
		lz.assign(w,id());
		hung=built=0;
	}
	template<class G>
	void init(int n,G f){
		init(n);
		for(int i=0;i<n;i++)d[w+i]=f(i);
	}
	template<class U>
	void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void upd(int i){if(built)while(i>>=1)merge(i);}
	void _apply(int i,F f){
		if(built||i>=w)d[i]=mapping(f,d[i]);
		if(i<w)lz[i]=composition(f,lz[i]);
	}
	void push(int i){if(hung){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}}
	void pull(int i){assert(0<=i&&i<n);if(hung){i+=w;for(int j=h;--j;)push(i>>j);}}
	void pull_all(){if(hung){for(int i=1;i<w;i++)push(i);hung=0;}}
	vector<X>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}
	void build(){
		if(built)return;
		pull_all();
		for(int i=w;--i;)merge(i);
		built=1;
	}
	void set(int i,X x){pull(i),d[i+=w]=x,upd(i);}
	void apply(int i,F f){pull(i),_apply(i+=w,f),upd(i);}
	const X&get(int i){pull(i);return d[i+w];}
	const X&operator[](int i){return get(i);}
	void apply(int l,int r,F f){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		if(l+1==r)return apply(l,f);
		apply(l,r,f,1,0,w);
		hung=1;
	}
	void apply(int L,int R,const F&f,int i,int l,int r){
		if(L<=l&&r<=R)return _apply(i,f);
		int c=l+r>>1;
		push(i);
		if(L<c)apply(L,R,f,i<<1,l,c);
		if(c<R)apply(L,R,f,i<<1|1,c,r);
		merge(i);
	}
	X prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e();
		if(l+1==r)return get(l);
		build();
		return prod(l,r,1,0,w);
	}
	X prod(int L,int R,int i,int l,int r){
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		push(i);
		if(R<=c)return prod(L,R,i<<1,l,c);
		if(c<=L)return prod(L,R,i<<1|1,c,r);
		return op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));
	}
	template<class G>
	int max_right(int l,G f){
		assert(0<=l&&l<=n);
		if(l==n)return n;
		build();
		X x=e();
		return max_right(l,f,x,1,0,w);
	}
	template<class G>
	int max_right(int L,G f,X&x,int i,int l,int r){
		if(L<=l){
			if(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}
			if(l+1==r)return l;
		}
		push(i);
		int c=l+r>>1,j=c<=L?L:max_right(L,f,x,i<<1,l,c);
		return j<c||j==n?j:max_right(L,f,x,i<<1|1,c,r);
	}
	template<class G>
	int min_left(int r,G f){
		assert(0<=r&&r<=n);
		if(r==0)return 0;
		build();
		X x=e();
		return min_left(r,f,x,1,0,w);
	}
	template<class G>
	int min_left(int R,G f,X&x,int i,int l,int r){
		if(r<=R){
			if(f(op(d[i],x))){x=op(d[i],x);return l;}
			if(l+1==r)return r;
		}
		push(i);
		int c=l+r>>1,j=R<=c?R:min_left(R,f,x,i<<1|1,c,r);
		return c<j?j:min_left(R,f,x,i<<1,l,c);
	}
};
