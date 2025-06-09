//https://judge.yosupo.jp/submission/291834
struct union_find{
	vector<int>d;
	union_find(){}
	union_find(int n){init(n);}
	void init(int n){d.assign(n,-1);}
	int root(int u){
		while(d[u]>=0){
			if(d[d[u]]<0)return d[u];
			u=d[u]=d[d[u]];
		}
		return u;
	}
	bool same(int u,int v){return root(u)==root(v);}
	int size(int u){return -d[root(u)];}
	bool unite(int u,int v){
		u=root(u),v=root(v);
		if(u==v)return 0;
		if(d[u]<d[v])swap(u,v);
		d[v]+=d[u],d[u]=v;
		return 1;
	}
};
