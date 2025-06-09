//https://atcoder.jp/contests/practice2/submissions/66618324
struct union_find{
	vector<int>r;
	union_find(int n):r(n){for(int i=0;i<n;i++)r[i]=i;}
	int root(int u){return r[u]==u?u:root(r[u]);}
	bool same(int u,int v){return root(u)==root(v);}
	int unite(int u,int v){return r[root(u)]=root(v);}//u->v
};
