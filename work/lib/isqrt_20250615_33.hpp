//digit by digit
//https://en.wikipedia.org/wiki/Integer_square_root#Digit-by-digit_algorithm
//https://en.wikipedia.org/wiki/Square_root_algorithms#Digit-by-digit_calculation
//https://atcoder.jp/contests/abc400/submissions/66804012
//n=4k+r (0<=r<4)とおく
//[n/4]=kで
//sqrt(k)=a+0.bとすると
//[sqrt(k)]*2=2a=xとなる
//答えはxかx+1であることを示す。
//a<=sqrt(k)<a+1 より
//x^2=4a^2<=4a^2+r<=4k+r=n -> x<=isqrt(n)
//n=4k+r<4(a^2+2a+1)+r=x^2+4a+4+r=(x+2)^2+r
//isqrt(n)<[sqrt((x+2)^2+r)] だが、x>=0より右辺がx+3以上になるためにはr>=5が必要。
//しかしr<4であり明らかにx+2以上のため右辺はx+2となり
//isqrt(n)<x+2となる
//よってx<=isqrt(n)<x+2
template<class T>
T isqrt(T n){
	if(n<2)return n;
	T x=isqrt(n/4)*2|1;
	return x-(x*x>n);
}
