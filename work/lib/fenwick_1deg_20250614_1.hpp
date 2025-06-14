//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
#include"fenwick_20250609_1.hpp"
template<class T>
struct fenwick_1deg{
	fenwick<T>d0,d1;
	fenwick_1deg(int n):d0(n),d1(n){}
	void add(int i,T x){d0.add(i,(1-i)*x),d1.add(i,x);}
	T operator[](int i){return d0[i]+d1[i]*i;}
};
