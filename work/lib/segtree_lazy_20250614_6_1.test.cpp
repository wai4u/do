#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include"io_20250608_1.hpp"
#include"segtree_lazy_20250614_6.hpp"
int op(int x,int y){return x==-1?y:x;}
int e(){return -1;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_lazy<int,op,e>seg(n+1);
	for(int i=0;i<=n;i++)seg.set(i,(1l<<31)-1);
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
