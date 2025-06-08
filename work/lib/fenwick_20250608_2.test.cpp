#include"io_20250608_1.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"fenwick_20250608_2.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<long>s(n,[&](int i){
		int x;
		cin>>x;
		return x;
	});
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0)s.add(i,j);
		else cout<<s[j-1]-s[i-1]<<'\n';
	}
}
