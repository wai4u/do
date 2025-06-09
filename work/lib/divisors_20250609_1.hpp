//int
//https://atcoder.jp/contests/abc136/submissions/66634614
vector<int>divisors(int n,bool asc=0){
	vector<int>divs;
	for(int i=1;i*i<=n;i++)if(n%i==0){
		divs.push_back(i);
		if(i*i!=n)divs.push_back(n/i);
	}
	if(asc)sort(divs.begin(),divs.end());
	return divs;
}
