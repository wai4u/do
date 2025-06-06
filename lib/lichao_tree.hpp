//https://github.com/yosupo06/library-checker-problems/blob/master/data_structure/line_add_get_min/sol/correct.cpp
//|x|<=10^9,|a|<=10^9,|b|<=10^18
//https://smijake3.hatenablog.com/entry/2018/06/16/144548
struct line{
	long a,b;
	long operator()(long x){return a*x+b;}
};
struct lichao_tree{
	int n,w;
	vector<int>xs;
	vector<line>f;
	bool built=0;
	void add_point(int x){
		assert(!built);
		xs.push_back(x);
	}
	void build(){
		if(built)return;
		built=1;
		sort(xs.begin(),xs.end());
		xs.erase(unique(xs.begin(),xs.end()),xs.end());
		n=xs.size(),w=1;
		while(w<n)w<<=1;
		//if(n)xs.resize(w,max_element(xs.begin(),xs.end()));
		xs.resize(w,1<<30);
		f.assign(w+w,{0,2l<<60});
	}
	void add_line(line g){
		build();
		add_line(g,0,w,1);
	}
	void add_line(line g,int l,int r,int i){
		int c=l+r>>1;
		long x=xs[c];
		if(g(x)<f[i](x))swap(g,f[i]);
		if(r-l==1)return;
		if(g.a>f[i].a)add_line(g,l,c,i<<1);
		if(g.a<f[i].a)add_line(g,c,r,i<<1|1);
	}
	long calc(long x){
		int i=lower_bound(xs.begin(),xs.end(),x)-xs.begin();
		assert(0<=i&&i<n&&xs[i]==x);
		long y=2l<<60;
		i+=w;
		while(i>=1){
			y=min(y,f[i](x));
			i>>=1;
		}
		return y;
	}
};
