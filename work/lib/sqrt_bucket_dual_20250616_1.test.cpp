#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"
#include"io_20250608_1.hpp"
#include"sqrt_bucket_dual_20250616_1.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	sqrt_bucket_dual<int>seg(n+1);
	while(q--){
		int t;
		cin>>t;
		if(t==0){
			int l,r,x;
			cin>>l>>r>>x;
			seg.add(l,r+1,x);
		}else{
			int i;
			cin>>i;
			cout<<seg[i]<<'\n';
		}
	}
}
