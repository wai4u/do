//template<class T,bool(*less)(T,T)>
template<class T,bool MAX=0>
struct cartesian_tree{
	int n;
	vector<int>p,l,r,L,R;//l,r:child,L,R:subtree_range[L[i],R[i])
	vector<T>a,st;
	cartesian_tree():n(0){}
	template<class F>
	cartesian_tree(int n,F f){init(n,f);}
	cartesian_tree(const vector<T>&a){init(a);}
	void init(){
		n=0;
		a.clear();
		st.clear();
		l.clear();
		r.clear();
		p.clear();
		L.clear();
		R.clear();
	}
	void init(const vector<T>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	template<class F>
	void init(int n,F f){
		init();
		a.reserve(n);
		l.reserve(n);
		r.reserve(n);
		p.reserve(n);
		L.reserve(n);
		R.reserve(n);
		for(int i=0;i<n;i++)push(f(i));
	}
	//bool f(int i,int j){return a[i]!=a[j]?less(a[i],a[j]):i<j;}
	void push(T x){
		a.push_back(x);
		l.push_back(-1);
		r.push_back(-1);
		p.push_back(-1);
		L.push_back(0);
		R.push_back(-1);
		int i=-1;
		while(st.size()&&(MAX?a[st.back()]<x:a[st.back()]>x)){
			i=st.back();st.pop_back();
			R[i]=n;
		}
		if(i>-1)p[i]=n,l[n]=i;
		if(st.size())r[st.back()]=n,p[n]=st.back(),L[n]=st.back()+1;
		st.push_back(n++);
	}
	int root(){assert(n);return st[0];}
	pair<int,int>range(int i){return{L[i],R[i]<0?n:R[i]};}
};
