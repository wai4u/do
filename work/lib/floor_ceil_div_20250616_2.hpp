template<class T,class U>
auto floor_div(T a,U b){return a/b-((a^b)<0&&a%b);}
template<class T,class U>
auto ceil_div(T a,U b){return a/b+((a^b)>0&&a%b);}
/*
int main(){
	for(int a:vector{3,-3})for(int b:vector{10,-10}){
		cout<<a<<' '<<b<<' '<<floor_div(b,a)<<' '<<ceil_div(b,a)<<'\n';
	}
}
*/
