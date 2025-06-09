#include"io.hpp"
#include"fenwick_monoid.hpp"
long op(long x,long y){return max(x,y);}
long e(){return 0;}
int main(){
	int n;
	cin>>n;
	vector<int>h(n),a(n);
	for(int i=0;i<n;i++)cin>>h[i];
	for(int i=0;i<n;i++)cin>>a[i];
	fenwick<long,op,e>s(n);
	for(int i=0;i<n;i++){
		h[i]--;
		s.apply(h[i],s[h[i]-1]+a[i]);
	}
	cout<<s[n-1]<<'\n';
}
