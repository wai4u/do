#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential_non_commutative_group"
#include"io_20250608_1.hpp"
#include"weighted_uf_20250612_2.hpp"
#include<atcoder/modint>
using mint=atcoder::modint998244353;
using T=array<array<mint,2>,2>;
T op(T a,T b){
	T c;
	for(int i=0;i<2;i++)for(int k=0;k<2;k++)for(int j=0;j<2;j++){
		c[i][j]+=a[i][k]*b[k][j];
	}
	return c;
}
T e(){return{1,0,0,1};}
T inv(T a){return{a[1][1],-a[0][1],-a[1][0],a[0][0]};};
int main(){
	int n,q;
	cin>>n>>q;
	weighted_uf<T,op,e,inv>uf(n);
	while(q--){
		int t,u,v;
		cin>>t>>u>>v;
		if(t==0){
			T w;
			for(int i=0;i<2;i++)for(int j=0;j<2;j++){
				int x;
				cin>>x;
				w[i][j]=x;
			}
			if(uf.valid(v,u,w)){
				cout<<1<<'\n';
				uf.unite(v,u,w);
			}else{
				cout<<0<<'\n';
			}
		}else{
			if(uf.same(u,v)){
				T w=uf.diff(v,u);
				for(int i=0;i<2;i++)for(int j=0;j<2;j++){
					cout<<w[i][j].val()<<' ';
				}
				cout<<'\n';
			}else cout<<-1<<'\n';
		}
	}
}
