#pragma once
//https://atcoder.jp/contests/arc197/submissions/66622201
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
	int lower_bound(T x){//first [i]>=x
		int i=0,w=1;while(w<=n)w<<=1;
		build();
		while(w>>=1)if(i+w<=n&&d[i+w-1]<x)x-=d[i+w-1],i+=w;
		return i;
	}
};
