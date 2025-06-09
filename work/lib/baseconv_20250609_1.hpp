//https://atcoder.jp/contests/abc105/tasks/abc105_c
//by truncated divisioin (c++ default)
template<class T,class U>
vector<U>baseconv(T n,U b,bool desc=0){
	assert(abs(b)>1);
	if(!n)return{0};
	vector<U>res;
	while(n){
		int q=n/b,r=n-q*b;
		assert(q*b+r==n);
		if(r<0){
			if(b<0)r-=b,q++;
			else r+=b,q--;
		}
		res.push_back(r);
		n=q;
	}
	if(desc)reverse(res.begin(),res.end());
	return res;
}
