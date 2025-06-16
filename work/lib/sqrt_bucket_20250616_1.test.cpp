#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include"io_20250608_1.hpp"
#include"sqrt_bucket_20250616_1.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	sqrt_bucket<int,(1l<<31)-1>seg(n);
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0){
			seg.set(i,j);
		}else{
			cout<<seg.prod(i,j+1)<<'\n';
		}
	}
}
