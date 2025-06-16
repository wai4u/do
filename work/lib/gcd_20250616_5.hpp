//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
template<class T>T gcd(T a,T b){
	a=abs(a),b=abs(b);
	while(1){
		if(a<b)swap(a,b);
		if(!b)return a;
		a-=b;
	}
	//return a;
}
