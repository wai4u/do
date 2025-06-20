template<class T>
T ikthroot(T n,int k){
	assert(n>=0&&k>0);
	if(k==1)return n;
	if(n<2)return n;
	T ok=0,ng=numeric_limits<T>::max();
	auto f=[&](T x)->bool{
		T y=1;
		for(int i=0;i<k;i++){
			if(y>n/x)return 0;
			y*=x;
		}
		return 1;
	};
	while(ng-ok>1){
		T x=(ok+ng)/2;
		(f(x)?ok:ng)=x;
	}
	assert(f(ok)&&!f(ok+1));
	return ok;
}
/*
#include"rng.hpp"
int main(){
	for(int i=0;i<10000;i++){
		int n=rng()%(int)1e9;
		for(int k=1;k<65;k++)ikthroot(n,k);
		//ikthroot(n,2);
	}
}
*/
