//https://atcoder.jp/contests/practice2/submissions/64402027
//https://atcoder.jp/contests/practice2/submissions/64402021
int bitlen(int x){return x?32-__builtin_clz(x):0;}
template<class T,auto op,auto e>
struct segtree{
	int n,w=1;
	vector<T>d;
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	segtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());}
	segtree(vector<T>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int i=w;--i;)merge(i);}
	T operator[](int i){assert(0<=i&&i<n);return d[i+w];}
	void set(int i,T x){assert(0<=i&&i<n);d[i+=w]=x;while(i>>=1)merge(i);}
	T fold(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		l+=w,r+=w;
		T vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
	template<class F>
	int max_right(int l,F ok){
		assert(0<=l&&l<=n);
		T y=e();
		assert(ok(y));
		if(l==n)return n;
		l+=w,l/=l&-l;
		while(ok(op(y,d[l]))){y=op(y,d[l++]);if((l/=l&-l)==1)return n;}
		while(l<w)if(ok(op(y,d[l<<=1])))y=op(y,d[l++]);
		assert(l<w+n);
		return l-w;
	}
	template<class F>
	int min_left(int r,F ok){
		assert(0<=r&&r<=n);
		T y=e();
		assert(ok(y));
		if(r==0)return 0;
		r+=w,r/=r&-r;
		if(r==1)r=2;
		while(ok(op(d[r-1],y))){y=op(d[--r],y);if((r/=r&-r)==1)return 0;}
		while(r<=w)if(ok(op(d[(r<<=1)-1],y)))y=op(d[--r],y);
		return r-w;
	}
};
