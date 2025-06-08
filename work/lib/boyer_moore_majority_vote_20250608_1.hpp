//boyer moore
//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
//https://atcoder.jp/contests/abc272/tasks/abc272_g
//
//過半数があればただ一つ見つかる。なければyは最後の更新後半数以上だったものというだけで意義はない。
//https://judge.yosupo.jp/problem/majority_voting (これは動的なのでこのアルゴリズムでは無理)
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
	return{c+c>(int)a.size(),y};
}
