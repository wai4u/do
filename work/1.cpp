#include"io.hpp"
//primal
//initial fast build
//https://judge.yosupo.jp/submission/291675
template<class T,bool dual=0>
struct fenwick{
	int n;vector<T>d;
	bool build;
	fenwick(int n){init(n);}
	template<class F>fenwick(int n,F f){init(n,f);}
	void build(){
		for(int i=0;i<n;++i){
			d[i]+=f(i);
			int j=i|i+1;
			if(j<n)d[j]+=d[i];
		}
	}
	void add(int i,T x){while(i<n)d[i]+=x,i|=i+1;}
	T operator[](int i){T y{};while(i>=0)y+=d[i],i&=i+1,--i;return y;}
};
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<long>s(n,[&](int i){
		int x;
		cin>>x;
		return x;
	});
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0)s.add(i,j);
		else cout<<s[j-1]-s[i-1]<<'\n';
	}
}
