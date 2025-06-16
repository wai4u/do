//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
template<class T>T gcd(T a,T b){
	a=abs(a),b=abs(b);
	while(b)a%=b,swap(a,b);
	return a;
}
