#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		auto dp=vector(n+1,vector(3,(int)1e9));
		dp[0][0]=0;
		for(int i=0;i<n;i++){
			dp[i+1][0]=dp[i][0]+(s[i]=='1');
			dp[i+1][1]=min(dp[i][1],dp[i][0])+(s[i]=='0');
			dp[i+1][2]=min(dp[i][1],dp[i][2])+(s[i]=='1');
		}
		cout<<*min_element(dp[n].begin(),dp[n].end())<<'\n';
 	}
}
