//newton's method
//初期値をより近似
//https://atcoder.jp/contests/abc400/submissions/66803144
template<class T>
int msb(T x){return x?63-__builtin_clzll(x):-1;}
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x,nx=T(1)<<msb(n)/2+1;
	do{x=nx,nx=x+n/x>>1;}while(nx<x);
	return x;
}
