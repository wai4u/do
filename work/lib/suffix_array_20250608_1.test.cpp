#include"io.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include"suffix_array_20250608_1.hpp"
int main(){
	string s;
	cin>>s;
	cout<<suffix_array(s)<<'\n';
}
