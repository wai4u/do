//newton
double sqrt(double x){
//long double mysqrt(long double x){
	assert(0<=x&&x<1e9);
	double y=x/2;
	//for(int i=0;i<10;i++)y-=(y*y-x)/2*y;
	for(int i=0;i<20;i++)y=(y+x/y)/2;
	return y;
}
/*
#include"rng.hpp"
int main(){
	for(int i=0;i<100;i++){
		double y=rng()%(ulong)1e9;
		double x=sqrt(y);
		//double x=std::sqrt(y);
		//double x=::sqrt(y);
		cout<<y<<' '<<x<<' '<<abs(y-x*x)<<'\n';
	}
}
*/
