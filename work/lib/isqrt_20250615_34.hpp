//digit by digit
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Digit-by-digit_algorithm
//https://en.wikipedia.org/wiki/Square_root_algorithms#Digit-by-digit_calculation
//https://atcoder.jp/contests/abc400/submissions/66805104
template<class T>
T isqrt(T n){
	int k=0;while(n>>k)k+=2;
	T x=0;
	while(k){
		k-=2;
		x<<=1;
		x+=(x+1)*(x+1)<=n>>k;
	}
	return x;
}
