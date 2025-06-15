//binary search
//任意整数型
//overflowを気にするが上限の見積もりができない場合、
//掛け算ではなく割り算で比較することでoverflowを避ける。
//https://atcoder.jp/contests/abc400/submissions/66799873
template<class T>
T isqrt(T x){
	T l=0,r=x+1;
	while(r-l>1){T y=l+r>>1;(y<=x/y?l:r)=y;}
	return l;
}
