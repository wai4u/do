#include"io.hpp"
//#include"fenwick_20250609_2.hpp"
/*
int main(){
	int q;
	cin>>q;
	int k=3e6;
	fenwick<int>s(k);
	for(int i=1;i<k;i++)s.add(i,1);
	vector<bool>f(k,1);
	f[0]=0;
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a<k&&f[a]){
			for(int i=a;i<k;i+=a)if(f[i]){
				f[i]=0;
				s.add(i,-1);
			}
		}
		cout<<s.lower_bound(b)<<'\n';
	}
}
*/
#include"fenwick_bitset_20250609_2.hpp"
int main(){
	int q;
	cin>>q;
	//int k=3e6;
	int k=2750160;
	fenwick_bitset s(k);
	for(int i=1;i<k;i++)s.set(i);
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a<k&&s[a]){
			for(int i=a;i<k;i+=a)s.unset(i);
		}
		cout<<s.kth(b-1)<<'\n';
	}
}
