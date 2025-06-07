#include"io.hpp"
#include"mcf_ssp_bellmandijkstra.hpp"
int main(){
	int h,w;
	cin>>h>>w;
	int N=h*w;
	auto a=vector(h,vector(w,0l));
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)cin>>a[i][j];
	long tot=0;
	MCF<int,long>g(N+2,1);
	int s=N,t=N+1;
	int D[5]={0,1,0,-1,0};
	for(int i=0;i<h;i++)for(int j=0;j<w;j++){
		tot+=a[i][j];
		int u=i*w+j;
		if(i+j&1){
			g.add_edge(u,t,1,0);
			continue;
		}
		g.add_edge(s,u,1,0);
		for(int k=0;k<4;k++){
			int y=i+D[k],x=j+D[k+1];
			if(0<=y&&y<h&&0<=x&&x<w){
				int v=y*w+x;
				g.add_edge(u,v,1,a[i][j]+a[y][x]);
			}
		}
	}
	cout<<tot-g.mincost_flow(s,t).second<<'\n';
}
