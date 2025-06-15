#include<bits/stdc++.h>
using namespace std;
//newton method
//https://atcoder.jp/contests/abc400/submissions/66803405
template<class T>
int bitlen(T x){return x?64-__builtin_clzll(x):0;}
template<class T>
T isqrt(T n){
	assert(n>=0);
	if(n<2)return n;
	T x,nx=T(1)<<(bitlen(n-1)+1)/2;
	assert(nx*nx>=n);
	do{x=nx,nx=x+n/x>>1;}while(nx<x);
	return x;
}
int main(){
	long n;
	cin>>n;
	cout<<isqrt(n/2)+isqrt(n/4)<<'\n';
}
