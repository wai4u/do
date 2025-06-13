---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: work/lib/io_20250608_1.hpp
    title: work/lib/io_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/optimize_20250608_1.hpp
    title: work/lib/optimize_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1.hpp
    title: work/lib/segtree_lazy_20250612_1.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250612_1_4.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n#line\
    \ 1 \"work/lib/optimize_20250608_1.hpp\"\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n#line 2 \"work/lib/io_20250608_1.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nnamespace io{\nconstexpr int N=1<<16;\nusing ll=long long;\ntemplate<class\
    \ T>\nconstexpr T ten(int k){return k?ten<T>(k-1)*10:1;}\ntemplate<class T>\n\
    constexpr bool is_128=is_same_v<T,__int128>||is_same_v<T,unsigned __int128>;\n\
    struct I:istream{\nchar b[N],*r=b+N,*p=r;\nconstexpr inline void load(int need){\n\
    \tif(int d=r-p;d<need){\n\t\td=fread(copy_n(p,d,b),1,p-b,stdin);\n\t\tp=b;\n\t\
    }\n}\nvoid skip(){while(*p<=' ')++p;}\nvoid sc(char&c){\n\tload(5);\n\tskip();\n\
    \tc=*p++;\n}\nvoid sc(string&s){\n\ts.clear();\n\tload(5);\n\tskip();\n\tdo{\n\
    \t\ts+=*p++;\n\t\tload(1);\n\t}while(*p>' ');\n\t++p;\n}\nvoid sc(double&x){\n\
    \tstring s;\n\tsc(s);\n\tx=stod(s);\n}\ntemplate<class T>\nenable_if_t<is_integral_v<T>&&!is_128<T>>sc(T&x){\n\
    \tload(25);\n\tskip();\n\tbool neg=0;\n\tif(*p=='-')neg=1,++p;\n\tx=0;\n\tbool\
    \ ok=0;\n\twhile(1){\n\t\tint d=0;\n\t\tfor(int i=0;i<9;i++){\n\t\t\tif(*p<='\
    \ '){\n\t\t\t\tok=1;\n\t\t\t\tif(i)x=x*ten<int>(i)+d;\n\t\t\t\t++p;\n\t\t\t\t\
    break;\n\t\t\t}\n\t\t\td=d*10+(*p++-'0');\n\t\t}\n\t\tif(ok)break;\n\t\tx=x*ten<int>(9)+d;\n\
    \t}\n\tif(neg)x=-x;\n}\ntemplate<class T>\nenable_if_t<is_128<T>>sc(T&x){\n\t\
    load(45);\n\tskip();\n\tbool neg=0;\n\tif(*p=='-')neg=1,++p;\n\tx=0;\n\twhile(1){\n\
    \t\tuint64_t d;\n\t\tmemcpy(&d,p,8);\n\t\td-=0x3030303030303030;\n\t\tif(d&0x8080808080808080)break;\n\
    \t\td=(d*10+(d>>8))&0xff00ff00ff00ff;\n\t\td=(d*100+(d>>16))&0xffff0000ffff;\n\
    \t\td=(d*10000+(d>>32))&0xffffffff;\n\t\tx=x*100000000+d;\n\t\tp+=8;\n\t}\n\t\
    int d=0,c=0;\n\twhile(*p>' '){\n\t\td=d*10+(*p++-'0');\n\t\t++c;\n\t}\n\t++p;\n\
    \tif(c)x=x*ten<int>(c)+d;\n\tif(neg)x=-x;\n}\ntemplate<class T,class U>\nvoid\
    \ sc(pair<T,U>&x){sc(x.first),sc(x.second);}\ntemplate<int k=0,class T>\nvoid\
    \ sc_tup(T&x){\n\tif constexpr(k<tuple_size<T>::value){\n\t\tsc(std::get<k>(x));\n\
    \t\tsc_tup<k+1>(x);\n\t}\n}\ntemplate<class...T>\nvoid sc(tuple<T...>&x){sc_tup(x);}\n\
    template<class T>\nvoid sc(vector<T>&a){for(T&x:a)sc(x);}\ntemplate<class T>I&operator>>(T&x){sc(x);return\
    \ *this;}\n}_i;\nstruct O:ostream{\nchar b[N],*r=b+N,*p=b;\nconstexpr inline void\
    \ flush(int need=N){\n\tif(r-p<need){\n\t\tfwrite(b,1,p-b,stdout);\n\t\tp=b;\n\
    \t}\n}\n~O(){flush();}\nvoid pr(char c){\n\tflush(1);\n\t*p++=c;\n}\nvoid pr(bool\
    \ x){pr(x?'1':'0');}\nvoid pr(const char*s){\n\tint n=strlen(s);\n\tfor(int i=0;i<n;i++)pr(s[i]);\n\
    }\nvoid pr(string s){for(char c:s)pr(c);}\nvoid pr(double x){\n\tostringstream\
    \ os;\n\tos<<setprecision(18)<<x;\n\tpr(os.str());\n}\nvoid pr(long double x){pr((double)x);}\n\
    static constexpr auto num=[](){\n\tarray<array<char,4>,10000>num={};\n\tfor(int\
    \ i=10000;i--;){\n\t\tint x=i;\n\t\tfor(int j=4;j--;)num[i][j]=x%10|'0',x/=10;\n\
    \t}\n\treturn num;\n}();\nchar tmp[20];\ntemplate<class T>\nenable_if_t<is_integral_v<T>&&!is_128<T>>pr(T\
    \ x){\n\tflush(20);\n\tif(x<0)*p++='-',x=-x;\n\tint i;\n\tfor(i=20;x>=10000;){\n\
    \t\ti-=4;\n\t\tmemcpy(tmp+i,&num[x%10000][0],4);\n\t\tx/=10000;\n\t}\n\tif(x>=1000)p=copy_n(&num[x][0],4,p);\n\
    \telse if(x>=100)p=copy_n(&num[x][1],3,p);\n\telse if(x>=10)p=copy_n(&num[x][2],2,p);\n\
    \telse *p++=x|'0';\n\tp=copy_n(tmp+i,20-i,p);\n}\ntemplate<int k=16>\nvoid w4(ll\
    \ x){\n\tif constexpr(k==4){\n\t\tp=copy_n(&num[x][0],4,p);\n\t\treturn;\n\t}else{\n\
    \t\tp=copy_n(&num[x/ten<ll>(k-4)][0],4,p);\n\t\tw4<k-4>(x%ten<ll>(k-4));\n\t}\n\
    }\ntemplate<class T>\nenable_if_t<is_128<T>>pr(T x){\n\tflush(40);\n\tif(x<0)*p++='-',x=-x;\n\
    \tif(x<ten<T>(16))pr(static_cast<ll>(x));\n\telse if(x<ten<T>(32)){\n\t\tpr(static_cast<ll>(x/ten<T>(16)));\n\
    \t\tw4(static_cast<ll>(x%ten<T>(16)));\n\t}else{\n\t\tpr(static_cast<int>(x/ten<T>(32)));\n\
    \t\tx%=ten<T>(32);\n\t\tw4(static_cast<ll>(x/ten<T>(16)));\n\t\tw4(static_cast<ll>(x%ten<T>(16)));\n\
    \t}\n}\ntemplate<class T,class U>\nvoid pr(pair<T,U>x){pr(x.first),pr(' '),pr(x.second);}\n\
    template<int k=0,class T>\nvoid pr_tup(T x){\n\tif constexpr(k<tuple_size<T>::value){\n\
    \t\tif constexpr(k)pr(' ');\n\t\tpr(get<k>(x));\n\t\tpr_tup<k+1>(x);\n\t}\n}\n\
    template<class...T>\nvoid pr(tuple<T...>x){pr_tup(x);}\ntemplate<class T>\nvoid\
    \ pr(vector<T>a){\n\tint n=a.size();\n\tfor(int i=0;i<n;++i){\n\t\tif(i)pr(' ');\n\
    \t\tpr(a[i]);\n\t}\n}\ntemplate<class T>O&operator<<(T x){pr(x);return *this;}\n\
    }_o;\nvoid flush(){_o.flush();}\n}\nusing io::flush;\n#define cin io::_i\n#define\
    \ cout io::_o\n#line 1 \"work/lib/segtree_lazy_20250612_1.hpp\"\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n//https://atcoder.jp/contests/practice2/submissions/66685138\n\
    template<\nclass X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,\nF(*composition)(F,F)=op,F(*id)()=e\n\
    >\nstruct segtree_lazy{\n\tint n=0,w=0;\n\tvector<X>d;\n\tvector<F>lz;\n\tbool\
    \ built=0,hung=0;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\ttemplate<class\
    \ G>\n\tsegtree_lazy(int n,G f){init(n,f);}\n\ttemplate<class U>\n\tsegtree_lazy(const\
    \ vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\tw=1;while(w<n)w<<=1;\n\
    \t\td.assign(w+w,e());\n\t\tlz.assign(w,id());\n\t\thung=built=0;\n\t}\n\ttemplate<class\
    \ G>\n\tvoid init(int n,G f){\n\t\tinit(n);\n\t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\
    \t}\n\ttemplate<class U>\n\tvoid init(const vector<U>&a){\n\t\tinit(a.size(),[&](int\
    \ i){return a[i];});\n\t}\n\tvoid _apply(int i,F f){\n\t\t//d[i]=mapping(f,d[i]);\n\
    \t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){\n\t\t_apply(i<<1,lz[i]);\n\t\t_apply(i<<1|1,lz[i]);\n\
    \t\tlz[i]=id();\n\t}\n\tvoid pull(int i){\n\t\tif(!i)return;\n\t\tfor(int j=(32-__builtin_clz(i));--j;)push(i>>j);\n\
    \t}\n\tvoid update_all(){\n\t\tif(!hung)return;\n\t\thung=0;\n\t\tfor(int i=1;i<w;i++)push(i);\n\
    \t}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){while(i>>=1)merge(i);}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tif(hung)update_all();\n\t\tbuilt=1;\n\
    \t\tfor(int i=w;--i;)merge(i);\n\t\t/*\n\t\tbuilt=1;\n\t\tfor(int i=w;--i;){\n\
    \t\t\tmerge(i);\n\t\t\td[i]=mapping(lz[i],d[i]);\n\t\t}\n\t\t*/\n\t}\n\tconst\
    \ X&get(int i){\n\t\tassert(0<=i&&i<n);\n\t\ti+=w;\n\t\tif(hung)pull(i);\n\t\t\
    return d[i];\n\t}\n\tconst X&operator[](int i){return get(i);}\n\tvector<X>get_all(){\n\
    \t\tupdate_all();\n\t\treturn{d.begin()+w,d.begin()+w+n};\n\t}\n\tvoid set(int\
    \ i,X x){\n\t\tget(i);\n\t\td[i+w]=x;\n\t\tif(built)upd(i+w);\n\t}\n\tvoid apply(int\
    \ i,F f){\n\t\tget(i);\n\t\t_apply(i+w,f);\n\t\tif(built)upd(i+w);\n\t}\n\tvoid\
    \ apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\
    \t\tif(l+1==r)return apply(l,f);\n\t\tl+=w,r+=w;\n\t\tint L=l/(l&-l),R=r/(r&-r)-1;\n\
    \t\tif(hung)pull(L),pull(R);\n\t\thung=1;\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);\n\
    \t\t\tif(r&1)_apply(--r,f);\n\t\t\tl>>=1,r>>=1;\n\t\t}\n\t\tif(built)upd(L),upd(R);\n\
    \t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return\
    \ e();\n\t\tif(l+1==r)return get(l);\n\t\tl+=w,r+=w;\n\t\tbuild();\n\t\tif(hung)pull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);\n\t\t\t\
    if(r&1)vr=op(d[--r],vr);\n\t\t\tl>>=1,r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t\
    }\n};\n#line 4 \"work/lib/segtree_lazy_20250612_1_4.test.cpp\"\nint op(int x,int\
    \ y){return x==-1?y:x;}\nint e(){return -1;}\nint main(){\n\tint n,q;\n\tcin>>n>>q;\n\
    \tsegtree_lazy<int,op,e>seg(n);\n\tfor(int i=0;i<n;i++)seg.set(i,(1l<<31)-1);\n\
    \twhile(q--){\n\t\tint t;\n\t\tcin>>t;\n\t\tif(t==0){\n\t\t\tint l,r,x;\n\t\t\t\
    cin>>l>>r>>x;\n\t\t\tseg.apply(l,r+1,x);\n\t\t}else{\n\t\t\tint i;\n\t\t\tcin>>i;\n\
    \t\t\tcout<<seg[i]<<'\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include\"io_20250608_1.hpp\"\n#include\"segtree_lazy_20250612_1.hpp\"\nint\
    \ op(int x,int y){return x==-1?y:x;}\nint e(){return -1;}\nint main(){\n\tint\
    \ n,q;\n\tcin>>n>>q;\n\tsegtree_lazy<int,op,e>seg(n);\n\tfor(int i=0;i<n;i++)seg.set(i,(1l<<31)-1);\n\
    \twhile(q--){\n\t\tint t;\n\t\tcin>>t;\n\t\tif(t==0){\n\t\t\tint l,r,x;\n\t\t\t\
    cin>>l>>r>>x;\n\t\t\tseg.apply(l,r+1,x);\n\t\t}else{\n\t\t\tint i;\n\t\t\tcin>>i;\n\
    \t\t\tcout<<seg[i]<<'\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - work/lib/io_20250608_1.hpp
  - work/lib/optimize_20250608_1.hpp
  - work/lib/segtree_lazy_20250612_1.hpp
  isVerificationFile: true
  path: work/lib/segtree_lazy_20250612_1_4.test.cpp
  requiredBy: []
  timestamp: '2025-06-13 09:18:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: work/lib/segtree_lazy_20250612_1_4.test.cpp
layout: document
redirect_from:
- /verify/work/lib/segtree_lazy_20250612_1_4.test.cpp
- /verify/work/lib/segtree_lazy_20250612_1_4.test.cpp.html
title: work/lib/segtree_lazy_20250612_1_4.test.cpp
---
