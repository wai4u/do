#include"io.hpp"
int main(){
	int n;
	cin>>n;
	map<string,int>c;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		c[s]++;
	}
	vector<pair<int,string>>a;
	for(auto[s,c]:c)a.push_back(make_pair(-c,s));
	sort(a.begin(),a.end());
	int v=a[0].first;
	for(auto[d,s]:a){
		if(d>v)break;
		cout<<s<<'\n';
	}
}
