//binary search
//https://atcoder.jp/contests/abc400/submissions/66799633
int isqrt(long n){
	int ok=0,ng=1<<30;
	while(ng-ok>1){
		int x=ok+ng>>1;
		((long)x*x<=n?ok:ng)=x;
	}
	return ok;
}
