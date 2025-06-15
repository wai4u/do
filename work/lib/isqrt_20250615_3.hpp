//binary search
//https://atcoder.jp/contests/abc400/submissions/66799587
ulong isqrt(ulong n){
	ulong ok=0,ng=1ul<<32;
	while(ng-ok>1){
		ulong x=ok+ng>>1;
		(x*x<=n?ok:ng)=x;
	}
	return ok;
}
long isqrt(long n){return isqrt(ulong(n));}
