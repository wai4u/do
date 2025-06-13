---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_5_1.test.cpp
    title: work/lib/segtree_lazy_20250614_5_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_5_2.test.cpp
    title: work/lib/segtree_lazy_20250614_5_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_5_3.test.cpp
    title: work/lib/segtree_lazy_20250614_5_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_5_4.test.cpp
    title: work/lib/segtree_lazy_20250614_5_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_5_5.test.cpp
    title: work/lib/segtree_lazy_20250614_5_5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250614_5.hpp\"\n//recursive\n//minimal\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n\
    template<class X,X(*op)(X,X),X(*e)(),class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\n\
    struct segtree_lazy{\n\tint n,w=1,h=1;\n\tvector<X>d;vector<F>lz;\n\tsegtree_lazy(int\
    \ n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e()),lz.assign(w,id());}\n\tvoid _apply(int\
    \ i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tX operator[](int i){i+=w;for(int j=h;--j;)push(i>>j);return d[i];}\n\tvoid set(int\
    \ i,X x){set(i,x,1,0,w);}\n\tvoid set(int i,const X&x,int j,int l,int r){\n\t\t\
    if(j>=w){d[j]=x;return;}\n\t\tpush(j);\n\t\tint c=l+r>>1;\n\t\tif(i<c)set(i,x,j<<1,l,c);\n\
    \t\telse set(i,x,j<<1|1,c,r);\n\t\tmerge(j);\n\t}\n\tvoid apply(int l,int r,F\
    \ f){apply(l,r,f,1,0,w);}\n\tvoid apply(int L,int R,const F&f,int i,int l,int\
    \ r){\n\t\tif(r<=L||R<=l)return;\n\t\tif(L<=l&&r<=R)return _apply(i,f);\n\t\t\
    int c=l+r>>1;\n\t\tpush(i);\n\t\tapply(L,R,f,i<<1,l,c),apply(L,R,f,i<<1|1,c,r);\n\
    \t\tmerge(i);\n\t}\n\tX prod(int l,int r){return prod(l,r,1,0,w);}\n\tX prod(int\
    \ L,int R,int i,int l,int r){\n\t\tif(r<=L||R<=l)return e();\n\t\tif(L<=l&&r<=R)return\
    \ d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\treturn op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));\n\
    \t}\n};\n"
  code: "//recursive\n//minimal\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\ntemplate<class\
    \ X,X(*op)(X,X),X(*e)(),class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\n\
    struct segtree_lazy{\n\tint n,w=1,h=1;\n\tvector<X>d;vector<F>lz;\n\tsegtree_lazy(int\
    \ n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e()),lz.assign(w,id());}\n\tvoid _apply(int\
    \ i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tX operator[](int i){i+=w;for(int j=h;--j;)push(i>>j);return d[i];}\n\tvoid set(int\
    \ i,X x){set(i,x,1,0,w);}\n\tvoid set(int i,const X&x,int j,int l,int r){\n\t\t\
    if(j>=w){d[j]=x;return;}\n\t\tpush(j);\n\t\tint c=l+r>>1;\n\t\tif(i<c)set(i,x,j<<1,l,c);\n\
    \t\telse set(i,x,j<<1|1,c,r);\n\t\tmerge(j);\n\t}\n\tvoid apply(int l,int r,F\
    \ f){apply(l,r,f,1,0,w);}\n\tvoid apply(int L,int R,const F&f,int i,int l,int\
    \ r){\n\t\tif(r<=L||R<=l)return;\n\t\tif(L<=l&&r<=R)return _apply(i,f);\n\t\t\
    int c=l+r>>1;\n\t\tpush(i);\n\t\tapply(L,R,f,i<<1,l,c),apply(L,R,f,i<<1|1,c,r);\n\
    \t\tmerge(i);\n\t}\n\tX prod(int l,int r){return prod(l,r,1,0,w);}\n\tX prod(int\
    \ L,int R,int i,int l,int r){\n\t\tif(r<=L||R<=l)return e();\n\t\tif(L<=l&&r<=R)return\
    \ d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\treturn op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250614_5.hpp
  requiredBy: []
  timestamp: '2025-06-14 07:33:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250614_5_3.test.cpp
  - work/lib/segtree_lazy_20250614_5_4.test.cpp
  - work/lib/segtree_lazy_20250614_5_1.test.cpp
  - work/lib/segtree_lazy_20250614_5_5.test.cpp
  - work/lib/segtree_lazy_20250614_5_2.test.cpp
documentation_of: work/lib/segtree_lazy_20250614_5.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250614_5.hpp
- /library/work/lib/segtree_lazy_20250614_5.hpp.html
title: work/lib/segtree_lazy_20250614_5.hpp
---
