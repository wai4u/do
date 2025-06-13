//https://atcoder.jp/contests/practice2/submissions/64401002
template<class X,auto op,auto e,class F=X,auto mapping=op,auto composition=op,auto id=e>
struct segtree{
	int n,w=1,h=0;
	vector<X>d;vector<F>lz;
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}
	void push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}
	void pull(int i){for(int j=h+1;--j;)push(i>>j);}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void upd(int i){while(i>>=1)merge(i);}
	segtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());lz.assign(w,id());}
	segtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int i=w;--i;)merge(i);}
	X operator[](int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}
	void set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}
	void _apply(int l,int r,int i,F f,int L,int R){
		if(r<=L||R<=l)return;
		if(L<=l&&r<=R){_apply(i,f);return;}
		int c=l+r>>1;
		push(i),_apply(l,c,i<<1,f,L,R),_apply(c,r,i<<1|1,f,L,R),merge(i);
	}
	X fold(int l,int r){assert(0<=l&&l<=r&&r<=n);return _fold(0,w,1,l,r);}
	X _fold(int l,int r,int i,int L,int R){
		if(r<=L||R<=l)return e();
		if(L<=l&&r<=R)return d[i];
		int c=l+r>>1;
		push(i);return op(_fold(l,c,i<<1,L,R),_fold(c,r,i<<1|1,L,R));
	}
	template<class G>
	int max_right(int l,G ok){
		assert(0<=l&&l<=n);
		X y=e();assert(ok(y));
		if(l==n)return n;
		int r=_max_right(0,w,1,y,ok,l);
		assert(r<=n);
		return r;
	}
	template<class G>
	int _max_right(int l,int r,int i,X&y,G ok,int L){
		if(r<=L)return L;
		if(L<=l){
			if(ok(op(y,d[i]))){y=op(y,d[i]);return min(r,n);}
			if(r-l==1)return l;
		}
		assert(r-l>1);
		push(i);
		int c=l+r>>1,j=_max_right(l,c,i<<1,y,ok,L);
		return j<c||j==n?j:_max_right(c,r,i<<1|1,y,ok,L);
	}
	template<class G>
	int min_left(int r,G ok){
		assert(0<=r&&r<=n);
		X y=e();assert(ok(y));
		if(r==0)return 0;
		return _min_left(0,w,1,y,ok,r);
	}
	template<class G>
	int _min_left(int l,int r,int i,X&y,G ok,int R){
		if(R<=l)return R;
		if(r<=R){
			if(ok(op(d[i],y))){y=op(d[i],y);return l;}
			if(r-l==1)return r;
		}
		assert(r-l>1);
		push(i);
		int c=l+r>>1,j=_min_left(c,r,i<<1|1,y,ok,R);
		return c<j?j:_min_left(l,c,i<<1,y,ok,R);
	}
};
