#include"io.hpp"
struct line{
	long a,b;
	long operator()(long x){return a*x+b;}
}
//min
long inf=2l<<60;
struct lichao_tree{
	int n,w;
	vector<long>xs,f;
	lichao_tree(vector<long>xs):xs(xs){
		n=xs.size();
		w=1;
		while(w<n)w<<=1;
		xs.resize(w,1<<30);
		f.assign(w+w,line{0,inf});
	}
	void add(line g){add(g,0,w,1);}
	void add(line g,int l,int r,int i){
		int c=l+r>>1;
		long x=xs[c];
		if(g.eval(x)<f[i].eval(x))swap(g,f[i]);
		if(r-l==1)return;
		if(g.a>f[i].a)add(g,l,c,i<<1);
		if(g.a<f[i].a)add(g,c,r,i<<1|1);
	}
	long calc(long x){
		int i
};
int main(){
	int n,q;
	cin>>n>>q;
}
