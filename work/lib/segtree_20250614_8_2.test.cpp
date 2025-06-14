#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"
#include"io_20250608_1.hpp"
#include"segtree_20250614_8.hpp"
int op(int x,int y){return x+y;}
int e(){return 0;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree<int,op,e>seg(n+1);
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0)seg.set(i,seg[i]+j);
		else cout<<seg.prod(i,j+1)<<'\n';
	}
}
