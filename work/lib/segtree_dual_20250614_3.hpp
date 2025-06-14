//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
template<class T,T(*op)(T,T),T(*e)()>
struct segtree_dual{
	int n=0,w=0;
	vector<T>d;
	bool hung=0;
	segtree_dual(){}
	segtree_dual(int n){init(n);}
	template<class F>segtree_dual(int n,F f){init(n,f);}
	template<class U>segtree_dual(const vector<U>&a){init(a);}
	void init(int n){
		this->n=n;
		w=1;while(w<n)w<<=1;
		d.assign(w+w,e());
		hung=0;
	}
	template<class F>void init(int n,F f){
		init(n);for(int i=0;i<n;i++)d[w+i]=f(i);
	}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void _apply(int i,T x){d[i]=op(d[i],x);}
	void push(int i){if(hung)_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}
	void pull(int i){if(hung&&i)for(int j=(32-__builtin_clz(i));--j;)push(i>>j);}
	void pull_all(){if(hung)for(int i=1;i<w;i++)push(i);hung=0;}
	vector<T>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}
	T&get(int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}
	T&operator[](int i){return get(i);}
	void set(int i,T x){get(i)=x;}
	void apply(int i,T x){T&y=get(i);y=op(y,x);}
	void apply(int l,int r,T x){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		if(l+1==r)return apply(l,x);
		apply(l,r,x,1,0,w);
		hung=1;
	}
	void apply(int L,int R,const T&x,int i,int l,int r){
		if(L<=l&&r<=R)return _apply(i,x);
		int c=l+r>>1;
		push(i);
		if(L<c)apply(L,R,x,i<<1,l,c);
		if(c<R)apply(L,R,x,i<<1|1,c,r);
	}
};
