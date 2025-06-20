//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n=0,w=0;
	vector<T>d;
	bool built=0;
	segtree(){}
	segtree(int n){init(n);}
	template<class F>
	segtree(int n,F f){init(n,f);}
	template<class U>
	segtree(const vector<U>&a){init(a);}
	void init(int n){
		this->n=n;
		w=1;while(w<n)w<<=1;
		d.assign(w+w,e());
		built=0;
	}
	template<class F>
	void init(int n,F f){
		init(n);
		for(int i=0;i<n;i++)d[w+i]=f(i);
	}
	template<class U>
	void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void build(){
		if(built)return;
		built=1;
		for(int i=w;--i>0;)merge(i);
	}
	const T&get(int i){
		assert(0<=i&&i<n);
		return d[w+i];
	}
	const T&operator[](int i){return get(i);}
	void set(int i,T x){
		assert(0<=i&&i<n);
		d[i+=w]=x;
		if(built)while(i>>=1)merge(i);
	}
	void apply(int i,T x){set(i,op(get(i),x));}
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
};
