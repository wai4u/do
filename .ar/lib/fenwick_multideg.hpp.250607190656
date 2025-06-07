template<class T>
struct fenwick{
	int n;
	vector<T>d;
	fenwick(int n):n(n),d(n){}
	void add(int i,T x){while(i<n)d[i]+=x,i|=i+1;}
	T operator[](int i){T y{};while(i>=0)y+=d[i],i&=i+1,i--;return y;}
};
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
template<class T>
struct fenwick_1deg{
	fenwick<T>d0,d1;
	fenwick_1deg(int n):d0(n),d1(n){}
	//primal:[i]+=x
	//dual:(i<=j)+=(j-i+1)x
	void add(int i,T x){d0.add(i,(1-i)*x),d1.add(i,x);}
	//primal:sum_j<=i (i-j+1)*[j]
	//dual:[i]
	T operator[](int i){return d0[i]+d1[i]*i;}
};
//https://atcoder.jp/contests/abc256/tasks/abc256_f
template<class T>
struct fenwick_2deg{
	fenwick<T>d0,d1,d2;
	fenwick_2deg(int n):d0(n),d1(n),d2(n){}
	//primal:[i]+=x
	//dual:(i<=j)+=(sum_i<=k<=j (k-i+1)x)=x/2*(j-i+1)(j-i+2)=x/2*(j^2+(-2i+3)j+(-i+1)(-i+2))
	void add(int i,T x){
		d0.add(i,x*(-i+1)*(-i+2));
		d1.add(i,x*(-2*i+3));
		d2.add(i,x);
	}
	//primal:sum_j<=i (sum_k<=j (j-k+1)*[k])
	//dual:[i]
	T operator[](int i){return (d0[i]+d1[i]*i+d2[i]*i*i)/2;}
};
