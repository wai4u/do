//recursive
//minimal
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n,w=1;
	vector<T>d;
	segtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());}
	void set(int i,T x){d[i+=w]=x;while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}
	T operator[](int i){return d[i+w];}
	/*
	T prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		return prod(l,r,1,0,w);
	}
	*/
	T prod(int l,int r){return prod(l,r,1,0,w);}
	T prod(int L,int R,int i,int l,int r){
		if(r<=L||R<=l)return e();
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		return op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));
	}
};
