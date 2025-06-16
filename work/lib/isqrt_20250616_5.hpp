//https://github.com/mdickinson/snippets/blob/main/proofs/isqrt/src/isqrt.lean
//https://atcoder.jp/contests/abc400/submissions/66821946
template<class T>int bitlen(T n){return n?64-__builtin_clzll(n):0;}
template<class T>T nsqrt(int c,T n){
	if(!c)return 1;
	int k=(c-1)/2;
	T x=nsqrt(c/2,n>>k+k+2);
	return(x<<k)+(n>>k+2)/x;
}
template<class T>T isqrt(T n){
	if(n==0)return 0;
	T x=nsqrt(bitlen(n)-1>>1,n);	
	x-=x*x>n;
	assert(x*x<=n&&(x+1)*(x+1)>n);
	return x;
}
