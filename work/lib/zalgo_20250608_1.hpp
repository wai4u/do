template<class A>
vector<int>zalgo(A a){
	int n=a.size();
	vector<int>z(n);z[0]=n;
	for(int i=1,l=1;i<n;i++){
		int r=l+z[l],d=r<=i?0:min(r-i,z[i-l]);
		while(i+d<n&&a[d]==a[i+d])++d;
		z[i]=d;
		if(i+d>r)l=i;
	}
	return z;
}
