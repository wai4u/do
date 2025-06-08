//primal-dual
//internally 0-indexed
//https://judge.yosupo.jp/submission/291764
//https://judge.yosupo.jp/submission/291765
template<class T,bool dual=0>
struct fenwick{
	int n=0;
	vector<T>d,s;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	fenwick(int n,T x){init(n,x);}
	fenwick(const vector<T>&a){init(a);}
	template<class U>fenwick(const vector<U>&a){init(a);}
	template<class F>fenwick(int n,F f){init(n,f);}
	void init(int n){
		this->n=n;
		d.assign(n,T{});
		built=0;
	}
	template<class U>void assign(int n,U x){
		init(n,[&](int i){return x;});
	}
	void init(int n,T x){assign(n,x);}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	template<class F>void init(int n,F f){
		init(n);
		for(int i=0;i<n;i++)d[i]=f(i);
		if constexpr(dual)for(int i=n;--i>0;)d[i]-=d[i-1];
	}
	void build(){
		if(built)return;
		built=1;
		s=d;
		for(int i=0;i<n;i++){
			int j=i|i+1;
			if(j<n)s[j]+=s[i];
		}
	}
	void add(int i,T x,bool upd=1){
		if constexpr(!dual)assert(0<=i&&i<n);
		else assert(0<=i&&i<=n);//便宜上nを含める
		d[i]+=x;
		if(!built||!upd){built=0;return;}
		while(i<n)s[i]+=x,i|=i+1;
	}
	template<class U=void>
	enable_if_t<dual,U>add(int l,int r,T x,bool upd=1){
		assert(l<=r);
		if(l<r)add(l,x,upd),add(r,-x,upd);
	}
	//primalではsum(a[:i]) 閉区間!
	T operator[](int i){
		if constexpr(dual)assert(0<=i&&i<n);
		else assert(-1<=i&&i<n);//便宜上-1を含める
		build();
		T y{};
		while(i>=0)y+=s[i],i&=i+1,i--;
		return y;
	}
	//primalではa[i]
	T get(int i){
		assert(0<=i&&i<n);
		if constexpr(!dual)return d[i];
		else return(*this)[i];
	}
	//[0,i) 開区間!
	template<class U=T>
	enable_if_t<!dual,U>sum(int i){return(*this)[i-1];}
	//[l,r)
	template<class U=T>
	enable_if_t<!dual,U>sum(int l,int r){
		assert(l<=r);
		return l==r?T{}:sum(r)-sum(l);
	}
};
