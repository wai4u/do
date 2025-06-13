---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/segtree_dual_20250613_1_1.test.cpp
    title: work/segtree_dual_20250613_1_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/segtree_dual_20250613_1_2.test.cpp
    title: work/segtree_dual_20250613_1_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"work/segtree_dual_20250613_1.hpp\"\n//minimal\n//commutative\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n\
    template<class T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n;\n\tvector<T>d;\n\
    \tsegtree_dual(int n):n(n),d(n+n,e()){}\n\tT operator[](int i){\n\t\tT y=d[i+=n];\n\
    \t\twhile(i>>=1)y=op(y,d[i]);\n\t\treturn y;\n\t}\n\tvoid apply(int l,int r,T\
    \ x){\n\t\tl+=n,r+=n;\n\t\twhile(l<r){\n\t\t\tif(l&1)d[l++]=op(d[l],x);l>>=1;\n\
    \t\t\tif(r&1)d[r]=op(d[--r],x);r>>=1;\n\t\t}\n\t}\n};\n"
  code: "//minimal\n//commutative\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n;\n\tvector<T>d;\n\tsegtree_dual(int\
    \ n):n(n),d(n+n,e()){}\n\tT operator[](int i){\n\t\tT y=d[i+=n];\n\t\twhile(i>>=1)y=op(y,d[i]);\n\
    \t\treturn y;\n\t}\n\tvoid apply(int l,int r,T x){\n\t\tl+=n,r+=n;\n\t\twhile(l<r){\n\
    \t\t\tif(l&1)d[l++]=op(d[l],x);l>>=1;\n\t\t\tif(r&1)d[r]=op(d[--r],x);r>>=1;\n\
    \t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/segtree_dual_20250613_1.hpp
  requiredBy: []
  timestamp: '2025-06-13 18:37:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/segtree_dual_20250613_1_1.test.cpp
  - work/segtree_dual_20250613_1_2.test.cpp
documentation_of: work/segtree_dual_20250613_1.hpp
layout: document
redirect_from:
- /library/work/segtree_dual_20250613_1.hpp
- /library/work/segtree_dual_20250613_1.hpp.html
title: work/segtree_dual_20250613_1.hpp
---
