//https://atcoder.jp/contests/abl/submissions/66614684
struct union_find{
	vector<int>d;
	union_find(int n):d(n,-1){}
	int root(int u){return d[u]<0?u:d[u]=root(d[u]);}
	int size(int u){return -d[root(u)];}
	bool same(int u,int v){return root(u)==root(v);}
	bool unite(int u,int v){
		u=root(u),v=root(v);
		if(u==v)return 0;
		if(d[u]>d[v])swap(u,v);
		d[u]+=d[v];
		d[v]=u;
		return 1;
	}
};
