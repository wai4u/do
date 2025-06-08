#include"io.hpp"
#include"fenwick.hpp"
int main(){
	int n,q;
	cin>>n>>q;
	fenwick<long>s(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.add(i,x);
	}
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		if(t==0)s.add(i,j);
		else cout<<s[j-1]-s[i-1]<<'\n';
	}
}
