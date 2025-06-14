#include"io.hpp"
//binary search
//https://atcoder.jp/contests/practice2/submissions/66708009
//https://atcoder.jp/contests/practice2/submissions/66707994
template<class T,T(*op)(T,T),T(*e)()>
struct segtree{
	int n,w=1;
	vector<T>d;
	segtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());}
	void set(int i,T x){assert(0<=i&&i<n);d[i+=w]=x;while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}
	T operator[](int i){assert(0<=i&&i<n);return d[i+w];}
	T prod(int l,int r){
		assert(0<=l&&l<=r&&r<=n);
		l+=w,r+=w;
		T vl=e(),vr=e();
		while(l<r){
			if(l&1)vl=op(vl,d[l++]);l>>=1;
			if(r&1)vr=op(d[--r],vr);r>>=1;
		}
		return op(vl,vr);
	}
	template<class F>
	int max_right(int i,F f){
		assert(0<=i&&i<=n);
		if(i==n)return n;
		T x=e();
		i+=w;
		while(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return n;}
		while(i<w)if(f(op(x,d[i<<=1])))x=op(x,d[i++]);
		assert(i<w+n);
		return i-w;
	}
	template<class G>
	int min_left(int i,G f){
		assert(0<=i&&i<=n);
		if(i==0)return 0;
		T x=e();
		i+=w;
		if(i==1)i=2;
		while(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return 0;}
		while(i<=w)if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);
		assert(w<i&&i<=w+n);
		return i-w;
	}
};
int op(int x,int y){return max(x,y);}
int e(){return 0;}
int main(){
	int n,q;
	cin>>n>>q;
	segtree<int,op,e>seg(n);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		seg.set(i,a);
	}
	while(q--){
		int t,i,j;
		cin>>t>>i>>j;
		i--;
		if(t==1){
			seg.set(i,j);
		}
		if(t==2){
			cout<<seg.prod(i,j)<<'\n';
		}
		if(t==3){
			cout<<seg.max_right(i,[&](int x){return x<j;})+1<<'\n';
		}
	}
}
