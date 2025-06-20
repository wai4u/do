//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
//https://atcoder.jp/contests/practice2/submissions/66685138
template<
class X,X(*op)(X,X),X(*e)(),
class F=X,X(*mapping)(F,X)=op,
F(*composition)(F,F)=op,F(*id)()=e
>
struct segtree_lazy{
	int n=0,w=0;
	vector<X>d;
	vector<F>lz;
	bool built=0,hung=0;
	segtree_lazy(){}
	segtree_lazy(int n){init(n);}
	template<class G>
	segtree_lazy(int n,G f){init(n,f);}
	template<class U>
	segtree_lazy(const vector<U>&a){init(a);}
	void init(int n){
		this->n=n;
		w=1;while(w<n)w<<=1;
		d.assign(w+w,e());
		lz.assign(w,id());
		hung=built=0;
	}
	template<class G>
	void init(int n,G f){
		init(n);
		for(int i=0;i<n;i++)d[w+i]=f(i);
	}
	template<class U>
	void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void _apply(int i,F f){
		//d[i]=mapping(f,d[i]);
		if(built||i>=w)d[i]=mapping(f,d[i]);
		if(i<w)lz[i]=composition(f,lz[i]);
	}
	void push(int i){
		_apply(i<<1,lz[i]);
		_apply(i<<1|1,lz[i]);
		lz[i]=id();
	}
	void pull(int i){
		if(!i)return;
		for(int j=(32-__builtin_clz(i));--j;)push(i>>j);
	}
	void update_all(){
		if(!hung)return;
		hung=0;
		for(int i=1;i<w;i++)push(i);
	}
	void merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}
	void upd(int i){while(i>>=1)merge(i);}
	void build(){
		if(built)return;
		if(hung)update_all();
		built=1;
		for(int i=w;--i;)merge(i);
		/*
		built=1;
		for(int i=w;--i;){
			merge(i);
			d[i]=mapping(lz[i],d[i]);
		}
		*/
	}
	const X&get(int i){
		assert(0<=i&&i<n);
		i+=w;
		if(hung)pull(i);
		return d[i];
	}
	const X&operator[](int i){return get(i);}
	vector<X>get_all(){
		update_all();
		return{d.begin()+w,d.begin()+w+n};
	}
	void set(int i,X x){
		get(i);
		d[i+w]=x;
		if(built)upd(i+w);
	}
	void apply(int i,F f){
		get(i);
		_apply(i+w,f);
		if(built)upd(i+w);
	}
	void apply(int l,int r,F f){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		if(l+1==r)return apply(l,f);
		l+=w,r+=w;
		int L=l/(l&-l),R=r/(r&-r)-1;
		if(hung)pull(L),pull(R);
		hung=1;
		while(l<r){
			if(l&1)_apply(l++,f);
			if(r&1)_apply(--r,f);
			l>>=1,r>>=1;
		}
		if(built)upd(L),upd(R);
	}
	X prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e();
		if(l+1==r)return get(l);
		l+=w,r+=w;
		build();
		if(hung)pull(l/(l&-l)),pull(r/(r&-r)-1);
		X vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);
			if(r&1)vr=op(d[--r],vr);
			l>>=1,r>>=1;
		}
		return op(vl,vr);
	}
};
