#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"
#include"io_20250608_1.hpp"
#include"segtree_dual_20250613_1.hpp"
struct X{int id=-1,val=(1l<<31)-1;};
X op(X x,X y){return x.id>=y.id?x:y;}
X e(){return X{};}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_dual<X,op,e>seg(n+1);
	int id=0;
	while(q--){
		int t;
		cin>>t;
		if(t==0){
			int l,r,x;
			cin>>l>>r>>x;
			seg.apply(l,r+1,X{id++,x});
		}else{
			int i;
			cin>>i;
			cout<<seg[i].val<<'\n';
		}
	}
}
