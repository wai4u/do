template<class T>
struct maxflow{
	int n;
	vector<vector<T>>c;
	vector<bool>vis;
	vector<int>d,que;
	maxflow(int n):n(n),c(n,vector<T>(n,0)){}
	void add_edge(int u,int v,T w){c[u][v]+=w;}
	T dfs(int u,int t,T in){
		if(u==t)return in;
		if(vis[u])return 0;
		vis[u]=1;
		T out=0;
		for(int v=0;v<n;v++){
			if(!in)break;
			if(d[v]<=d[u]||!c[u][v])continue;
			T f=dfs(v,t,min(c[u][v],in));
			c[u][v]-=f;
			c[v][u]+=f;
			in-=f;
			out+=f;
		}
		return out;
	};
	T flow(int s,int t){
		T ans=0,inf=numeric_limits<T>::max();
		while(1){
			vis.assign(n,0);
			d.assign(n,-1),que.clear();
			d[s]=0,que.push_back(s);
			for(int i=0;i<que.size();i++){
				int u=que[i];
				for(int v=0;v<n;v++)if(c[u][v]&&d[v]<0){
					d[v]=d[u]+1;
					que.push_back(v);
				}
			}
			if(d[t]<0)break;
			ans+=dfs(s,t,inf);
		}
		return ans;
	}
	//call after flow(s,t).1->0 edge is in a cut
	//https://atcoder.jp/contests/abc239/submissions/66446109
	vector<bool>partition(){
		for(int i=0;i<n;i++)vis[i]=d[i]>-1;
		return vis;
	}
};
