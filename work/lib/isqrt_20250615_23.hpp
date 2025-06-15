//linear search
//https://en.wikipedia.org/wiki/Integer_square_root#Linear_search_using_addition
//https://atcoder.jp/contests/abc400/submissions/66803262
template<class T>
T isqrt(T n){
	assert(n>=0);
	//sq=(x+1)^2,d=2(x+1)+1
	T x=0,sq=1,d=3;
	while(sq<=n)sq+=d,d+=2,x++;
	return x;
}
