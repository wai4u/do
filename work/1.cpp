#include"io.hpp"
//minimal
//non commutative monoid
//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
template<class X,X(*op)(X,X),X(*e)(),
class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>
struct segtree_lazy{
	int n;
	vector<X>d;
	vector<F>lz;
	segtree_lazy(int n):n(n),d(n+n,e()),lz(n,id()){}
	void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<n)lz[i]=composition(f,lz[i]);}
	void push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}
	void pull(int i){if(i)for(int j=(32-__builtin_clz(i));--j;)push(i>>j);}
	void upd(int i){while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}
	X operator[](int i){pull(i+=n);return d[i];}
	void set(int i,X x){pull(i+=n),d[i]=x,upd(i);}
	void apply(int l,int r,F f){
		l+=n,r+=n;int L=l/(l&-l),R=r/(r&-r)-1;
		pull(L),pull(R);
		while(l<r){
			if(l&1)_apply(l++,f);l>>=1;
			if(r&1)_apply(--r,f);r>>=1;
		}
		upd(L),upd(R);
	}
	X prod(int l,int r){
		l+=n,r+=n;
		pull(l/(l&-l)),pull(r/(r&-r)-1);
		X vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
};
int op(int x,int y){return min(x,y);}
int e(){return(1l<<31)-1;}
int mapping(int f,int x){return f==-1?x:f;}
int composition(int f,int g){return f==-1?g:f;}
int id(){return -1;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree_lazy<int,op,e,int,mapping,composition,id>seg(n+1);
	while(q--){
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0){
			int x;
			cin>>x;
			seg.apply(l,r+1,x);
		}else{
			cout<<seg.prod(l,r+1)<<'\n';
		}
	}
}
