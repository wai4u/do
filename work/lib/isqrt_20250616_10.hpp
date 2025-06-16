//newton
//初期値最適化
//初期値はx>=sqrt(n)であれば良い。
//2の冪乗でなるべく条件を満たす小さいものを選びたい。
//2^k>=sqrt(n) -> 2^2k>=n
//2^msb(n)<=n<2^(msb(n)+1)=2^bitlen(n) なので、2k>=bitlen(n)であれば良い。
//k=[(bitlen(n-1)+1)/2]とすると
//n=2^tで表されてる時のみbitlen(n-1)<bitlen(n)となるが、bitlen(n)が偶数の時は2kは変わらず。
//奇数の時は2kは2小さくなるが。元々2k=bitlen(n)+1だったから2^(bitlen(n)-1)=2^msb(n)=n>=nなのでok
//https://atcoder.jp/contests/abc400/submissions/66822586
template<class T>int msb(T x){return x?63-__builtin_clzll(x):-1;}
template<class T>int bitlen(T x){return msb(x)+1;}
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x,y=T(1)<<(bitlen(n-1)+1)/2;
	assert(y*y>=n);
	do{x=y,y=x+n/x>>1;}while(y<x);
	return x;
}
