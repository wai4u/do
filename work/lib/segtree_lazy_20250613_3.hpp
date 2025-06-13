//proxy set
//non commutative monoid
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
template<class X,X(*op)(X,X),X(*e)(),
class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>
struct segtree_lazy{
	int n,w=1;
	vector<X>d;
	vector<F>lz;
	segtree_lazy(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e()),lz.assign(w,id());}
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}
	void push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}
	void pull(int i){if(i)for(int j=(32-__builtin_clz(i));--j;)push(i>>j);}
	void upd(int i){while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}
	struct proxy{
		segtree_lazy&seg;
		int i;
		proxy(segtree_lazy&seg,int i):seg(seg),i(i){seg.pull(i);}
		proxy&operator=(X x){seg.d[i]=x,seg.upd(i);return *this;}
		void apply(F f){seg._apply(i,f),seg.upd(i);}
		operator X()const{return seg.d[i];}
	};
	proxy operator[](int i){return proxy(*this,i+w);}
	void apply(int l,int r,F f){
		l+=w,r+=w;int L=l/(l&-l),R=r/(r&-r)-1;
		pull(L),pull(R);
		while(l<r){
			if(l&1)_apply(l++,f);l>>=1;
			if(r&1)_apply(--r,f);r>>=1;
		}
		upd(L),upd(R);
	}
	X prod(int l,int r){
		l+=w,r+=w;
		pull(l/(l&-l)),pull(r/(r&-r)-1);
		X vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
};
