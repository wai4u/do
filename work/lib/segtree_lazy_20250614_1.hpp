//https://atcoder.jp/contests/practice2/submissions/64396190
//https://atcoder.jp/contests/practice2/submissions/64400457
int bitlen(int x){return x?32-__builtin_clz(x):0;}
template<class X,auto op,auto e,class F=X,auto mapping=op,auto composition=op,auto id=e>
struct segtree{
	int n,w=1;
	vector<X>d;vector<F>p;
	segtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());p.assign(w,id());}
	segtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int i=w;--i;)merge(i);}
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)p[i]=composition(f,p[i]);}
	void push(int i){_apply(i<<1,p[i]),_apply(i<<1|1,p[i]),p[i]=id();}
	void pull(int i){for(int j=bitlen(i);--j>0;)push(i>>j);}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void upd(int i){while(i>>=1)merge(i);}
	X operator[](int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}
	void set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}
	void apply(int l,int r,F f){
		assert(0<=l&&l<=r&&r<=n);
		l+=w,r+=w;int L=l/(l&-l),R=r/(r&-r)-1;
		pull(L),pull(R);
		while(l<r){
			if(l&1)_apply(l++,f);l>>=1;
			if(r&1)_apply(--r,f);r>>=1;
		}
		upd(L),upd(R);
	}
	X fold(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		l+=w,r+=w;
		pull(l/(l&-l));pull(r/(r&-r)-1);
		X vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
	template<class G>
	int max_right(int l,G ok){
		assert(0<=l&&l<=n);
		X y=e();
		assert(ok(y));
		if(l==n)return n;
		l+=w;
		pull(l/=l&-l);
		while(ok(op(y,d[l]))){y=op(y,d[l++]);if((l/=l&-l)==1)return n;}
		while(l<w){push(l);if(ok(op(y,d[l<<=1])))y=op(y,d[l++]);}
		assert(l<w+n);
		return l-w;
	}
	template<class G>
	int min_left(int r,G ok){
		assert(0<=r&&r<=n);
		X y=e();
		assert(ok(y));
		if(r==0)return 0;
		r+=w;
		pull((r/=r&-r)-1);
		if(r==1)r=2;
		while(ok(op(d[r-1],y))){y=op(d[--r],y);if((r/=r&-r)==1)return 0;}
		while(r<=w){push(r-1);if(ok(op(d[(r<<=1)-1],y)))y=op(d[--r],y);}
		return r-w;
	}
};
