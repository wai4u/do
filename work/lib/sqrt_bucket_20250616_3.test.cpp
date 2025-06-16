#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include"io_20250608_1.hpp"
#include"sqrt_bucket_20250616_3.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	sqrt_bucket<int>seg(n);
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		i--;
		if(t==0)seg.add(i,j);
		else cout<<seg.sum(i,j)<<'\n';
	}
}
