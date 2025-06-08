#include"io.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/majority_voting"
//boyer moore
//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
//https://judge.yosupo.jp/problem/majority_voting
//過半数があればただ一つ見つかる。なければyは最後の更新後半数以上だったものというだけで意義はない。
template<class T>
pair<bool,T>majority_vote(const vector<T>&a){
	T y;
	int c=0;
	for(T x:a){
		if(!c)y=x,c=1;
		else if(x==y)c++;
		else c--;
	}
	c=0;
	for(T x:a)c+=x==y;
	return{c+c>n,y};
}
int main(){
	int n,q;
	cin>>n>>q;
}
