//linear search
//https://en.wikipedia.org/wiki/Integer_square_root#Linear_search_using_addition
//https://atcoder.jp/contests/abc400/submissions/66803235
template<class T>
T isqrt(T n){
	assert(n>=0);
	//sq=x^2,d=2x+1
	T sq=1,d=3;
	while(sq<=n)sq+=d,d+=2;
	return d/2-1;
}
