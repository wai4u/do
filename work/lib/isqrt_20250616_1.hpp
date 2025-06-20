//newton
//https://atcoder.jp/contests/abc400/submissions/66819275
//s=isqrt(n)=[sqrt(n)]とおく
//x>sのときx>sqrt(n)でn/x<sqrt(n)より[n/x]<=s
//であるから[(x+[n/x])/2]は少なくともxより1以上小さい。よっていずれx<=sに収束する。
//このときちょうどx=sであることを示す。
//x=s+1の時にy>=sになることを示れば、f(x)=x^2-nはx>sにおいて下に凸であるかことから傾きが単調増加なため
//x>s+1においてもy>=sとなる。
//つまりx1<x2ならばy1<=y2が成り立つため、x=s+1においてy>=sならばx'>xにおいてy'>=sが成り立つ。
//x=s+1のとき、s^2-1<=nよりs-1<=n/(s+1)だから[n/(s+1)]>=s-1
//よってs+1+[n/(s+1)]>=2sなのでy=[(x+[n/x])/2]>=s
//最初のx>sのときy<xと合わせると、s<=y<s+1となりy=s
template<class T>T isqrt(T n){
	if(n<2)return n;
	T x,y=n/2;
	do{x=y,y=x+n/x>>1;}while(y<x);
	return x;
}
