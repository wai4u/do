//non commutative group
//from root & right operation
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
//https://judge.yosupo.jp/submission/292501
//https://judge.yosupo.jp/submission/292505
template<class T,T(*op)(T,T),T(*e)(),T(*inv)(T)>
struct weighted_uf{
	int n=0;
	vector<int>d;
	vector<T>p;
	weighted_uf(){}
	weighted_uf(int n){init(n);}
	void init(int n){
		this->n=n;
		d.assign(n,-1);
		p.assign(n,e());
	}
	int root(int u){
		int v=d[u];
		if(v<0)return u;
		d[u]=root(v);
		p[u]=op(p[v],p[u]);
		return d[u];
	}
	bool same(int u,int v){return root(u)==root(v);}
	int size(){return n;}
	int size(int u){return -d[root(u)];}
	T diff(int u,int v){
		assert(same(u,v));
		return op(inv(p[u]),p[v]);
	}
	bool valid(int u,int v,T w){
		return !same(u,v)||diff(u,v)==w;
	}
	bool unite(int u,int v,T w){
		assert(valid(u,v,w));
		if(same(u,v))return 0;
		w=op(op(p[u],w),inv(p[v]));
		u=root(u),v=root(v);
		if(d[u]>d[v])swap(u,v),w=inv(w);
		d[u]+=d[v];
		d[v]=u;
		p[v]=w;
		return 1;
	}
};
