//primal
//initial fast build
//https://judge.yosupo.jp/submission/291675
template<class T>
struct fenwick{
	int n;vector<T>d;
	fenwick(int n):n(n),d(n){}
	template<class F>fenwick(int n,F f):fenwick(n){
		for(int i=0;i<n;++i){
			d[i]+=f(i);
			int j=i|i+1;
			if(j<n)d[j]+=d[i];
		}
	}
	void add(int i,T x){while(i<n)d[i]+=x,i|=i+1;}
	T operator[](int i){T y{};while(i>=0)y+=d[i],i&=i+1,--i;return y;}
};
