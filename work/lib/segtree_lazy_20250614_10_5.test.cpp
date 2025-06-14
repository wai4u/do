#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include"io_20250608_1.hpp"
#include"segtree_lazy_20250614_10.hpp"
#include<atcoder/modint>
using mint=atcoder::modint998244353;
struct X{mint s=0;int c=0;};
X e(){return X{};}
X op(X x,X y){return X{x.s+y.s,x.c+y.c};}
struct F{mint a=1,b=0;};
X mapping(F f,X x){return X{x.s*f.a+x.c*f.b,x.c};}
F composition(F f,F g){return F{f.a*g.a,f.b+f.a*g.b};}
F id(){return F{};}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_lazy<X,op,e,F,mapping,composition,id>seg(n,[&](int i){
		int a;
		cin>>a;
		return X{a,1};
	});
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0){
			int a,b;
			cin>>a>>b;
			seg.apply(l,r,F{a,b});
		}else{
			cout<<seg.prod(l,r).s.val()<<'\n';
		}
	}
}
