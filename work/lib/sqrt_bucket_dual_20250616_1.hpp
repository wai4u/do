//additive
//dual
//abelian groupの特殊ケース
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
template<class T>
struct sqrt_bucket_dual{
	int n,m=0;
	vector<T>a,s;
	sqrt_bucket_dual(int n):n(n),a(n){while(m*m<n)m++;s.resize(m);}
	void add(int i,T x){
		assert(0<=i&&i<n);
		a[i]+=x;
	}
	void set(int i,T x){
		assert(0<=i&&i<n);
		a[i]=x-s[i/m];
	}
	T operator[](int i){
		assert(0<=i&&i<n);
		return a[i]+s[i/m];
	}
	void add(int l,int r,T x){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		int j=l/m,k=r/m;
		if(j<k&&j*m<l){
			for(int i=l;i<(j+1)*m;i++)a[i]+=x;
			j++;
		}
		for(int i=j;i<k;i++)s[i]+=x;
		for(int i=max(k*m,l);i<r;i++)a[i]+=x;
	}
};
