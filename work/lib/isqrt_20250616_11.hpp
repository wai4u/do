//https://atcoder.jp/contests/abc400/submissions/66824169
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x,y=T(1)<<(63-__builtin_clzll(n))/2+1;
	assert(y*y>=n);
	do{x=y,y=x+n/x>>1;}while(y<x);
	return x;
}
