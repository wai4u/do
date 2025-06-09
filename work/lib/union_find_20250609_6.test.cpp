#include"io_20250608_1.hpp"
#include"union_find_20250609_6.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
int main(){
	int n,q;
	cin>>n>>q;
	union_find uf(n);
	while(q--){
		int t,u,v;
		cin>>t>>u>>v;
		if(t==0)uf.unite(u,v);
		else cout<<uf.same(u,v)<<'\n';
	}
}
