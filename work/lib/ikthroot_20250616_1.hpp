ulong ikthroot(ulong n,int k){
	assert(n>=0&&k>0);
	if(k==1)return n;
	if(n<2)return n;
	//if(k>=64)return 1;
	ulong ok=0,ng=1ul<<(63+k)/k;
	auto f=[&](ulong x)->bool{
		ulong y=1;
		for(int i=0;i<k;i++){
			//if((__int128)y*x>n)return 0;
			if(y>n/x)return 0;
			y*=x;
		}
		return 1;
	};
	while(ng-ok>1){
		ulong x=(ok+ng)/2;
		(f(x)?ok:ng)=x;
	}
	assert(f(ok)&&!f(ok+1));
	return ok;
}
/*
#include"rng.hpp"
int main(){
	for(int i=0;i<100000;i++){
		ulong n=rng();
		for(int k=1;k<65;k++)ikthroot(n,k);
		//ikthroot(n,2);
	}
}
*/
