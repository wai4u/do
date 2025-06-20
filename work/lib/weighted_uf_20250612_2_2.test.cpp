#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"
#include"io_20250608_1.hpp"
#include"weighted_uf_20250612_2.hpp"
#include<atcoder/modint>
using mint=atcoder::modint998244353;
mint op(mint x,mint y){return x+y;}
mint e(){return 0;}
mint inv(mint x){return -x;}
int main(){
	int n,q;
	cin>>n>>q;
	weighted_uf<mint,op,e,inv>uf(n);
	while(q--){
		int t,u,v;
		cin>>t>>u>>v;
		if(t==0){
			int w;
			cin>>w;
			if(uf.valid(v,u,w)){
				cout<<1<<'\n';
				uf.unite(v,u,w);
			}else{
				cout<<0<<'\n';
			}
		}else{
			if(uf.same(u,v)){
				cout<<uf.diff(v,u).val()<<'\n';
			}else cout<<-1<<'\n';
		}
	}
}
