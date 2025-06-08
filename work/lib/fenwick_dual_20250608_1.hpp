//dual
//https://judge.yosupo.jp/submission/291759
//sequenceで初期化する場合は値配列を渡す(差分配列ではない)
template<class T>
struct fenwick{
	int n=0;
	vector<T>d,s;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	template<class F>fenwick(int n,F f){init(n,f);}
	template<class U>fenwick(const vector<U>&a){init(a);}
	fenwick(const vector<T>&a){init(a);}
	fenwick(int n,T x){init(n,x);}
	void init(int n){
		this->n=n;
		d.assign(n,T{});
		built=0;
	}
	template<class F>void init(int n,F f){
		init(n);
		for(int i=0;i<n;i++)d[i]=f(i);
		for(int i=n;--i>0;)d[i]-=d[i-1];
	}
	void init(int n,T x){init(n,[&](int i){return x;});}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
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
	//[i,n)
	void add(int i,T x,bool upd=1){
		assert(0<=i&&i<=n);//実用上nを含める
		d[i]+=x;
		if(!built||!upd){built=0;return;}
		while(i<n)s[i]+=x,i|=i+1;
	}
	//[l,r)
	void add(int l,int r,T x,bool upd=1){
		assert(0<=l&&l<=r&&r<=n);
		add(l,x,upd),add(r,-x,upd);
	}
	T get(int i){
		assert(0<=i&&i<n);//-1は含めない
		build();
		T y{};
		while(i>=0)y+=s[i],i&=i+1,i--;
		return y;
	}
	T operator[](int i){return get(i);}
};
