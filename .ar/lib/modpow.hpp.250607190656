template<class X,class T,class M>
X modpow(X x,T t,M m){
	x%=m;
	X y=1%m;
	while(t){if(t&1)y=y*x%m;x=x*x%m,t>>=1;}
	return y;
}
template<class Y,class X,class T,class M>
Y modpow(X x,T t,M m){return modpow(Y(x),t,m);}
