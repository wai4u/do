---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250614_1_1.test.cpp
    title: work/lib/segtree_dual_20250614_1_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250614_1_2.test.cpp
    title: work/lib/segtree_dual_20250614_1_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"work/lib/segtree_dual_20250614_1.hpp\"\n//recursive\n//minimal\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n\
    template<class T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n,w=1,h=1;\n\
    \tvector<T>d;\n\tsegtree_dual(int n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e());}\n\
    \t//void push(int i){d[i<<1]=op(d[i<<1],d[i]),d[i<<1|1]=op(d[i<<1|1],d[i]),d[i]=e();}\n\
    \tvoid _apply(int i,T x){d[i]=op(d[i],x);}\n\tvoid push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}\n\
    \tT&operator[](int i){i+=w;for(int j=h;--j;)push(i>>j);return d[i];}\n\tvoid apply(int\
    \ l,int r,T x){apply(l,r,x,1,0,w);}\n\tvoid apply(int L,int R,const T&x,int i,int\
    \ l,int r){\n\t\tif(r<=L||R<=l)return;\n\t\t//if(L<=l&&r<=R){d[i]=op(d[i],x);return;}\n\
    \t\tif(L<=l&&r<=R)return _apply(i,x);\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tapply(L,R,x,i<<1,l,c),apply(L,R,x,i<<1|1,c,r);\n\
    \t}\n};\n"
  code: "//recursive\n//minimal\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n,w=1,h=1;\n\tvector<T>d;\n\
    \tsegtree_dual(int n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e());}\n\t//void push(int\
    \ i){d[i<<1]=op(d[i<<1],d[i]),d[i<<1|1]=op(d[i<<1|1],d[i]),d[i]=e();}\n\tvoid\
    \ _apply(int i,T x){d[i]=op(d[i],x);}\n\tvoid push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}\n\
    \tT&operator[](int i){i+=w;for(int j=h;--j;)push(i>>j);return d[i];}\n\tvoid apply(int\
    \ l,int r,T x){apply(l,r,x,1,0,w);}\n\tvoid apply(int L,int R,const T&x,int i,int\
    \ l,int r){\n\t\tif(r<=L||R<=l)return;\n\t\t//if(L<=l&&r<=R){d[i]=op(d[i],x);return;}\n\
    \t\tif(L<=l&&r<=R)return _apply(i,x);\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tapply(L,R,x,i<<1,l,c),apply(L,R,x,i<<1|1,c,r);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_dual_20250614_1.hpp
  requiredBy: []
  timestamp: '2025-06-14 07:06:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_dual_20250614_1_1.test.cpp
  - work/lib/segtree_dual_20250614_1_2.test.cpp
documentation_of: work/lib/segtree_dual_20250614_1.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_dual_20250614_1.hpp
- /library/work/lib/segtree_dual_20250614_1.hpp.html
title: work/lib/segtree_dual_20250614_1.hpp
---
