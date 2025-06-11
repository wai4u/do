#pragma once
//https://atcoder.jp/contests/abc105/submissions/66654933
template<class T,class U>
auto divrem_floor(T a,U b){
	using X=common_type_t<T,U>;
	X q=a/b,r=a-q*b;
	if(r&&(a^b)<0)r+=b,q--;
	return make_pair(q,r);
}
template<class T,class U>
auto divmod(T a,U b){return divrem_floor(a,b);}
