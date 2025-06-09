#include"io.hpp"
#include<atcoder/segtree>
long op(long x,long y){return max(x,y);}
long e(){return 0;}
template<class T>
struct coord_comp{
	vector<T>a;
	bool f=1;
	void add(T x){a.push_back(x),f=0;}
	void build(){
		if(f)return;
		f=1;
		sort(a.begin(),a.end());
		a.erase(unique(a.begin(),a.end()),a.end());
	}
	int operator()(T x){
		build();
		return lower_bound(a.begin(),a.end(),x)-a.begin();
	}
	T operator[](int i){build();return a[i];}
	int size(){build();return a.size();}
};
int main(){
	int n;
	cin>>n;
	coord_comp<int>compx,compy;
	vector<int>r(n),c(n),x(n);
	for(int i=0;i<n;i++){
		cin>>r[i]>>c[i]>>x[i];
		compx.add(r[i]);
		compy.add(c[i]);
	}
	atcoder::segtree<long,op,e>sc(compy.size());
	vector<long>sr(compx.size());
	vector<vector<int>>que(compx.size());
	for(int i=0;i<n;i++){
		r[i]=compx(r[i]);
		c[i]=compy(c[i]);
		sr[r[i]]+=x[i];
		sc.set(c[i],sc.get(c[i])+x[i]);
		que[r[i]].push_back(i);
	}
	long ans=0;
	for(int i=0;i<compx.size();i++){
		for(int j:que[i]){
			sc.set(c[j],sc.get(c[j])-x[j]);
		}
		ans=max(ans,sr[i]+sc.all_prod());
		for(int j:que[i]){
			sc.set(c[j],sc.get(c[j])+x[j]);
		}
	}
	cout<<ans<<'\n';
}
