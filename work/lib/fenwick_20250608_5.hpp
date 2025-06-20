//primal-dual
//primalかdualかは外側で使用者に委ねる
//primalは値配列,dualは差分配列で初期化
//assign系の固定値初期化はdualの時に使い方を間違えやすい(差分を渡すのが正しいが値を渡しそう)ので廃止
//(lazy build機能だけ残して、サイズ初期化のみにしても良さそうか)
//add(l,r),sum(i),sum(l,r),get(i)などprimalかdualどちらかでしか使わなかったり、処理が違うmethodは廃止
//区間クエリ(add for dual,[i](sum) for primal)は閉区間
//https://judge.yosupo.jp/submission/291767
template<class T>
struct fenwick{
	int n=0;
	vector<T>d,s;
	bool built=0;
	fenwick(){}
	fenwick(int n){init(n);}
	fenwick(const vector<T>&a){init(a);}
	template<class U>fenwick(const vector<U>&a){init(a);}
	template<class F>fenwick(int n,F f){init(n,f);}
	void init(int n){
		this->n=n;
		d.assign(n,T{});
		built=0;
	}
	template<class U>void init(const vector<U>&a){
		init(a.size(),[&](int i){return a[i];});
	}
	template<class F>void init(int n,F f){
		init(n);
		for(int i=0;i<n;i++)d[i]=f(i);
	}
	void build(){
		if(built)return;
		built=1;
		s=d;
		for(int i=0;i<n;i++){
			int j=i|i+1;
			if(j<n)s[j]+=s[i];
		}
	}
	void add(int i,T x,bool upd=1){
		assert(0<=i);
		d[i]+=x;
		if(!built||!upd){built=0;return;}
		while(i<n)s[i]+=x,i|=i+1;
	}
	T operator[](int i){
		assert(i<n);
		build();
		T y{};
		while(i>=0)y+=s[i],i&=i+1,i--;
		return y;
	}
};
