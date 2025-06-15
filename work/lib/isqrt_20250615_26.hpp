//digit by digit
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Digit-by-digit_algorithm
//https://atcoder.jp/contests/abc400/submissions/66803352
template<class T>
T isqrt(T n){
	assert(n>=0);
	int k=0;while(n>>k)k+=2;
	T x=0;
	while(k){
		k-=2;
		x=x<<1|1;
		x-=x*x>n>>k;
	}
	return x;
}
