//proxy set
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n;
	vector<T>d;
	segtree(int n):n(n),d(n+n,e()){}
	struct proxy{
		vector<T>&d;
		int i;
		/*
		proxy&operator=(T x){
			d[i]=x;
			int j=i;
			while(j>>=1)d[j]=op(d[j<<1],d[j<<1|1]);
			return *this;
		}
		*/
		void upd(){int j=i;while(j>>=1)d[j]=op(d[j<<1],d[j<<1|1]);}
		proxy&operator=(T x){d[i]=x,upd();return *this;}
		void apply(T x){d[i]=op(d[i],x),upd();}
		//operator T(){return d[i];}
		operator T()const {return d[i];}
	};
	proxy operator[](int i){return proxy{d,i+n};}
	T prod(int l,int r){
		l+=n,r+=n;
		T vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
};
