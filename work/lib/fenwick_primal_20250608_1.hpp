//primal
//internally 1-indexed
//https://judge.yosupo.jp/submission/291730
template<class T>
struct fenwick{
	int n=0;
	vector<T>a,s;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	template<class F>fenwick(int n,F f){init(n,f);}
	template<class U>fenwick(const vector<U>&a){init(a);}
	fenwick(const vector<T>&a){init(a);}
	void assign(int n,T x){
		this->n=n;
		a.assign(n,x);
		built=0;
	}
	void init(int n){assign(n,T{});}
	template<class F>void init(int n,F f){
		init(n);
		for(int i=0;i<n;i++)a[i]=f(i);
	}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void build(){
		if(built)return;
		built=1;
		s.assign(n+1,T{});
		for(int i=1;i<=n;i++){
			s[i]+=a[i-1];
			int j=i+(i&-i);
			if(j<=n)s[j]+=s[i];
		}
	}
	void add(int i,T x,bool upd=1){
		assert(0<=i&&i<n);//別にcheckしなくてもデータが存在すれば足すと捉えればいいが、実装ミス気づきやすくする
		a[i]+=x;
		if(!built||!upd){built=0;return;}
		i++;
		while(i<=n)s[i]+=x,i+=i&-i;
	}
	void set(int i,T x,bool upd=1){
		assert(0<=i&&i<n);
		if(built&&upd)add(i,x-a[i],1);
		else a[i]=x,built=0;
	}
	const T&get(int i){
		assert(0<=i&&i<n);
		return a[i];
	}
	//operator[]はa[i]かs[i]か曖昧だからあえてつけない。
	T sum(int i){
		assert(0<=i&&i<=n);
		build();
		T y{};
		while(i>0)y+=s[i],i-=i&-i;
		return y;
	}
	T sum(int l,int r){return sum(r)-sum(l);}
};
