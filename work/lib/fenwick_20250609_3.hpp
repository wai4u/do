#pragma once
//https://atcoder.jp/contests/arc197/submissions/66630418
template<class T>
struct fenwick{
	int n=0,w0=1;
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
		w0=1;while(w0<=n)w0<<=1;
	}
	void add(int i,T x){
		assert(0<=i);
		if(!built){if(i<n)d[i]+=x;return;}
		while(i<n)d[i]+=x,i|=i+1;
	}
	T operator[](int i){
		assert(i<n);
		build();
		T y{};
		while(i>=0)y+=d[i],i&=i+1,i--;
		return y;
	}
	template<class F>
	int max_right(F f){
		build();
		int i=-1,w=w0;
		T x{};
		while(w>>=1)if(i+w<n&&f(x+d[i+w]))x+=d[i+=w];
		return i;
	}
	int lower_bound(T x){
		return max_right([&](T y){return y<x;})+1;
	}
};
