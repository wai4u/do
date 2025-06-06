//https://atcoder.jp/contests/abc294/submissions/66429916
//euler tourをsegtreeに乗せてLCAと区間prod
//group (non commutative ok)
//HLDの方がinv不要でlazyにも対応でき優れているが、実装例として一応
#include<atcoder/segtree>
template<class T,T(*op)(T,T),T(*e)(),T(*inv)(T)>
struct edge_set_path_prod{
	int n,m=0;
	vector<vector<tuple<int,int,T>>>g;
	bool built=0;
	vector<int>L,R,ev;
	static int lop(int x,int y){return min(x,y);}
	static int loe(){return 1e9;}
	static T opr(T x,T y){return op(y,x);}
	atcoder::segtree<int,lop,loe>low;
	atcoder::segtree<T,op,e>sl;
	atcoder::segtree<T,opr,e>sr;
	edge_set_path_prod(int n):n(n),g(n),low(n+n-1),sl(n+n),sr(n+n),L(n),R(n),ev(n-1){}
	void add_edge(int u,int v,T w,int id=-1){
		if(id==-1)id=m;
		assert(0<=id&&id<n-1);
		g[u].emplace_back(id,v,w);
		g[v].emplace_back(id,u,w);
		m++;
	}
	void build(){
		assert(m==n-1);
		if(built)return;
		built=1;
		int k=0;
		dfs(0,-1,k);
		assert(k==n+n);
	}
	void dfs(int u,int p,int&k){
		low.set(k,k);
		L[u]=k++;
		for(auto[i,v,w]:g[u])if(v!=p){
			ev[i]=v;
			sl.set(k,w),sr.set(k,w);
			dfs(v,u,k);
			sl.set(k-1,inv(w)),sr.set(k-1,inv(w));
		}
		if(p>-1)low.set(k,L[p]);
		R[u]=k++;
	}
	void set(int i,T x){
		assert(0<=i&&i<m);
		build();
		int l=L[ev[i]],r=R[ev[i]];
		sl.set(l,x),sl.set(r,inv(x));
		sr.set(l,x),sr.set(r,inv(x));
	}
	T prod(int u,int v){
		//u->v
		assert(0<=u&&u<n&&0<=v&&v<n);
		build();
		int l=low.prod(min(L[u],L[v]),max(L[u],L[v])+1)+1;
		return op(sr.prod(l,L[u]+1),sl.prod(l,L[v]+1));
	}
};
