#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"io.hpp"
#include"fenwick_primal_20250608_1.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<long>s(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.add(i,x);
	}
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0)s.add(i,j);
		else cout<<s.sum(i,j)<<'\n';
	}
}
