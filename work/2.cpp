#include"io.hpp"
//primal
//internally 1-indexed
//https://judge.yosupo.jp/submission/291760
template<class T>
struct fenwick{
	int n=0;
	vector<T>a,s;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	template<class F>fenwick(int n,F f){init(n,f);}
	template<class U>fenwick(const vector<U>&a){init(a);}
	fenwick(const vector<T>&a){init(a);}
	fenwick(int n,T x){init(n,x);}
	template<class U>void assign(int n,U x){init(n,x);}
	void init(int n){
		this->n=n;
		a.assign(n,T{});
		built=0;
	}
	template<class F>void init(int n,F f){
		init(n);
		for(int i=0;i<n;i++)a[i]=f(i);
	}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	void init(int n,T x){init(n,[&](int i){return x;});}
	void build(){
		if(built)return;
		built=1;
		s.assign(n+1,T{});
		for(int i=1;i<=n;i++){
			s[i]+=a[i-1];
			int j=i+(i&-i);
			if(j<=n)s[j]+=s[i];
		}
	}
	void add(int i,T x,bool upd=1){
		assert(0<=i&&i<n);
		a[i]+=x;
		if(!built||!upd){built=0;return;}
		i++;
		while(i<=n)s[i]+=x,i+=i&-i;
	}
	void set(int i,T x,bool upd=1){
		assert(0<=i&&i<n);
		if(built&&upd)add(i,x-a[i],1);
		else a[i]=x,built=0;
	}
	const T&get(int i){
		assert(0<=i&&i<n);
		return a[i];
	}
	T sum(int i){
		assert(0<=i&&i<=n);
		build();
		T y{};
		while(i>0)y+=s[i],i-=i&-i;
		return y;
	}
	T sum(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		return sum(r)-sum(l);
	}
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
		if(t==0){
			s.add(i,j);
		}else{
			cout<<s.sum(i,j)<<'\n';
		}
	}
}
