#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"
#include"io_20250608_1.hpp"
#include"segtree_lazy_20250612_1.hpp"
int op(int x,int y){return min(x,y);}
int e(){return (1l<<31)-1;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_lazy<int,op,e>seg(n);
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
