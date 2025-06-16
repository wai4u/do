#include<bits/stdc++.h>
using namespace std;
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<'\n';
}
