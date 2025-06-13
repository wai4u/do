//minimal
//non commutative monoid
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
template<class T,T(*op)(T,T),T(*e)()>
struct segtree_dual{
	int n,w=1,h=1;
	vector<T>d;
	segtree_dual(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());}
	//void _apply(int i,T x){d[i]=op(d[i],x);}
	//void push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}
	void push(int i){
		int l=i<<1,r=l|1;
		d[l]=op(d[l],d[i]),d[r]=op(d[r],d[i]);
		d[i]=e();
	}
	void pull(int i){for(int j=h;--j;)push(i>>j);}
	T&operator[](int i){pull(i+=w);return d[i];}
	void apply(int l,int r,T x){
		pull(l+=w),pull((r+=w)-1);
		while(l<r){
			if(l&1)d[l++]=op(d[l],x);l>>=1;
			if(r&1)d[r]=op(d[--r],x);r>>=1;
		}
	}
};
