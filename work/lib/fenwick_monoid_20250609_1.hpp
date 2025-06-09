//fenwick tree monoid
//https://atcoder.jp/contests/dp/submissions/66630023
//templateでop,eを指定する実装
template<class T,T(*op)(T,T),T(*e)()>
struct fenwick{
	int n=0;bool built=0;
	vector<T>d;
	fenwick(){}
	fenwick(int n){init(n);}
	void init(int n){
		this->n=n;
		d.assign(n,e());
		built=0;
	}
	void apply(int i,T x){
		assert(0<=i);
		while(i<n)d[i]=op(d[i],x),i|=i+1;
	}
	T operator[](int i){
		assert(i<n);
		build();
		T y=e();
		while(i>=0)y=op(y,d[i]),i&=i+1,i--;
		return y;
	}
};
