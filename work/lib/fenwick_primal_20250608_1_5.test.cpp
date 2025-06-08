#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"io_20250608_1.hpp"
#include"fenwick_primal_20250608_1.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	vector<long>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	fenwick s(a);
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0)s.add(i,j);
		else cout<<s.sum(i,j)<<'\n';
	}
}
