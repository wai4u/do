#include"io.hpp"
#include"manacher_20250608_1.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
int main(){
	string s;
	cin>>s;
	cout<<manacher(s,1)<<'\n';
}
