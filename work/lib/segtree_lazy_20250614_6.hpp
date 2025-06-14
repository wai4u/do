//recursive
//minimal
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
template<class X,X(*op)(X,X),X(*e)(),class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>
struct segtree_lazy{
	int n,w=1,h=1;
	vector<X>d;vector<F>lz;
	segtree_lazy(int n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e()),lz.assign(w,id());}
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}
	void push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void pull(int i){for(int j=h;--j;)push(i>>j);}
	X operator[](int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}
	void set(int i,X x){assert(0<=i&&i<n);pull(i+=w),d[i]=x;while(i>>=1)merge(i);}
	void apply(int l,int r,F f){assert(0<=l&&l<=r&&r<=n);apply(l,r,f,1,0,w);}
	void apply(int L,int R,const F&f,int i,int l,int r){
		if(r<=L||R<=l)return;
		if(L<=l&&r<=R)return _apply(i,f);
		int c=l+r>>1;
		push(i);
		apply(L,R,f,i<<1,l,c),apply(L,R,f,i<<1|1,c,r);
		merge(i);
	}
	X prod(int l,int r){assert(0<=l&&l<=r&&r<=n);return prod(l,r,1,0,w);}
	X prod(int L,int R,int i,int l,int r){
		if(r<=L||R<=l)return e();
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		push(i);
		return op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));
	}
};
