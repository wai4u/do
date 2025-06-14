#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"
#include"io_20250608_1.hpp"
#include"fenwick_1deg_20250614_1.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick_1deg<long>s(n);
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		l--;
		if(t==0){
			int x;
			cin>>x;
			s.add(l,x);
			s.add(r,-x);
		}else{
			cout<<s[r-1]-s[l-1]<<'\n';
		}
	}
}
