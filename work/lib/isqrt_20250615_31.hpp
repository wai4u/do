//linear search,掛け算を使わない
//平方数は2k+1の和で表せる
//https://atcoder.jp/contests/abc400/submissions/66803760
template<class T>
T isqrt(T n){
	T d=1;
	while(n>=d)n-=d,d+=2;
	return d/2;
}
