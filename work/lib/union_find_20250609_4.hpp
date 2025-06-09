//with init
//https://judge.yosupo.jp/submission/291833
struct union_find{
	vector<int>d;
	union_find(){}
	union_find(int n){init(n);}
	void init(int n){d.assign(n,-1);}
	int root(int u){return d[u]<0?u:d[u]=root(d[u]);}
	bool same(int u,int v){return root(u)==root(v);}
	bool unite(int u,int v){//u->v
		u=root(u),v=root(v);
		if(u==v)return 0;
		if(d[u]<d[v])swap(u,v);
		d[v]+=d[u],d[u]=v;
		return 1;
	}
};
