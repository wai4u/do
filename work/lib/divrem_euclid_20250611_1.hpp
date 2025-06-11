//https://atcoder.jp/contests/abc105/submissions/66654640
#pragma once
template<class T,class U>
auto divrem_euclid(T a,U b){
	using X=common_type_t<T,U>;
	X q=a/b,r=a-q*b;
	if(r<0){
		if(b<0)r-=b,q++;
		else r+=b,q--;
	}
	return make_pair(q,r);
}
