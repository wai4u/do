//newton's method
//O(loglogN)
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method
//https://atcoder.jp/contests/abc400/submissions/66801279
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T r=n>>1,l=r+n/r>>1;
	while(l<r)r=l,l=r+n/r>>1;
	assert(r*r<=n&&(r+1)*(r+1)>n);
	return r;
}
