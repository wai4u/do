//digit by digit
//recursive 
//https://en.wikipedia.org/wiki/Integer_square_root
//https://en.wikipedia.org/wiki/Integer_square_root#Digit-by-digit_algorithm
//https://atcoder.jp/contests/abc400/submissions/66799767
int isqrt(long x){
	if(x<2)return x;
	long y=isqrt(x>>2)<<1;
	y++;
	if(y*y>x)y--;
	return y;
}
