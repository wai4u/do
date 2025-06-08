#include"io_20250608_1.hpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"
#include"fenwick_primal_20250608_2.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<int>s(n);
	while(q--){
		int t;
		cin>>t;
		if(t==0){
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			s.add(l,x);
			if(r<n)s.add(r,-x);
		}else{
			int i;
			cin>>i;
			cout<<s.sum(i)<<'\n';
		}
	}
}
