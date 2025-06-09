#include"io.hpp"
long ten(int k){return k==0?1:ten(k-1)*10;}
int main(){
	int k;
	cin>>k;
	string s,t;
	cin>>s>>t;
	int n=k*9;
	vector<long>c(10,k),a(10),b(10);
	for(int i=0;i<4;i++)c[s[i]-'0']--,c[t[i]-'0']--;
	for(int i=0;i<4;i++)a[s[i]-'0']++,b[t[i]-'0']++;
	long valid=0,win=0;
	for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){
		if(i==j&&c[i]<2)continue;
		if(!c[i]||!c[j])continue;
		long d=(i==j)?c[i]*(c[i]-1):c[i]*c[j];
		valid+=d;
		long sa=0;
		long sb=0;
		a[i]++,b[j]++;
		for(int k=1;k<=9;k++){
			sa+=ten(a[k])*k;
			sb+=ten(b[k])*k;
		}
		a[i]--,b[j]--;
		if(sa>sb)win+=d;
	}
	assert(valid>0);
	cout<<(double)win/valid<<'\n';
}
