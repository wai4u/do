//https://atcoder.jp/contests/abc298/submissions/66630079
template<class T>
struct coord_comp{
	vector<T>a;bool f=1;
	void add(T x){a.push_back(x),f=0;}
	void build(){if(!f)f=1,sort(a.begin(),a.end()),a.erase(unique(a.begin(),a.end()),a.end());}
	int operator()(T x){build();return lower_bound(a.begin(),a.end(),x)-a.begin();}
	T operator[](int i){build();return a[i];}
	int size(){build();return a.size();}
};
