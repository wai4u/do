//for radius,not include center.
template<class A>
vector<int>manacher(const A&a,bool diam=0){
	int n=a.size();
	if(!n)return{};
	vector<int>D(n+n-1);
	for(int i=1,c=0;i<n+n-2;i++){
		int k=i/2,j=i-k,r=c/2+D[c];
		int d=r<=k?0:min(r-k,D[c+c-i]);
		while(j-d&&k+d+1<n&&a[j-d-1]==a[k+d+1])++d;
		D[i]=d;
		if(k+d>r)c=i;
	}
	if(diam)for(int i=0;i<n+n-1;i++)D[i]+=D[i]+(~i&1);
	return D;
}
