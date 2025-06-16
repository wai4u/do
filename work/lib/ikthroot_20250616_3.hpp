//exponential binary search
template<class T>
T ikthroot(T n,int k){
	assert(n>=0&&k>0);
	if(k==1)return n;
	if(n<2)return n;
	auto f=[&](T x)->bool{
		T y=1;
		for(int i=0;i<k;i++){
			if(y>n/x)return 0;
			y*=x;
		}
		return 1;
	};
	/*
	if(!f(2))return 1;
	T ok=2,ng=4;
	while(f(ng))ng*=ng;
	*/
	T ok=1,ng=2;
	while(f(ng))ok=ng,ng*=ng;
	while(ng-ok>1){
		T x=(ok+ng)/2;
		(f(x)?ok:ng)=x;
	}
	assert(f(ok)&&!f(ok+1));
	return ok;
}
/*
#include"rng.hpp"
#include"io.hpp"
int main(){
	for(int i=0;i<10000;i++){
		//int n=rng()%(int)1e9;
		ulong n=rng();
		for(int k=1;k<65;k++)ikthroot(n,k);
		//ikthroot(n,2);
	}
	for(int i=0;i<100;i++){
		unsigned long n=rng();
		unsigned long x=ikthroot(n,3);
		cout<<n<<' '<<x<<' '<<n-(__int128)x*x*x<<' '<<n-__int128(x+1)*(x+1)*(x+1)<<'\n';
	}
}
*/
