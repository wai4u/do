//recursive
//https://atcoder.jp/contests/practice2/submissions/64401386
//https://atcoder.jp/contests/practice2/submissions/64401778
template<class T,auto op,auto e>
struct segtree{
	int n,w=1,h=0;
	vector<T>d;
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	segtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());}
	segtree(vector<T>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int i=w;--i;)merge(i);}
	T operator[](int i){assert(0<=i&&i<n);return d[i+w];}
	void set(int i,T x){assert(0<=i&&i<n);d[i+=w]=x;while(i>>=1)merge(i);}
	T fold(int l,int r){assert(0<=l&&l<=r&&r<=n);return _fold(0,w,1,l,r);}
	T _fold(int l,int r,int i,int L,int R){
		if(r<=L||R<=l)return e();
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		return op(_fold(l,c,i<<1,L,R),_fold(c,r,i<<1|1,L,R));
	}
	template<class F>
	int max_right(int l,F ok){
		assert(0<=l&&l<=n);
		T y=e();assert(ok(y));
		return min(_max_right(0,w,1,y,ok,l),n);
	}
	template<class F>
	int _max_right(int l,int r,int i,T&y,F ok,int L){
		if(r<=L)return L;
		if(L<=l){
			if(ok(op(y,d[i]))){y=op(y,d[i]);return r;}
			if(r-l==1)return l;
		}
		int c=l+r>>1,j=_max_right(l,c,i<<1,y,ok,L);
		return j<c?j:_max_right(c,r,i<<1|1,y,ok,L);
	}
	template<class F>
	int min_left(int r,F ok){
		assert(0<=r&&r<=n);
		T y=e();assert(ok(y));
		return _min_left(0,w,1,y,ok,r);
	}
	template<class F>
	int _min_left(int l,int r,int i,T&y,F ok,int R){
		if(R<=l)return R;
		if(r<=R){
			if(ok(op(d[i],y))){y=op(d[i],y);return l;}
			if(r-l==1)return r;
		}
		int c=l+r>>1,j=_min_left(c,r,i<<1|1,y,ok,R);
		return c<j?j:_min_left(l,c,i<<1,y,ok,R);
	}
};
