#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"
#include"io_20250608_1.hpp"
#include"segtree_lazy_20250614_5.hpp"
int op(int x,int y){return min(x,y);}
int e(){return(1l<<31)-1;}
int mapping(int f,int x){return f==-1?x:f;}
int composition(int f,int g){return f==-1?g:f;}
int id(){return -1;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_lazy<int,op,e,int,mapping,composition,id>seg(n+1);
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0){
			int x;
			cin>>x;
			seg.apply(l,r+1,x);
		}else{
			cout<<seg.prod(l,r+1)<<'\n';
		}
	}
}
