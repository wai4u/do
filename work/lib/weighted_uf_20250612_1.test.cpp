#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"
#include"io_20250608_1.hpp"
#include"weighted_uf_20250612_1.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	weighted_uf<int>uf(n);
	while(q--){
		int t,u,v;
		cin>>t>>u>>v;
		if(t==0){
			int w;
			cin>>w;
			uf.unite(u,v,w);
		}else{
			if(uf.same(u,v))cout<<uf.diff(u,v)<<'\n';
			else cout<<'?'<<'\n';
		}
	}
}
