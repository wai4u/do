//stdで近似して調整
//https://atcoder.jp/contests/abc400/submissions/66799710
int isqrt(long x){
	long y=sqrt(x);
	while((y+1)*(y+1)<=x)y++;
	while(y*y>x)y--;
	return y;
}
