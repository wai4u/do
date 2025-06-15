//digit by digit
//https://en.wikipedia.org/wiki/Integer_square_root#Digit-by-digit_algorithm
//https://atcoder.jp/contests/abc400/submissions/66803287
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x=isqrt(n>>2)<<1|1;
	return x-(x*x>n);
}
