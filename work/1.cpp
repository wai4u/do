#include"io.hpp"
#include"union_find_20250609_4.hpp"
template<class T>
struct fenwick{
	int n=0;
	vector<T>d;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	void init(int n){
		this->n=n;
		d.assign(n,T{});
		built=0;
	}
	void build(){
		if(built)return;
		built=1;
		for(int i=0;i<n;i++){
			int j=i|i+1;
			if(j<n)d[j]+=d[i];
		}
	}
	void add(int i,T x){
		assert(0<=i);
		if(!built){d[i]+=x;return;}
		while(i<n)d[i]+=x,i|=i+1;
	}
	T operator[](int i){
		assert(i<n);
		build();
		T y{};
		while(i>=0)y+=d[i],i&=i+1,i--;
		return y;
	}
	int lower_bound(T x){
		int i=0,w=1;while(w<=n)w<<=1;
		build();
		while(w>>=1)if(i+w<=n&&d[i+w-1]<x)x-=d[i+w-1],i+=w;
		return i;
	}
};
int main(){
	int q;
	cin>>q;
	int k=5e6;
	fenwick<int>s(k);
	for(int i=1;i<k;i++)s.add(i,1);
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
		cout<<s.lower_bound(b)<<'\n';
	}
}
