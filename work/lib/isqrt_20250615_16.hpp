//newton's method
//O(loglogN)
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method
//[(x+n/x)/2]=[(x+[n/x])/2]を使っている
//x+n/x=1.abc...か0.abc... mod 2なので切り捨てて1か0 mod 2となっても結果は変わらない。
//https://atcoder.jp/contests/abc400/submissions/66801935
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x=n>>1,nx=x+n/x>>1;
	while(nx<x)x=nx,nx=x+n/x>>1;
	return x-(x*x>n);
}
