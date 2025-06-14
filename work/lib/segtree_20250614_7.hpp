//lazy build
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
//https://atcoder.jp/contests/practice2/submissions/66710105
//https://atcoder.jp/contests/practice2/submissions/66710116
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
		if(l+1==r)return get(l);
		build();
		l+=w,r+=w;
		T vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);
			if(r&1)vr=op(d[--r],vr);
			l>>=1,r>>=1;
		}
		return op(vl,vr);
	}
	template<class F>
	int max_right(int i,F f){
		assert(0<=i&&i<=n);
		if(i==n)return n;
		build();
		T x=e();
		i+=w;
		while(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return n;}
		while(i<w)if(f(op(x,d[i<<=1])))x=op(x,d[i++]);
		assert(i<w+n);
		return i-w;
	}
	template<class G>
	int min_left(int i,G f){
		assert(0<=i&&i<=n);
		if(i==0)return 0;
		build();
		T x=e();
		i+=w;
		if(i==1)i=2;
		while(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return 0;}
		while(i<=w)if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);
		assert(w<i&&i<=w+n);
		return i-w;
	}
};
