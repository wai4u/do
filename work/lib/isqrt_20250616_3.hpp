//newton * 指数digit by digit
//https://atcoder.jp/contests/abc400/submissions/66820220
template<class T>int bitlen(T n){return n?64-__builtin_clzll(n):0;}
template<class T>T nsqrt(T n){
	if(n<4)return 1;
	int k=(bitlen(n)+1)/4;
	T x=nsqrt(n>>2*k)<<k;
	return(x+n/x)/2;
}
template<class T>T isqrt(T n){T x=nsqrt(n);return x-(x*x>n);}
