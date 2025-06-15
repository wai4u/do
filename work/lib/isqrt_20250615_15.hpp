//newton's method
//O(loglogN)
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method
//[(x+n/x)/2]=[(x+[n/x])/2]を使っている
//x+n/x=1.abc...か0.abc... mod 2なので切り捨てて1か0 mod 2となっても結果は変わらない。
//https://atcoder.jp/contests/abc400/submissions/66801910
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x=n/2;//x0>=sqrt(n)をとる
	while(1){
		T y=(x+n/x)/2;
		//x>[sqrt(n)]の時,[n/x]<=[sqrt[n]]なので、y<x.
		if(x<=y)return x;
		x=y;
	}
}
