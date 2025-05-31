template<class T>
struct fenwick{
	int n;
	vector<T>d;
	fenwick(int n):n(n),d(n){}
	void add(int i,T x){
		assert(0<=i);
		while(i<n)d[i]+=x,i|=i+1;
	}
	T operator[](int i){
		assert(i<n);
		T y{};
		while(i>=0)y+=d[i],i&=i+1,i--;
		return y;
	}
};
