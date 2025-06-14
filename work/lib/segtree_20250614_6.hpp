//枝刈り
//https://atcoder.jp/contests/practice2/submissions/66708501
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n,w=1;
	vector<T>d;
	segtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());}
	void set(int i,T x){assert(0<=i&&i<n);d[i+=w]=x;while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}
	T get(int i){assert(0<=i&&i<n);return d[i+w];}
	T operator[](int i){return get(i);}
	T prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e();
		if(l+r==1)return get(l);
		return prod(l,r,1,0,w);
	}
	T prod(int L,int R,int i,int l,int r){
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		if(R<=c)return prod(L,R,i<<1,l,c);
		if(c<=L)return prod(L,R,i<<1|1,c,r);
		return op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));
	}
	template<class F>
	int max_right(int l,F f){
		assert(0<=l&&l<=n);
		if(l==n)return n;
		T x=e();
		return max_right(l,f,x,0,w,1);
	}
	template<class F>
	int max_right(int L,F f,T&x,int l,int r,int i){
		if(r<=L)return L;
		if(L<=l){
			if(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}
			if(l+1==r)return l;
		}
		int c=l+r>>1,j=max_right(L,f,x,l,c,i<<1);
		return j<c||j==n?j:max_right(L,f,x,c,r,i<<1|1);
	}
	template<class F>
	int min_left(int r,F f){
		assert(0<=r&&r<=n);
		if(r==0)return 0;
		T x=e();
		return min_left(r,f,x,0,w,1);
	}
	template<class F>
	int min_left(int R,F f,T&x,int l,int r,int i){
		if(R<=l)return R;
		if(r<=R){
			if(f(op(d[i],x))){x=op(d[i],x);return l;}
			if(l+1==r)return r;
		}
		int c=l+r>>1,j=min_left(R,f,x,c,r,i<<1|1);
		return c<j?j:min_left(R,f,x,l,c,i<<1);
	}
};
