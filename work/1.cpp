#include"io.hpp"
#include"fenwick_bitset.hpp"
int main(){
	int q;
	cin>>q;
	int k=3e6;
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
