#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
namespace io{
constexpr int N=1<<16;
using ll=long long;
template<class T>
constexpr T ten(int k){return k?ten<T>(k-1)*10:1;}
template<class T>
constexpr bool is_128=is_same_v<T,__int128>||is_same_v<T,unsigned __int128>;
struct I:istream{
char b[N],*r=b+N,*p=r;
constexpr inline void load(int need){
	if(int d=r-p;d<need){
		d=fread(copy_n(p,d,b),1,p-b,stdin);
		p=b;
	}
}
void skip(){while(*p<=' ')++p;}
void sc(char&c){
	load(5);
	skip();
	c=*p++;
}
void sc(string&s){
	s.clear();
	load(5);
	skip();
	do{
		s+=*p++;
		load(1);
	}while(*p>' ');
	++p;
}
void sc(double&x){
	string s;
	sc(s);
	x=stod(s);
}
template<class T>
enable_if_t<is_integral_v<T>&&!is_128<T>>sc(T&x){
	load(25);
	skip();
	bool neg=0;
	if(*p=='-')neg=1,++p;
	x=0;
	bool ok=0;
	while(1){
		int d=0;
		for(int i=0;i<9;i++){
			if(*p<=' '){
				ok=1;
				if(i)x=x*ten<int>(i)+d;
				++p;
				break;
			}
			d=d*10+(*p++-'0');
		}
		if(ok)break;
		x=x*ten<int>(9)+d;
	}
	if(neg)x=-x;
}
template<class T>
enable_if_t<is_128<T>>sc(T&x){
	load(45);
	skip();
	bool neg=0;
	if(*p=='-')neg=1,++p;
	x=0;
	while(1){
		uint64_t d;
		memcpy(&d,p,8);
		d-=0x3030303030303030;
		if(d&0x8080808080808080)break;
		d=(d*10+(d>>8))&0xff00ff00ff00ff;
		d=(d*100+(d>>16))&0xffff0000ffff;
		d=(d*10000+(d>>32))&0xffffffff;
		x=x*100000000+d;
		p+=8;
	}
	int d=0,c=0;
	while(*p>' '){
		d=d*10+(*p++-'0');
		++c;
	}
	++p;
	if(c)x=x*ten<int>(c)+d;
	if(neg)x=-x;
}
template<class T,class U>
void sc(pair<T,U>&x){sc(x.first),sc(x.second);}
template<int k=0,class T>
void sc_tup(T&x){
	if constexpr(k<tuple_size<T>::value){
		sc(std::get<k>(x));
		sc_tup<k+1>(x);
	}
}
template<class...T>
void sc(tuple<T...>&x){sc_tup(x);}
template<class T>
void sc(vector<T>&a){for(T&x:a)sc(x);}
template<class T>I&operator>>(T&x){sc(x);return *this;}
}_i;
struct O:ostream{
char b[N],*r=b+N,*p=b;
constexpr inline void flush(int need=N){
	if(r-p<need){
		fwrite(b,1,p-b,stdout);
		p=b;
	}
}
~O(){flush();}
void pr(char c){
	flush(1);
	*p++=c;
}
void pr(bool x){pr(x?'1':'0');}
void pr(const char*s){
	int n=strlen(s);
	for(int i=0;i<n;i++)pr(s[i]);
}
void pr(string s){for(char c:s)pr(c);}
void pr(double x){
	ostringstream os;
	os<<setprecision(18)<<x;
	pr(os.str());
}
void pr(long double x){pr((double)x);}
static constexpr auto num=[](){
	array<array<char,4>,10000>num={};
	for(int i=10000;i--;){
		int x=i;
		for(int j=4;j--;)num[i][j]=x%10|'0',x/=10;
	}
	return num;
}();
char tmp[20];
template<class T>
enable_if_t<is_integral_v<T>&&!is_128<T>>pr(T x){
	flush(20);
	if(x<0)*p++='-',x=-x;
	int i;
	for(i=20;x>=10000;){
		i-=4;
		memcpy(tmp+i,&num[x%10000][0],4);
		x/=10000;
	}
	if(x>=1000)p=copy_n(&num[x][0],4,p);
	else if(x>=100)p=copy_n(&num[x][1],3,p);
	else if(x>=10)p=copy_n(&num[x][2],2,p);
	else *p++=x|'0';
	p=copy_n(tmp+i,20-i,p);
}
template<int k=16>
void w4(ll x){
	if constexpr(k==4){
		p=copy_n(&num[x][0],4,p);
		return;
	}else{
		p=copy_n(&num[x/ten<ll>(k-4)][0],4,p);
		w4<k-4>(x%ten<ll>(k-4));
	}
}
template<class T>
enable_if_t<is_128<T>>pr(T x){
	flush(40);
	if(x<0)*p++='-',x=-x;
	if(x<ten<T>(16))pr(static_cast<ll>(x));
	else if(x<ten<T>(32)){
		pr(static_cast<ll>(x/ten<T>(16)));
		w4(static_cast<ll>(x%ten<T>(16)));
	}else{
		pr(static_cast<int>(x/ten<T>(32)));
		x%=ten<T>(32);
		w4(static_cast<ll>(x/ten<T>(16)));
		w4(static_cast<ll>(x%ten<T>(16)));
	}
}
template<class T,class U>
void pr(pair<T,U>x){pr(x.first),pr(' '),pr(x.second);}
template<int k=0,class T>
void pr_tup(T x){
	if constexpr(k<tuple_size<T>::value){
		if constexpr(k)pr(' ');
		pr(get<k>(x));
		pr_tup<k+1>(x);
	}
}
template<class...T>
void pr(tuple<T...>x){pr_tup(x);}
template<class T>
void pr(vector<T>a){
	int n=a.size();
	for(int i=0;i<n;++i){
		if(i)pr(' ');
		pr(a[i]);
	}
}
template<class T>O&operator<<(T x){pr(x);return *this;}
}_o;
void flush(){_o.flush();}
}
using io::flush;
#define cin io::_i
#define cout io::_o
