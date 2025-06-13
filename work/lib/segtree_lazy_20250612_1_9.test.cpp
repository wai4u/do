#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"
#include"io_20250608_1.hpp"
#include"segtree_lazy_20250612_1.hpp"
struct X{long s=0,c=0;};
X op(X x,X y){return X{x.s+y.s,x.c+y.c};}
X e(){return X{};}
int id(){return 1e9;}
X mapping(int f,X x){return f==id()?x:X{x.c*f,x.c};}
int composition(int f,int g){return f==id()?g:f;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_lazy<X,op,e,int,mapping,composition,id>seg(n+1,[&](int i){return X{0,1};});
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0){
			int x;
			cin>>x;
			seg.apply(l,r+1,x);
		}else{
			cout<<seg.prod(l,r+1).s<<'\n';
		}
	}
}
