//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
//binary
template<class T>T gcd(T a,T b){
	a=abs(a),b=abs(b);
	if(!a)return b;
	if(!b)return a;
	int k=min(__builtin_ctzll(a),__builtin_ctzll(b));
	a>>=k,b>>=k;
	while(1){
		a>>=__builtin_ctzll(a);
		b>>=__builtin_ctzll(b);
		if(a==b)return a<<k;
		if(a<b)swap(a,b);
		a-=b;
	}
}
