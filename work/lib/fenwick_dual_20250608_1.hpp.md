---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_dual_20250608_1_1.test.cpp
    title: work/lib/fenwick_dual_20250608_1_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_dual_20250608_1_2.test.cpp
    title: work/lib/fenwick_dual_20250608_1_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/291759
  bundledCode: "#line 1 \"work/lib/fenwick_dual_20250608_1.hpp\"\n//dual\n//https://judge.yosupo.jp/submission/291759\n\
    //sequence\u3067\u521D\u671F\u5316\u3059\u308B\u5834\u5408\u306F\u5024\u914D\u5217\
    \u3092\u6E21\u3059(\u5DEE\u5206\u914D\u5217\u3067\u306F\u306A\u3044)\ntemplate<class\
    \ T>\nstruct fenwick{\n\tint n=0;\n\tvector<T>d,s;\n\tbool built=0;\n\tfenwick(){}\n\
    \tfenwick(int n){init(n);}\n\ttemplate<class F>fenwick(int n,F f){init(n,f);}\n\
    \ttemplate<class U>fenwick(const vector<U>&a){init(a);}\n\tfenwick(const vector<T>&a){init(a);}\n\
    \tfenwick(int n,T x){init(n,x);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\td.assign(n,T{});\n\
    \t\tbuilt=0;\n\t}\n\ttemplate<class F>void init(int n,F f){\n\t\tinit(n);\n\t\t\
    for(int i=0;i<n;i++)d[i]=f(i);\n\t\tfor(int i=n;--i>0;)d[i]-=d[i-1];\n\t}\n\t\
    void init(int n,T x){init(n,[&](int i){return x;});}\n\ttemplate<class U>void\
    \ init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\ts=d;\n\t\tfor(int i=0;i<n;i++){\n\
    \t\t\tint j=i|i+1;\n\t\t\tif(j<n)s[j]+=s[i];\n\t\t}\n\t}\n\t//[i,n)\n\tvoid add(int\
    \ i,T x,bool upd=1){\n\t\tassert(0<=i&&i<=n);//\u5B9F\u7528\u4E0An\u3092\u542B\
    \u3081\u308B\n\t\td[i]+=x;\n\t\tif(!built||!upd){built=0;return;}\n\t\twhile(i<n)s[i]+=x,i|=i+1;\n\
    \t}\n\t//[l,r)\n\tvoid add(int l,int r,T x,bool upd=1){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tadd(l,x,upd),add(r,-x,upd);\n\t}\n\tT get(int i){\n\t\tassert(0<=i&&i<n);//-1\u306F\
    \u542B\u3081\u306A\u3044\n\t\tbuild();\n\t\tT y{};\n\t\twhile(i>=0)y+=s[i],i&=i+1,i--;\n\
    \t\treturn y;\n\t}\n\tT operator[](int i){return get(i);}\n};\n"
  code: "//dual\n//https://judge.yosupo.jp/submission/291759\n//sequence\u3067\u521D\
    \u671F\u5316\u3059\u308B\u5834\u5408\u306F\u5024\u914D\u5217\u3092\u6E21\u3059\
    (\u5DEE\u5206\u914D\u5217\u3067\u306F\u306A\u3044)\ntemplate<class T>\nstruct\
    \ fenwick{\n\tint n=0;\n\tvector<T>d,s;\n\tbool built=0;\n\tfenwick(){}\n\tfenwick(int\
    \ n){init(n);}\n\ttemplate<class F>fenwick(int n,F f){init(n,f);}\n\ttemplate<class\
    \ U>fenwick(const vector<U>&a){init(a);}\n\tfenwick(const vector<T>&a){init(a);}\n\
    \tfenwick(int n,T x){init(n,x);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\td.assign(n,T{});\n\
    \t\tbuilt=0;\n\t}\n\ttemplate<class F>void init(int n,F f){\n\t\tinit(n);\n\t\t\
    for(int i=0;i<n;i++)d[i]=f(i);\n\t\tfor(int i=n;--i>0;)d[i]-=d[i-1];\n\t}\n\t\
    void init(int n,T x){init(n,[&](int i){return x;});}\n\ttemplate<class U>void\
    \ init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\ts=d;\n\t\tfor(int i=0;i<n;i++){\n\
    \t\t\tint j=i|i+1;\n\t\t\tif(j<n)s[j]+=s[i];\n\t\t}\n\t}\n\t//[i,n)\n\tvoid add(int\
    \ i,T x,bool upd=1){\n\t\tassert(0<=i&&i<=n);//\u5B9F\u7528\u4E0An\u3092\u542B\
    \u3081\u308B\n\t\td[i]+=x;\n\t\tif(!built||!upd){built=0;return;}\n\t\twhile(i<n)s[i]+=x,i|=i+1;\n\
    \t}\n\t//[l,r)\n\tvoid add(int l,int r,T x,bool upd=1){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tadd(l,x,upd),add(r,-x,upd);\n\t}\n\tT get(int i){\n\t\tassert(0<=i&&i<n);//-1\u306F\
    \u542B\u3081\u306A\u3044\n\t\tbuild();\n\t\tT y{};\n\t\twhile(i>=0)y+=s[i],i&=i+1,i--;\n\
    \t\treturn y;\n\t}\n\tT operator[](int i){return get(i);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/fenwick_dual_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 22:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/fenwick_dual_20250608_1_1.test.cpp
  - work/lib/fenwick_dual_20250608_1_2.test.cpp
documentation_of: work/lib/fenwick_dual_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/fenwick_dual_20250608_1.hpp
- /library/work/lib/fenwick_dual_20250608_1.hpp.html
title: work/lib/fenwick_dual_20250608_1.hpp
---
