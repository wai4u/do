//additive
//abelian groupの特殊ケース
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
template<class T>
struct sqrt_bucket{
	int n,m=0;
	vector<T>a,s;
	sqrt_bucket(int n):n(n),a(n){while(m*m<n)m++;s.resize(m);}
	void add(int i,T x){
		assert(0<=i&&i<n);
		a[i]+=x;
		s[i/m]+=x;
	}
	void set(int i,T x){
		assert(0<=i&&i<n);
		add(i,x-a[i]);
	}
	T sum(int r){
		assert(0<=r&&r<=n);
		int j=r/m;
		T y{};
		for(int i=0;i<j;i++)y+=s[i];
		for(int i=j*m;i<r;i++)y+=a[i];
		return y;
	}
	T sum(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		T y{};
		int j=l/m,k=r/m;
		if(j<k&&j*m<l){
			for(int i=l;i<(j+1)*m;i++)y+=a[i];
			j++;
		}
		for(int i=j;i<k;i++)y+=s[i];
		for(int i=max(k*m,l);i<r;i++)y+=a[i];
		return y;
	}
};
