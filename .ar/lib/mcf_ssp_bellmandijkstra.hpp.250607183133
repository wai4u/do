//https://atcoder.jp/contests/abc407/submissions/66499853
//SSP(successive shortest path)
//s->t flow
//日本語の記事ではprimal-dualとか呼ばれていることもあるが、
//最小費用流自体がprimal-dual的見方ができるのであってprimal-dualはアルゴリズムの名称ではない。
//repeat dijkstra O(NM+FMlogM)
//initial bellman + repeat dijkstra O(NM+FMlogM) (負辺あり)
template<class T,class W>
struct MCF{
	struct edge{int to,rev;T c;W w;};
	int n;
	vector<vector<edge>>g;
	bool neg;
	vector<W>h,d;
	vector<pair<int,int>>p;
	static constexpr W inf=numeric_limits<W>::max();
	static constexpr T inflow=numeric_limits<T>::max();
	MCF(int n,bool neg=0):n(n),g(n),neg(neg){}
	void add_edge(int u,int v,T c,W w){
		assert(0<=u&&u<n&&0<=v&&v<n);
		assert(c>=0);
		if(!neg)assert(w>=0);
		g[u].push_back({v,(int)g[v].size(),c,w});
		g[v].push_back({u,(int)g[u].size()-1,0,-w});
	}
	void init_potential(){
		for(int t=1;t<=n;t++){
			bool upd=0;
			for(int u=0;u<n;u++)if(h[u]<inf){
				for(auto&e:g[u])if(e.c&&h[u]+e.w<h[e.to]){
					h[e.to]=h[u]+e.w;
					upd=1;
				}
			}
			if(!upd)break;
			assert(t<n);
		}
	}
	vector<pair<T,W>>slope(int s,int t,T in=inflow){
		if(neg){
			h.assign(n,inf),h[s]=0;
			init_potential();
		}else h.assign(n,0);
		T out=0;
		W cost=0;
		p.resize(n);
		using P=pair<W,int>;
		priority_queue<P,vector<P>,greater<P>>que;
		vector<pair<T,W>>res{{0,0}};
		while(in>0){
			d.assign(n,inf),d[s]=0;
			que.push(make_pair(0,s));
			while(que.size()){
				auto[du,u]=que.top();que.pop();
				if(du>d[u])continue;
				int i=-1;
				for(auto&e:g[u]){
					i++;
					if(!e.c)continue;
					int v=e.to;
					W dv=du+e.w+h[u]-h[v];
					if(dv<d[v]){
						d[v]=dv;
						que.push(make_pair(dv,v));
						p[v]=make_pair(u,i);
					}
				}
			}
			if(d[t]==inf)break;
			for(int i=0;i<n;i++)if(d[i]<inf)h[i]+=d[i];
			//for(int i=0;i<n;i++)h[i]+=d[i];//infになったら二度と使わないからoverflowしても良い
			T f=in;
			int u=t;
			while(u!=s){
				auto[v,i]=p[u];
				f=min(f,g[v][i].c);
				u=v;
			}
			u=t;
			while(u!=s){
				auto[v,i]=p[u];
				auto&e=g[v][i];
				e.c-=f;
				g[u][e.rev].c+=f;
				u=v;
			}
			in-=f;
			out+=f;
			cost+=f*h[t];
			if(!d[t]&&res.size()>1)res.pop_back();
			res.push_back({out,cost});
		}
		return res;
	}
	pair<T,W>maxflow_mincost(int s,int t,T in=inflow){return slope(s,t,in).back();}
	pair<T,W>mincost_flow(int s,int t,T in=inflow,bool mn=0){
		auto res=slope(s,t,in);
		for(int i=0;i<res.size()-1;i++){
			if(res[i+1].second-res[i].second>=0+!mn)return res[i];
		}
		return res.back();
	}
	pair<T,W>mincost_maxflow(int s,int t,T in=inflow){return mincost_flow(s,t,in,0);}
	pair<T,W>mincost_minflow(int s,int t,T in=inflow){return mincost_flow(s,t,in,1);}
};
