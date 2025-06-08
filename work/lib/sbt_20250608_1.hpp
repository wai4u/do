//no binary search
//gcd based
template<class T>
struct SBT{
	static vector<T>get_path(T a,T b){
		assert(a>0&&b>0);
		vector<T>p;
		while(a>1||b>1){
			//3/1->a>b->right 2
			if(a>b){
				T k=(a-1)/b;
				a-=k*b;
				p.push_back(k);
			}else{
				T k=(b-1)/a;
				b-=k*a;
				p.push_back(-k);
			}
		}
		return p;
	}
	static pair<T,T>from_path(vector<T>p,T a=1,T b=1){
		reverse(p.begin(),p.end());
		for(T k:p){
			if(k>0)a+=k*b;
			else b-=k*a;
		}
		return{a,b};
	}
	static pair<T,T>lca(T a,T b,T c,T d){
		vector<T>p1=get_path(a,b),p2=get_path(c,d);
		int m=min(p1.size(),p2.size());
		vector<T>p;
		for(int i=0;i<m;i++){
			T k=p1[i],l=p2[i];
			if(k>0^l>0)break;
			p.push_back(k>0?min(k,l):max(k,l));
			if(k!=l)break;
		}
		return from_path(p);
	}
	static T depth(T a,T b){
		T d=0;
		for(T k:get_path(a,b))d+=abs(k);
		return d;
	}
	static pair<T,T>la(T a,T b,T k){
		if(k<0||k>depth(a,b))return{-1,-1};
		vector<T>p=get_path(a,b);
		while(p.size()){
			T&d=p.back();
			if(abs(d)<k){
				k-=abs(d);
				p.pop_back();
				continue;
			}
			if(d>0)d-=k;
			else d+=k;
			break;
		}
		return from_path(p);
	}
	static tuple<T,T,T,T>range(T p,T q){
		auto path=get_path(p,q);
		auto[a,b]=from_path(path,0,1);
		auto[c,d]=from_path(path,1,0);
		return{a,b,c,d};
	}
	static tuple<T,T,T,T>child(T p,T q){
		auto path=get_path(p,q);
		auto[a,b]=from_path(path,1,2);
		auto[c,d]=from_path(path,2,1);
		return{a,b,c,d};
	}
	static pair<T,T>parent(T p,T q){
		auto[a,b,c,d]=range(p,q);
		if(a+b>=c+d)return{a,b};
		return{c,d};
	}
	template<class FL,class FR>
	static pair<T,T>highest_search(FL fl,FR fr){
		//assert(!fl(0,1)&&fl(1,0)&&!fr(1,0)&&fr(0,1));
		if(!fl(1,0)||!fr(0,1))return{0,0};
		if(fl(0,1))return{0,1};
		if(fr(1,0))return{1,0};
		T a=0,b=1,c=1,d=0;
		auto dfs=[&](auto dfs,auto f,T&a,T&b,T c,T d)->bool{
			if(f(a+c,b+d))return 0;
			if(!dfs(dfs,f,a,b,c+c,d+d)||!f(a+c,b+d))a+=c,b+=d;
			return 1;
		};
		while(dfs(dfs,fl,a,b,c,d)||dfs(dfs,fr,c,d,a,b));
		return{a+c,b+d};
	}
	template<class F>
	static tuple<T,T,T,T>binary_search(T n,F f){
		//assert(f(0,1)&&!f(1,0));
		if(n<1)return{0,0,0,0};
		if(!f(0,1))return{0,0,0,1};
		if(f(1,0))return{1,0,0,0};
		T a=0,b=1,c=1,d=0;
		auto dfs=[&](auto dfs,bool side,T&a,T&b,T c,T d)->bool{
			auto ok=[&](){return a+c<=n&&b+d<=n&&f(a+c,b+d)==side;};
			if(!ok())return 0;
			if(!dfs(dfs,side,a,b,c+c,d+d)||ok())a+=c,b+=d;
			return 1;
		};
		while(dfs(dfs,1,a,b,c,d)||dfs(dfs,0,c,d,a,b));
		return{a,b,c,d};
	}
};
