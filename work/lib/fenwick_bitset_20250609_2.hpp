//https://atcoder.jp/contests/arc197/submissions/66625913
#include"fenwick_20250609_2.hpp"
struct fenwick_bitset{
	constexpr static int M=63;
	int n=0,m;
	vector<unsigned long long>s;
	fenwick<int>d;
	fenwick_bitset(){}
	fenwick_bitset(int n){init(n);}
	void init(int n){
		this->n=n;
		//m=(n+63)/64;
		m=n+M>>6;
		s.assign(m,0);
		d.init(m);
	}
	bool get(int i){
		assert(0<=i&&i<n);
		return s[i>>6]>>(i&M)&1;
	}
	bool operator[](int i){return get(i);}
	void set(int i){
		if(get(i))return;
		s[i>>6]|=1ull<<(i&M);
		d.add(i>>6,1);
	}
	void unset(int i){
		if(!get(i))return;
		s[i>>6]^=1ull<<(i&M);
		//s[i>>6]&=~(1ull<<(i&M));
		d.add(i>>6,-1);
	}
	void flip(int i){if(get(i))unset(i);else set(i);}
	int count(){return d[m-1];}
	int count(int i){
		assert(0<=i&&i<=n);
		if(i==n)return count();
		return d[(i>>6)-1]+__builtin_popcountll(s[i>>6]&(1ull<<(i&M))-1);
	}
	int count(int l,int r){
		assert(l<=r);
		return l==r?0:count(r)-count(l);
	}
	int kth(int i){
		if(i>=count())return -1;
		int l=0;
		int j=d.max_right([&](int c){
			if(i<c)return 0;
			l=c;
			return 1;
		})+1;
		i-=l;
		assert(0<=i&&i<64);
		int ok=0,ng=64;
		while(ng-ok>1){
			int k=ng+ok>>1;
			if(__builtin_popcountll((1ull<<k)-1&s[j])<=i)ok=k;
			else ng=k;
		}
		return(j<<6)+ok;
	}
};
