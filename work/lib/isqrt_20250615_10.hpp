//newton's method with approximation
//cpython implementation like
//O(loglogN)
//iterative
//https://github.com/python/cpython/blob/main/Modules/mathmodule.c 
//https://github.com/mdickinson/snippets/blob/main/proofs/isqrt/src/isqrt.lean
//https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method
//https://en.wikipedia.org/wiki/Square_root_algorithms#Heron's_method
//https://stackoverflow.com/questions/78063269/time-complexity-of-python-3-8s-integer-square-root-math-isqrt-function
//https://teratail.com/questions/322048
//https://atcoder.jp/contests/abc400/submissions/66801129
int bitlen(long x){return x?64-__builtin_clzll(x):0;}
int isqrt(long n){
	assert(n>=0);
	if(!n)return 0;
	int c=bitlen(n)-1>>1,d=0,e;long a=1;
	for(int s=bitlen(c);s--;){
		e=d,d=c>>s;
		a=(a<<d-e-1)+(n>>2*c-e-d+1)/a;
	}
	return a-(a*a>n);
}
