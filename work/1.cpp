#include<bits/stdc++.h>
using namespace std;
#include"isqrt.hpp"
int main(){
	long n;
	cin>>n;
	cout<<isqrt(n/2)+isqrt(n/4)<<'\n';
}
