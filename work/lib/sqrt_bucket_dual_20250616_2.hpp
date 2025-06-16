//non commutative monoid
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
template<class T,T(*op)(T,T),T(*e)()>
struct sqrt_bucket_dual{
	int n,m=0;
	vector<T>a,s;
	sqrt_bucket_dual(int n):n(n),a(n,e()){while(m*m<n)m++;s.assign(m,e());}
	void push(int j){
		for(int i=j*m;i<(j+1)*m;i++)a[i]=op(a[i],s[j]);
		s[j]=e();
	}
	void apply(int i,T x){
		assert(0<=i&&i<n);
		push(i/m);
		a[i]=op(a[i],x);
	}
	void set(int i,T x){
		assert(0<=i&&i<n);
		push(i/m);
		a[i]=x;
	}
	T&operator[](int i){
		assert(0<=i&&i<n);
		push(i/m);
		return a[i];
	}
	void apply(int l,int r,T x){
		assert(0<=l&&l<=r&&r<=n);
		if(l==r)return;
		int j=l/m,k=r/m;
		if(j<k&&j*m<l){
			push(j);
			for(int i=l;i<(j+1)*m;i++)a[i]=op(a[i],x);
			j++;
		}
		for(int i=j;i<k;i++)s[i]=op(s[i],x);
		if(r==k*m)return;
		push(k);
		for(int i=max(k*m,l);i<r;i++)a[i]=op(a[i],x);
	}
};
