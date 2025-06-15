//stdで近似して調整
//https://atcoder.jp/contests/abc400/submissions/66799692
int isqrt(long x){
	long y=sqrt(x);
	while(y*y<=x)y++;
	while(y*y>x)y--;
	return y;
}
