//愚直
//https://atcoder.jp/contests/abc400/submissions/66799513
long isqrt(long n){
	long x=0;
	while(x*x<=n)++x;
	return x-1;
}
