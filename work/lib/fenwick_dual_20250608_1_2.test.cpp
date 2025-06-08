#include"io_20250608_1.hpp"
#include"fenwick_dual_20250608_1.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<int>a(n);
	while(q--){
		int t;
		cin>>t;
		if(t==0){
			int l,r,x;
			cin>>l>>r>>x;
			a.add(l-1,r,x);
		}else{
			int i;
			cin>>i;
			cout<<a[i-1]<<'\n';
		}
	}
}
