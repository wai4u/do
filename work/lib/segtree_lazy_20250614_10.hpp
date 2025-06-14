//lazy build/apply-hanging
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
//https://atcoder.jp/contests/practice2/submissions/66709756
//https://atcoder.jp/contests/practice2/submissions/66709750
//https://judge.yosupo.jp/submission/292922
//https://atcoder.jp/contests/practice2/submissions/66714336
template<
class X,X(*op)(X,X),X(*e)(),
class F=X,X(*mapping)(F,X)=op,
F(*composition)(F,F)=op,F(*id)()=e
>
struct segtree_lazy{
	int n=0,w=0,h=0;
	vector<X>d;
	vector<F>lz;
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
	void push(int i){
		//if(lz[i]==id())return;//operator==がないとだめ
		if(!hung)return;
		_apply(i<<1,lz[i]);
		_apply(i<<1|1,lz[i]);
		lz[i]=id();
	}
	void pull(int i,int j=-1){
		if(!hung||!i)return;
		if(j==-1)j=32-__builtin_clz(i);
		while(--j>0)push(i>>j);
	}
	void pull_all(){if(hung){for(int i=1;i<w;i++)push(i);hung=0;}}
	vector<X>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}
	void build(){
		if(built)return;
		pull_all();
		for(int i=w;--i;)merge(i);
		built=1;
	}
	void pull_leaf(int i){assert(0<=i&&i<n);pull(i+w,h);}
	const X&get(int i){pull_leaf(i);return d[i+w];}
	const X&operator[](int i){return get(i);}
	void set(int i,X x){pull_leaf(i),d[i+=w]=x,upd(i);}
	void apply(int i,F f){pull_leaf(i),_apply(i+=w,f),upd(i);}
	void apply(int l,int r,F f){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		if(l+1==r)return apply(l,f);
		l+=w,r+=w;
		int L=l/(l&-l),R=r/(r&-r)-1;
		pull(L),pull(R);
		hung=1;
		while(l<r){
			if(l&1)_apply(l++,f);
			if(r&1)_apply(--r,f);
			l>>=1,r>>=1;
		}
		upd(L),upd(R);
	}
	X prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e();
		if(l+1==r)return get(l);
		l+=w,r+=w;
		build();
		pull(l/(l&-l)),pull(r/(r&-r)-1);
		X vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);
			if(r&1)vr=op(d[--r],vr);
			l>>=1,r>>=1;
		}
		return op(vl,vr);
	}
	template<class G>
	int max_right(int i,G f){
		assert(0<=i&&i<=n);
		if(i==n)return n;
		build();
		X x=e();
		i+=w,pull(i/=i&-i);
		while(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return n;}
		while(i<w){push(i);if(f(op(x,d[i<<=1])))x=op(x,d[i++]);}
		assert(i<w+n);
		return i-w;
	}
	template<class G>
	int min_left(int i,G f){
		assert(0<=i&&i<=n);
		if(i==0)return 0;
		build();
		X x=e();
		i+=w,pull(i/=i&-i);
		if(i==1)i=2;
		while(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return 0;}
		while(i<=w){push(i-1);if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);}
		assert(w<i&&i<=w+n);
		return i-w;
	}
};
