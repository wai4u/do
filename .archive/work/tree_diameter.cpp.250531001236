#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<vector<pair<int,int>>>g(n);
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	auto dist=[&](int s){
		vector<long>d(n);
		vector<int>p(n,-1);
		queue<int>que;
		que.push(s);
		while(que.size()){
			int u=que.front();que.pop();
			for(auto[v,w]:g[u])if(v!=p[u]){
				p[v]=u;
				d[v]=d[u]+w;
				que.push(v);
			}
		}
		return make_pair(d,p);
	};
	auto[d0,p0]=dist(0);
	int u=max_element(d0.begin(),d0.end())-d0.begin();
	auto[du,pu]=dist(u);
	int v=max_element(du.begin(),du.end())-du.begin();
	long s=du[v];
	int k=1;
	vector<int>path{v};
	while(v!=u){
		v=pu[v];
		k++;
		path.push_back(v);
	}
	cout<<s<<' '<<k<<'\n';
	for(int x:path)cout<<x<<' ';
	cout<<'\n';
}
