---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_primal_20250608_1_1.test.cpp
    title: work/lib/fenwick_primal_20250608_1_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_primal_20250608_1_2.test.cpp
    title: work/lib/fenwick_primal_20250608_1_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_primal_20250608_1_3.test.cpp
    title: work/lib/fenwick_primal_20250608_1_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_primal_20250608_1_4.test.cpp
    title: work/lib/fenwick_primal_20250608_1_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_primal_20250608_1_5.test.cpp
    title: work/lib/fenwick_primal_20250608_1_5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/291730
  bundledCode: "#line 1 \"work/lib/fenwick_primal_20250608_1.hpp\"\n//primal\n//internally\
    \ 1-indexed\n//https://judge.yosupo.jp/submission/291730\ntemplate<class T>\n\
    struct fenwick{\n\tint n=0;\n\tvector<T>a,s;\n\tbool built=0;\n\tfenwick(){}\n\
    \tfenwick(int n){init(n);}\n\ttemplate<class F>fenwick(int n,F f){init(n,f);}\n\
    \ttemplate<class U>fenwick(const vector<U>&a){init(a);}\n\tfenwick(const vector<T>&a){init(a);}\n\
    \tvoid assign(int n,T x){\n\t\tthis->n=n;\n\t\ta.assign(n,x);\n\t\tbuilt=0;\n\t\
    }\n\tvoid init(int n){assign(n,T{});}\n\ttemplate<class F>void init(int n,F f){\n\
    \t\tinit(n);\n\t\tfor(int i=0;i<n;i++)a[i]=f(i);\n\t}\n\ttemplate<class U>void\
    \ init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\ts.assign(n+1,T{});\n\t\
    \tfor(int i=1;i<=n;i++){\n\t\t\ts[i]+=a[i-1];\n\t\t\tint j=i+(i&-i);\n\t\t\tif(j<=n)s[j]+=s[i];\n\
    \t\t}\n\t}\n\tvoid add(int i,T x,bool upd=1){\n\t\tassert(0<=i&&i<n);//\u5225\u306B\
    check\u3057\u306A\u304F\u3066\u3082\u30C7\u30FC\u30BF\u304C\u5B58\u5728\u3059\u308C\
    \u3070\u8DB3\u3059\u3068\u6349\u3048\u308C\u3070\u3044\u3044\u304C\u3001\u5B9F\
    \u88C5\u30DF\u30B9\u6C17\u3065\u304D\u3084\u3059\u304F\u3059\u308B\n\t\ta[i]+=x;\n\
    \t\tif(!built||!upd){built=0;return;}\n\t\ti++;\n\t\twhile(i<=n)s[i]+=x,i+=i&-i;\n\
    \t}\n\tvoid set(int i,T x,bool upd=1){\n\t\tassert(0<=i&&i<n);\n\t\tif(built&&upd)add(i,x-a[i],1);\n\
    \t\telse a[i]=x,built=0;\n\t}\n\tconst T&get(int i){\n\t\tassert(0<=i&&i<n);\n\
    \t\treturn a[i];\n\t}\n\t//operator[]\u306Fa[i]\u304Bs[i]\u304B\u66D6\u6627\u3060\
    \u304B\u3089\u3042\u3048\u3066\u3064\u3051\u306A\u3044\u3002\n\tT sum(int i){\n\
    \t\tassert(0<=i&&i<=n);\n\t\tbuild();\n\t\tT y{};\n\t\twhile(i>0)y+=s[i],i-=i&-i;\n\
    \t\treturn y;\n\t}\n\tT sum(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\t\
    return sum(r)-sum(l);\n\t}\n};\n"
  code: "//primal\n//internally 1-indexed\n//https://judge.yosupo.jp/submission/291730\n\
    template<class T>\nstruct fenwick{\n\tint n=0;\n\tvector<T>a,s;\n\tbool built=0;\n\
    \tfenwick(){}\n\tfenwick(int n){init(n);}\n\ttemplate<class F>fenwick(int n,F\
    \ f){init(n,f);}\n\ttemplate<class U>fenwick(const vector<U>&a){init(a);}\n\t\
    fenwick(const vector<T>&a){init(a);}\n\tvoid assign(int n,T x){\n\t\tthis->n=n;\n\
    \t\ta.assign(n,x);\n\t\tbuilt=0;\n\t}\n\tvoid init(int n){assign(n,T{});}\n\t\
    template<class F>void init(int n,F f){\n\t\tinit(n);\n\t\tfor(int i=0;i<n;i++)a[i]=f(i);\n\
    \t}\n\ttemplate<class U>void init(const vector<U>&a){\n\t\tinit(a.size(),[&](int\
    \ i){return a[i];});\n\t}\n\tvoid build(){\n\t\tif(built)return;\n\t\tbuilt=1;\n\
    \t\ts.assign(n+1,T{});\n\t\tfor(int i=1;i<=n;i++){\n\t\t\ts[i]+=a[i-1];\n\t\t\t\
    int j=i+(i&-i);\n\t\t\tif(j<=n)s[j]+=s[i];\n\t\t}\n\t}\n\tvoid add(int i,T x,bool\
    \ upd=1){\n\t\tassert(0<=i&&i<n);//\u5225\u306Bcheck\u3057\u306A\u304F\u3066\u3082\
    \u30C7\u30FC\u30BF\u304C\u5B58\u5728\u3059\u308C\u3070\u8DB3\u3059\u3068\u6349\
    \u3048\u308C\u3070\u3044\u3044\u304C\u3001\u5B9F\u88C5\u30DF\u30B9\u6C17\u3065\
    \u304D\u3084\u3059\u304F\u3059\u308B\n\t\ta[i]+=x;\n\t\tif(!built||!upd){built=0;return;}\n\
    \t\ti++;\n\t\twhile(i<=n)s[i]+=x,i+=i&-i;\n\t}\n\tvoid set(int i,T x,bool upd=1){\n\
    \t\tassert(0<=i&&i<n);\n\t\tif(built&&upd)add(i,x-a[i],1);\n\t\telse a[i]=x,built=0;\n\
    \t}\n\tconst T&get(int i){\n\t\tassert(0<=i&&i<n);\n\t\treturn a[i];\n\t}\n\t\
    //operator[]\u306Fa[i]\u304Bs[i]\u304B\u66D6\u6627\u3060\u304B\u3089\u3042\u3048\
    \u3066\u3064\u3051\u306A\u3044\u3002\n\tT sum(int i){\n\t\tassert(0<=i&&i<=n);\n\
    \t\tbuild();\n\t\tT y{};\n\t\twhile(i>0)y+=s[i],i-=i&-i;\n\t\treturn y;\n\t}\n\
    \tT sum(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\treturn sum(r)-sum(l);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/fenwick_primal_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 19:42:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/fenwick_primal_20250608_1_3.test.cpp
  - work/lib/fenwick_primal_20250608_1_1.test.cpp
  - work/lib/fenwick_primal_20250608_1_2.test.cpp
  - work/lib/fenwick_primal_20250608_1_5.test.cpp
  - work/lib/fenwick_primal_20250608_1_4.test.cpp
documentation_of: work/lib/fenwick_primal_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/fenwick_primal_20250608_1.hpp
- /library/work/lib/fenwick_primal_20250608_1.hpp.html
title: work/lib/fenwick_primal_20250608_1.hpp
---
