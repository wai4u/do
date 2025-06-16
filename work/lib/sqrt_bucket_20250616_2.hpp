//minimum
//commutative monoidの特殊ケース
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
template<class T,T e>
struct sqrt_bucket{
	int n,m=0;
	vector<T>a,s;
	vector<int>c;
	sqrt_bucket(int n):n(n){while(m*m<n)m++;a.assign(n,e),s.assign(m,e),c.resize(m);}
	void apply(int i,T x){
		assert(0<=i&&i<n);
		a[i]=min(a[i],x);
		i/=m;
		s[i]=min(s[i],x);
	}
	void set(int i,T x){
		//countを持つことで基本O(1)更新可能に
		//最小値が0個にリセットされたタイミングでやり直しO(sqrt(N))
		assert(0<=i&&i<n);
		int j=i/m;
		if(a[i]==x)return;
		if(x<s[j])c[j]=1,s[j]=a[i]=x;
		else if(x==s[j])c[j]++,a[i]=x;
		else{
			c[j]-=a[i]==s[j];
			a[i]=x;
			if(c[j])return;
			s[j]=e;
			for(int i=j*m;i<(j+1)*m;i++){
				if(s[j]==a[i])c[j]++;
				else if(a[i]<s[j])s[j]=a[i],c[j]=1;
			}
		}
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
