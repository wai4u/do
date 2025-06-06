//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
template<class T>
struct maxflow{
	int n;
	vector<vector<T>>c;
	vector<int>p,que;
	maxflow(int n):n(n),c(n,vector<T>(n,0)){}
	void add_edge(int u,int v,T w){c[u][v]+=w;}
	T flow(int s,int t){
		T ans=0;
		while(1){
			p.assign(n,-1);
			que.clear();
			que.push_back(s);
			for(int i=0;i<que.size();i++){
				int u=que[i];
				for(int v=0;v<n;v++)if(p[v]<0&&c[u][v]){
					p[v]=u;
					que.push_back(v);
				}
			}
			if(p[t]<0)break;
			int u=p[t];
			T f=c[u][t];
			while(u!=s){
				f=min(f,c[p[u]][u]);
				u=p[u];
			}
			u=t;
			while(u!=s){
				int v=p[u];
				c[v][u]-=f;
				c[u][v]+=f;
				u=v;
			}
			ans+=f;
		}
		return ans;
	}
};
