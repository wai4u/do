//binary search
double sqrt(double x){
	assert(0<=x&&x<1e9);
	double ok=0,ng=max(1.,x/2);
	for(int i=0;i<60;i++){
		double y=(ok+ng)/2;
		(y<=x/y?ok:ng)=y;
	}
	return ok;
}
/*
#include"rng.hpp"
int main(){
	for(int i=0;i<100;i++){
		double y=rng()%(ulong)1e9;
		double x=sqrt(y);
		cout<<y<<' '<<x<<' '<<abs(y-x*x)<<'\n';
	}
}
*/
