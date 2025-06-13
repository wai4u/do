//recursive
//https://atcoder.jp/contests/practice2/submissions/64392961
template<class X,auto op,auto e,class F,auto mapping,auto composition,auto id>
class segtree{
	int w=1,h=0;
	vector<X>d;vector<F>lz;
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}
	void push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}
	void pull(int i){for(int j=h+1;--j;)push(i>>j);}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void upd(int i){while(i>>=1)merge(i);}
public:
	int n;
	segtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());lz.assign(w,id());}
	segtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int i=w;--i;)merge(i);}
	X operator[](int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}
	void set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}
	void apply(int l,int r,F f){assert(0<=l&&l<=r&&r<=n);_apply(0,w,1,f,l,r);}
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
};
