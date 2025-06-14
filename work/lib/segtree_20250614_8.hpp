//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
//https://atcoder.jp/contests/practice2/submissions/66713270
//https://atcoder.jp/contests/practice2/submissions/66713278
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n=0,w=0;
	vector<T>d;
	bool built=0;
	segtree(){}
	segtree(int n){init(n);}
	template<class F>segtree(int n,F f){init(n,f);}
	template<class U>segtree(const vector<U>&a){init(a);}
	void init(int n){
		this->n=n;
		w=1;while(w<n)w<<=1;
		d.assign(w+w,e());
		built=0;
	}
	template<class F>void init(int n,F f){
		init(n);for(int i=0;i<n;i++)d[w+i]=f(i);
	}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void build(){if(!built)for(int i=w;--i>0;)merge(i);built=1;}
	const T&get(int i){assert(0<=i&&i<n);return d[w+i];}
	const T&operator[](int i){return get(i);}
	void upd(int i){if(built)while(i>>=1)merge(i);}
	void set(int i,T x){assert(0<=i&&i<n);d[i+=w]=x,upd(i);}
	void apply(int i,T x){assert(0<=i&&i<n);d[i]=op(d[i+=w],x),upd(i);}
	T prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e();
		if(l+r==1)return get(l);
		build();
		return prod(l,r,1,0,w);
	}
	T prod(int L,int R,int i,int l,int r){
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		if(R<=c)return prod(L,R,i<<1,l,c);
		if(c<=L)return prod(L,R,i<<1|1,c,r);
		return op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));
	}
	template<class F>
	int max_right(int l,F f){
		assert(0<=l&&l<=n);
		if(l==n)return n;
		build();
		T x=e();
		return max_right(l,f,x,0,w,1);
	}
	template<class F>
	int max_right(int L,F f,T&x,int l,int r,int i){
		if(L<=l){
			if(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}
			if(l+1==r)return l;
		}
		int c=l+r>>1,j=c<=L?L:max_right(L,f,x,l,c,i<<1);
		return j<c||j==n?j:max_right(L,f,x,c,r,i<<1|1);
	}
	template<class F>
	int min_left(int r,F f){
		assert(0<=r&&r<=n);
		if(r==0)return 0;
		build();
		T x=e();
		return min_left(r,f,x,0,w,1);
	}
	template<class F>
	int min_left(int R,F f,T&x,int l,int r,int i){
		if(r<=R){
			if(f(op(d[i],x))){x=op(d[i],x);return l;}
			if(l+1==r)return r;
		}
		int c=l+r>>1,j=R<=c?R:min_left(R,f,x,c,r,i<<1|1);
		return c<j?j:min_left(R,f,x,l,c,i<<1);
	}
};
