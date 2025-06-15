//newton's method
//https://atcoder.jp/contests/abc400/submissions/66803099
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x=n>>1,nx;
	do{nx=x+n/x>>1;}while(nx<x&&(x=nx));
	return x;
}
