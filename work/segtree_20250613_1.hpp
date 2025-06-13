//minimal
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n;
	vector<T>d;
	segtree(int n):n(n),d(n+n,e()){}
	void set(int i,T x){d[i+=n]=x;while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}
	T operator[](int i){return d[i+n];}
	T prod(int l,int r){
		l+=n,r+=n;
		T vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
};
