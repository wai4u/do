//newton's method
//O(loglogN)
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method
//https://atcoder.jp/contests/abc400/submissions/66801321
//f(x)=x^2-n,f'(x)=2x
//nx=x-f(x)/f'(x)=(x^2+n)/2x=(x+n/x)/2
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x=n>>1,nx=x+n/x>>1;
	while(nx<x)x=nx,nx=x+n/x>>1;
	return x-(x*x>n);
}
