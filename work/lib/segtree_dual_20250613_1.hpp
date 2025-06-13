//minimal
//commutative
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
template<class T,T(*op)(T,T),T(*e)()>
struct segtree_dual{
	int n;
	vector<T>d;
	segtree_dual(int n):n(n),d(n+n,e()){}
	T operator[](int i){
		T y=d[i+=n];
		while(i>>=1)y=op(y,d[i]);
		return y;
	}
	void apply(int l,int r,T x){
		l+=n,r+=n;
		while(l<r){
			if(l&1)d[l++]=op(d[l],x);l>>=1;
			if(r&1)d[r]=op(d[--r],x);r>>=1;
		}
	}
};
