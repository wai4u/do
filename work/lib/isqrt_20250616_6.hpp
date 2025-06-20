//https://github.com/mdickinson/snippets/blob/main/proofs/isqrt/src/isqrt.lean
//をベースに多倍長に最適化したものらしい。pythonのmath.isqrtの実装と等価
//https://github.com/python/cpython/blob/main/Modules/mathmodule.c
//https://stackoverflow.com/questions/78063269/time-complexity-of-python-3-8s-integer-square-root-math-isqrt-function
//https://atcoder.jp/contests/abc400/submissions/66822087
template<class T>int bitlen(T n){return n?64-__builtin_clzll(n):0;}
template<class T>T isqrt(T n){
	int c=(bitlen(n)-1)/2;
	T x=1;
	for(int s=bitlen(c);s--;){
		int d=c>>s,e=c>>s+1;
		x=(x<<d-e-1)+(n>>c+c-e-d+1)/x;
	}
	x-=x*x>n;
	assert(x*x<=n&&(x+1)*(x+1)>n);
	return x;
}
