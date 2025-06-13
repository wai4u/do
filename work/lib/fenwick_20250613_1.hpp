//internally 1-indexed
//https://atcoder.jp/contests/arc197/submissions/66700322
//https://atcoder.jp/contests/arc197/submissions/66700386
template<class T,bool dual=0>
struct fenwick{
	int n=0;
	vector<T>d,s;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	template<class F>fenwick(int n,F f){init(n,f);}
	void init(int n){
		this->n=n;
		d.assign(n,T{});
		built=0;
	}
	template<class F>void init(int n,F f){
		//dual時は差分配列を渡す
		init(n);
		for(int i=0;i<n;i++)d[i]=f(i);
	}
	void build(){
		if(built)return;
		built=1;
		s.assign(n+1,T{});
		for(int i=1;i<=n;i++){
			s[i]+=d[i-1];
			int j=i+(i&-i);
			if(j<=n)s[j]+=s[i];
		}
	}
	//primal:[i,n),dual:[i]
	void add(int i,T x){
		if constexpr(!dual)assert(0<=i&&i<n);
		else assert(0<=i&&i<=n);
		if(i<n)d[i]+=x;
		i++;
		if(built)while(i<=n)s[i]+=x,i+=i&-i;
	}
	template<class U=void>
	enable_if_t<dual,U>add(int l,int r,T x){
		assert(l<=r);
		if(l<r)add(l,x),add(r,-x);
	}
	T _sum(int i){
		assert(0<=i&&i<=n);
		build();
		T y{};
		while(i>0)y+=s[i],i-=i&-i;
		return y;
	}
	//primal:[0,i),dual:[i]
	T get(int i){
		assert(0<=i&&i<n);
		if constexpr(!dual)return d[i];
		else return _sum(i+1);
	}
	T operator[](int i){return get(i);}
	//[0,i)
	template<class U=T>
	enable_if_t<!dual,U>sum(int i){return _sum(i);}
	template<class U=T>
	enable_if_t<!dual,U>sum(int l,int r){
		assert(l<=r);
		return l==r?T{}:sum(r)-sum(l);
	}
	//primal:sum([0,r)) is ok
	//dual:ok([i]) for i:[0,r)
	template<class F>
	int max_right(F f){
		int i=0,w=1;while(w<=n)w<<=1;
		build();
		T x{};
		while(w>>=1)if(i+w<=n&&f(x+s[i+w]))x+=s[i+=w];
		return i;
	}
	template<class F>
	int max_right(int l,F f){
		assert(0<=l&&l<=n);
		int i=0,w=1;while(w<=n)w<<=1;
		build();
		T x=-_sum(l);
		while(w>>=1)if(i+w<=n&&(i+w<=l||f(x+s[i+w])))x+=s[i+=w];
		return i;
	}
};
/*
int main(){
	int q;
	cin>>q;
	int k=3e6;
	//fenwick<int>s(k);
	//for(int i=1;i<k;i++)s.add(i,1);
	fenwick<int>s(k,[&](int i){return 1;});
	s.add(0,-1);
	vector<bool>f(k,1);
	f[0]=0;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a<k&&f[a]){
			for(int i=a;i<k;i+=a)if(f[i]){
				f[i]=0;
				s.add(i,-1);
			}
		}
		cout<<s.max_right([&](int x){return x<b;})<<'\n';
	}
}
*/
