//minimum
//commutative monoidの特殊ケース
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
template<class T,T e>
struct sqrt_bucket{
	int n,m=0;
	vector<T>a,s;
	sqrt_bucket(int n):n(n){while(m*m<n)m++;a.assign(n,e),s.assign(m,e);}
	void apply(int i,T x){
		assert(0<=i&&i<n);
		a[i]=min(a[i],x);
		i/=m;
		s[i]=min(s[i],x);
	}
	void set(int i,T x){
		//O(sqrt(N))だが、場合によってはO(1)もある
		assert(0<=i&&i<n);
		int j=i/m;
		assert(s[j]<=a[i]);
		if(x<=a[i])s[j]=min(s[j],x);
		else if(s[j]==a[i]){
			s[j]=e;
			a[i]=x;
			for(int i=j*m;i<(j+1)*m;i++)s[j]=min(s[j],a[i]);
		}
		a[i]=x;
	}
	T prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return e;
		int ans=e;
		int j=l/m,k=r/m;
		if(j<k&&j*m<l){
			for(int i=l;i<(j+1)*m;i++)ans=min(ans,a[i]);
			j++;
		}
		for(int i=j;i<k;i++)ans=min(ans,s[i]);
		for(int i=max(k*m,l);i<r;i++)ans=min(ans,a[i]);
		return ans;
	}
};
