//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
//binary
template<class T>T gcd(T a,T b){
	a=abs(a),b=abs(b);
	if(!a)return b;
	if(!b)return a;
	int i=__builtin_ctzll(a),j=__builtin_ctzll(b),k=min(i,j);
	a>>=i,b>>=j;
	while(a!=b){
		if(a<b)swap(a,b);
		a-=b;
		a>>=__builtin_ctzll(a);
	}
	return a<<k;
}
