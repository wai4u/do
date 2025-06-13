---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250613_2_1.test.cpp
    title: work/lib/segtree_dual_20250613_2_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250613_2_2.test.cpp
    title: work/lib/segtree_dual_20250613_2_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"work/lib/segtree_dual_20250613_2.hpp\"\n//minimal\n//non\
    \ commutative monoid\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n,w=1,h=1;\n\tvector<T>d;\n\
    \tsegtree_dual(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());}\n\t//void _apply(int\
    \ i,T x){d[i]=op(d[i],x);}\n\t//void push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}\n\
    \tvoid push(int i){\n\t\tint l=i<<1,r=l|1;\n\t\td[l]=op(d[l],d[i]),d[r]=op(d[r],d[i]);\n\
    \t\td[i]=e();\n\t}\n\tvoid pull(int i){for(int j=h;--j;)push(i>>j);}\n\tT&operator[](int\
    \ i){pull(i+=w);return d[i];}\n\tvoid apply(int l,int r,T x){\n\t\tpull(l+=w),pull((r+=w)-1);\n\
    \t\twhile(l<r){\n\t\t\tif(l&1)d[l++]=op(d[l],x);l>>=1;\n\t\t\tif(r&1)d[r]=op(d[--r],x);r>>=1;\n\
    \t\t}\n\t}\n};\n"
  code: "//minimal\n//non commutative monoid\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n,w=1,h=1;\n\tvector<T>d;\n\
    \tsegtree_dual(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());}\n\t//void _apply(int\
    \ i,T x){d[i]=op(d[i],x);}\n\t//void push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}\n\
    \tvoid push(int i){\n\t\tint l=i<<1,r=l|1;\n\t\td[l]=op(d[l],d[i]),d[r]=op(d[r],d[i]);\n\
    \t\td[i]=e();\n\t}\n\tvoid pull(int i){for(int j=h;--j;)push(i>>j);}\n\tT&operator[](int\
    \ i){pull(i+=w);return d[i];}\n\tvoid apply(int l,int r,T x){\n\t\tpull(l+=w),pull((r+=w)-1);\n\
    \t\twhile(l<r){\n\t\t\tif(l&1)d[l++]=op(d[l],x);l>>=1;\n\t\t\tif(r&1)d[r]=op(d[--r],x);r>>=1;\n\
    \t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_dual_20250613_2.hpp
  requiredBy: []
  timestamp: '2025-06-13 19:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_dual_20250613_2_2.test.cpp
  - work/lib/segtree_dual_20250613_2_1.test.cpp
documentation_of: work/lib/segtree_dual_20250613_2.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_dual_20250613_2.hpp
- /library/work/lib/segtree_dual_20250613_2.hpp.html
title: work/lib/segtree_dual_20250613_2.hpp
---
