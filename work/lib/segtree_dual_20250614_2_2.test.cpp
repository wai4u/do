#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include"io_20250608_1.hpp"
#include"segtree_dual_20250614_2.hpp"
int op(int x,int y){return y==-1?x:y;}
int e(){return -1;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_dual<int,op,e>seg(n);
	for(int i=0;i<n;i++)seg[i]=(1l<<31)-1;
	while(q--){
		int t;
		cin>>t;
		if(t==0){
			int l,r,x;
			cin>>l>>r>>x;
			seg.apply(l,r+1,x);
		}else{
			int i;
			cin>>i;
			cout<<seg[i]<<'\n';
		}
	}
}
