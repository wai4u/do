//primal-dual
//fenwick_20250608_5.hpp で言及した通り、サイズ初期化以外の初期化手段を廃止
//代わりにlazy buildをする
//ただしadd時のbuild保留optionを廃止。initを呼んだ後[i]を呼ぶまでの間だけO(1)addされる。
//https://judge.yosupo.jp/submission/291769
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
		if(!built){d[i]+=x;return;}
		while(i<n)d[i]+=x,i|=i+1;
	}
	T operator[](int i){
		assert(i<n);
		build();
		T y{};
		while(i>=0)y+=d[i],i&=i+1,i--;
		return y;
	}
};
