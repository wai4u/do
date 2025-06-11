//https://atcoder.jp/contests/abc105/submissions/66654933
#include"divrem_floor_20250611_1.hpp"
template<class T,class U>
auto baseconv(T n,U b,bool desc=0){
	assert(abs(b)>1);
	vector<common_type_t<T,U>>res;
	U r;
	do{
		tie(n,r)=divrem_floor(n,b);
		if(r<0)r-=b,n++;
		res.push_back(r);
	}while(n);
	if(desc)reverse(res.begin(),res.end());
	return res;
}
