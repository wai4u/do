//newton's method
//O(loglogN)
//iterative
//https://en.wikipedia.org/wiki/Integer_square_root#Algorithm_using_Newton's_method
//https://atcoder.jp/contests/abc400/submissions/66801253
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T r=n>>1,l=r+n/r>>1;
	while(l<r)r=l,l=r+n/r>>1;
	while(l*l<=n)l++;
	l--;
	assert(l*l<=n);
	return l;
}
