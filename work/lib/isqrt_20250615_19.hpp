//newton's method
//https://atcoder.jp/contests/abc400/submissions/66803125
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x,nx=n>>1;
	do{x=nx,nx=x+n/x>>1;}while(nx<x);
	return x;
}
