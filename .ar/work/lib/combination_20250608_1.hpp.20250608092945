template<class T>
struct combination{
	vector<T>fact{1},ifact{1};
	void build(int n){
		int m=fact.size();
		if(m>n)return;
		n=max(n,m+m);
		fact.resize(n+1);
		ifact.resize(n+1);
		for(int i=m;i<=n;i++)fact[i]=fact[i-1]*i;
		ifact[n]=1/fact[n];
		for(int i=n;i-->m;)ifact[i]=ifact[i+1]*(i+1);
	}
	T C(int n,int k){
		if(k==0)return 1;
		if(k>n)return 0;
		build(n);
		return fact[n]*ifact[n-k]*ifact[k];
	}
};
