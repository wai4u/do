struct bimatch{
	int n,m=0;
	vector<vector<int>>g;
	vector<int>to,d;
	vector<bool>vis;
	bimatch(int n):n(n),g(n){}
	bimatch(int n,int m):n(n),m(m),g(n){}
	void add_edge(int u,int v){
		if(m)g[u].push_back(n+v);
		else{
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	bool dfs(int u){
		if(vis[u])return 0;
		vis[u]=1;
		for(int v:g[u]){
			int&w=to[v];
			if(w<0||d[w]>d[u]&&dfs(w)){to[w=u]=v;return 1;}
		}
		return 0;
	}
	int count(){
		int cnt=0;
		to.assign(n+m,-1);
		bool upd=1;
		vector<int>que;
		while(upd){
			upd=0,vis.assign(n,0);
			d.assign(n,-1),que.clear();
			for(int i=0;i<n;i++)if(to[i]<0)d[i]=0,que.push_back(i);
			for(int i=0;i<(int)que.size();i++){
				int u=que[i];
				for(int v:g[u]){
					int w=to[v];
					if(w>-1&&d[w]<0)d[w]=d[u]+1,que.push_back(w);
				}
			}
			for(int i=0;i<n;i++)if(to[i]<0&&dfs(i))cnt++,upd=1;
		}
		return cnt;
	}
	int right(int u){assert(m&&u<n);return to[u]-n;}
	int left(int v){assert(v<m);return to[v+n];}
};
