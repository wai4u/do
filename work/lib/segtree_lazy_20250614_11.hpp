template<class X,X(*op)(X,X),X(*e)(),class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>
struct segtree_lazy{
	int n,w=1,h=1;
	vector<X>d;vector<F>lz;
	segtree_lazy(int n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e()),lz.assign(w,id());}
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}
	void push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void pull(int i){for(int j=h;--j;)push(i>>j);}
	void upd(int i){while(i>>=1)merge(i);}
	void set(int i,X x){assert(0<=i&&i<n);pull(i+=w),d[i]=x,upd(i);}
	void apply(int i,F f){assert(0<=i&&i<n);pull(i+=w),_apply(i,f),upd(i);}
	X get(int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}
	X operator[](int i){return get(i);}
	void apply(int l,int r,F f){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		if(l+1==r)return apply(l,f);
		apply(l,r,f,1,0,w);
	}
	void apply(int L,int R,const F&f,int i,int l,int r){
		if(L<=l&&r<=R)return _apply(i,f);
		int c=l+r>>1;
		push(i);
		if(L<c)apply(L,R,f,i<<1,l,c);
		if(c<R)apply(L,R,f,i<<1|1,c,r);
		merge(i);
	}
	X prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e();
		if(l+1==r)return get(l);
		return prod(l,r,1,0,w);
	}
	X prod(int L,int R,int i,int l,int r){
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		push(i);
		if(R<=c)return prod(L,R,i<<1,l,c);
		if(c<=L)return prod(L,R,i<<1|1,c,r);
		return op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));
	}
	template<class G>
	int max_right(int l,G f){
		assert(0<=l&&l<=n);
		if(l==n)return n;
		X x=e();
		return max_right(l,f,x,0,w,1);
	}
	template<class G>
	int max_right(int L,G f,X&x,int l,int r,int i){
		if(L<=l){
			if(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}
			if(l+1==r)return l;
		}
		push(i);
		int c=l+r>>1,j=c<=L?L:max_right(L,f,x,l,c,i<<1);
		return j<c||j==n?j:max_right(L,f,x,c,r,i<<1|1);
	}
	template<class G>
	int min_left(int r,G f){
		assert(0<=r&&r<=n);
		if(r==0)return 0;
		X x=e();
		return min_left(r,f,x,0,w,1);
	}
	template<class G>
	int min_left(int R,G f,X&x,int l,int r,int i){
		if(r<=R){
			if(f(op(d[i],x))){x=op(d[i],x);return l;}
			if(l+1==r)return r;
		}
		push(i);
		int c=l+r>>1,j=R<=c?R:min_left(R,f,x,c,r,i<<1|1);
		return c<j?j:min_left(R,f,x,l,c,i<<1);
	}
};
