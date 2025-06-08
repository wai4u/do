//https://atcoder.jp/contests/abc239/submissions/66447451
template<class T>
struct maxflow{
	struct edge{
		int to,rev;T c;
		edge(int to,int rev,T c):to(to),rev(rev),c(c){}
	};
	int n;
	vector<vector<edge>>g;
	vector<bool>vis;
	vector<int>d,que;
	maxflow(int n):n(n),g(n){}
	void add_edge(int u,int v,T c){
		g[u].emplace_back(v,g[v].size(),c);
		g[v].emplace_back(u,g[u].size()-1,0);
	}
	T dfs(int u,int t,T in){
		if(u==t)return in;
		if(vis[u])return 0;
		vis[u]=1;
		T out=0;
		for(auto&[v,rev,c]:g[u]){
			if(!in)break;
			if(d[v]<=d[u]||!c)continue;
			T f=dfs(v,t,min(c,in));
			c-=f;
			g[v][rev].c+=f;
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
				for(auto[v,_,c]:g[u])if(c&&d[v]<0){
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
	vector<bool>partition(){
		for(int i=0;i<n;i++)vis[i]=d[i]>-1;
		return vis;
	}
};
