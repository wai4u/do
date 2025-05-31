#include<bits/stdc++.h>
using namespace std;
#include<atcoder/dsu>
int main(){
	int n,m;
	cin>>n>>m;
	vector<tuple<int,int,int>>edges(m);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i]=make_tuple(u-1,v-1,w);
	}
	int now=0;
	for(int k=30;k--;){
		int x=now|(1<<k)-1;
		atcoder::dsu uf(n);
		for(auto[u,v,w]:edges){
			if((w|x)!=x)continue;
			uf.merge(u,v);
		}
		if(!uf.same(0,n-1))now|=1<<k;
	}
	cout<<now<<'\n';
}
