//https://judge.yosupo.jp/submission/291835
struct union_find{
	vector<int>r,s;
	union_find(){}
	union_find(int n){init(n);}
	void init(int n){
		r.resize(n);
		s.assign(n,-1);
		for(int i=0;i<n;i++)r[i]=i;
	}
	int root(int u){
		while(u!=r[u])u=r[u]=r[r[u]];
		return u;
	}
	bool same(int u,int v){return root(u)==root(v);}
	int size(int u){return s[root(u)];}
	bool unite(int u,int v){
		u=root(u),v=root(v);
		if(u==v)return 0;
		if(s[u]>s[v])swap(u,v);
		s[v]+=s[u],r[u]=v;
		return 1;
	}
};
