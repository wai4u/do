template<class A>
vector<int>argsort(A a,bool desc=0,bool rev=0){
	int n=a.size();
	vector<int>p(n);
	for(int i=0;i<n;i++)p[i]=i;
	sort(p.begin(),p.end(),[&](int i,int j){
		if(a[i]!=a[j])return desc?a[i]>a[j]:a[i]<a[j];
		return rev?i>j:i<j;
	});
	return p;
}
template<class A>
vector<int>rankify(A a){
	int n=a.size();
	if(!n)return{};
	auto p=argsort(a);
	vector<int>r(n);
	r[p[0]]=0;
	for(int i=1;i<n;i++)r[p[i]]=r[p[i-1]]+(a[p[i]]>a[p[i-1]]);
	return r;
}
