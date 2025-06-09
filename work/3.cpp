#include"io.hpp"
#include"union_find.hpp"
int main(){
	int h,w;
	cin>>h>>w;
	union_find uf(h*w);
	vector<string>s(h);
	for(int i=0;i<h;i++)cin>>s[i];
	int c=0;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)if(s[i][j]=='#'){
		c++;
		for(int dy=-1;dy<=1;dy++)for(int dx=-1;dx<=1;dx++){
			if(dx==0&&dy==0)continue;
			int y=i+dy,x=j+dx;
			if(0<=y&&y<h&&0<=x&&x<w&&s[y][x]=='#'){
				c-=uf.unite(i*w+j,y*w+x);
			}
		}
	}
	cout<<c<<'\n';
}
