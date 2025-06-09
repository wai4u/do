struct union_find{
	vector<int>d;
	union_find(int n):d(n,-1){}
	int root(int u){return d[u]<0?u:d[u]=root(d[u]);}
	int size(int u){return -d[root(u)];}
	void unite(int u,int v){
		u=root(u),v=root(v);
		if(u==v)return;
		if(d[u]>d[v])swap(u,v);
		d[u]+=d[v];
		d[v]=u;
	}
};
