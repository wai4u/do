//newton * 指数digit by digit
//https://stackoverflow.com/questions/78063269/time-complexity-of-python-3-8s-integer-square-root-math-isqrt-function
//near sqrt
//(x-1)^2<n<(x+1)^nなるxを返す。
//O(loglogN)
//digit by digitでは線形でbitlenを2ずつ短くした問題を解いていったが、
//もっと大雑把にbitlenをおよそ半分にした問題を解いてnewton法1回で精度を保証することでより高速。
//https://atcoder.jp/contests/abc400/submissions/66820052
template<class T>int bitlen(T n){return n?64-__builtin_clzll(n):0;}
template<class T>T nsqrt(T n){
	if(n<4)return 1;
	//[n/4^k]での近似解を得て、2^k倍することでnに対する近似解を得る
	//>>k+kすることを考えると、k=bitlen(n)/4程度にするとbitlen(n)/2程度シフトした問題を解くことになる。
	//すなわちbitlenが半分程度の問題を解くことになる。再帰ステップはloglogN回。
	int k=bitlen(n)+1>>2;
	T x=nsqrt(n>>k+k)<<k;//近似解を初期値とする。まだ戻り値条件を満たさないかもしれない。
	return x+n/x>>1;//高々1回のnewton法で条件を満たすとこまで収束する。
	//収束範囲の証明は難しいので割愛。
}
//x*x<=nのとき(x+1)(x+1)>nなのでxでok
//x*x>nのとき(x-1)(x-1)<nなのでx-1でok
template<class T>T isqrt(T n){T x=nsqrt(n);return x-(x*x>n);}
