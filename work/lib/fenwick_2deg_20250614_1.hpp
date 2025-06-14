//https://atcoder.jp/contests/abc256/submissions/66716265
#include"fenwick_20250609_1.hpp"
template<class T>
struct fenwick_2deg{
	fenwick<T>d0,d1,d2;
	fenwick_2deg(int n):d0(n),d1(n),d2(n){}
	//[j>=i]+=sum_{k=i^j}(k-i+1)x
	void add(int i,T x){
		d0.add(i,x*(-i+1)*(-i+2));
		d1.add(i,x*(-2*i+3));
		d2.add(i,x);
	}
	T operator[](int i){return (d0[i]+d1[i]*i+d2[i]*i*i)/2;}
};
