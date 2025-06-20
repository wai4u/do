//newton * 指数digit by digit
//https://stackoverflow.com/questions/78063269/time-complexity-of-python-3-8s-integer-square-root-math-isqrt-function
//https://atcoder.jp/contests/abc400/submissions/66820244
template<class T>int bitlen(T n){return n?64-__builtin_clzll(n):0;}
template<class T>T nsqrt(T n){
	if(n<4)return 1;
	int k=(bitlen(n)+1)/4;
	T x=nsqrt(n>>2*k)<<k;
	x=(x+n/x)/2;
	assert((x-1)*(x-1)<n&&n<(x+1)*(x+1));
	return x;
}
template<class T>T isqrt(T n){
	T x=nsqrt(n);
	x-=x*x>n;
	assert(x*x<=n&&(x+1)*(x+1)>n);
	return x;
}
