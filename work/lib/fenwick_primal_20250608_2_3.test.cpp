#include"io_20250608_1.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include"fenwick_primal_20250608_2.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<int>s(n);
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		i--;
		if(t==0)s.add(i,j);
		else cout<<s.sum(i,j)<<'\n';
	}
}
