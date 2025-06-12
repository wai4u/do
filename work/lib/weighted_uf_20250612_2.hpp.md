---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/1.cpp
    title: work/1.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/weighted_uf_20250612_2.test.cpp
    title: work/lib/weighted_uf_20250612_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/weighted_uf_20250612_2_2.test.cpp
    title: work/lib/weighted_uf_20250612_2_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/292501
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"work/lib/weighted_uf_20250612_2.hpp\"\n//non commutative\
    \ group\n//from root & right operation\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\n\
    //https://judge.yosupo.jp/submission/292501\ntemplate<class T,T(*op)(T,T),T(*e)(),T(*inv)(T)>\n\
    struct weighted_uf{\n\tint n=0;\n\tvector<int>d;\n\tvector<T>p;\n\tweighted_uf(){}\n\
    \tweighted_uf(int n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\td.assign(n,-1);\n\
    \t\tp.assign(n,e());\n\t}\n\tint root(int u){\n\t\tint v=d[u];\n\t\tif(v<0)return\
    \ u;\n\t\td[u]=root(v);\n\t\tp[u]=op(p[v],p[u]);\n\t\treturn d[u];\n\t}\n\tbool\
    \ same(int u,int v){return root(u)==root(v);}\n\tint size(){return n;}\n\tint\
    \ size(int u){return -d[root(u)];}\n\tT diff(int u,int v){\n\t\tassert(same(u,v));\n\
    \t\treturn op(inv(p[u]),p[v]);\n\t}\n\tbool valid(int u,int v,T w){\n\t\treturn\
    \ !same(u,v)||diff(u,v)==w;\n\t}\n\tbool unite(int u,int v,T w){\n\t\tassert(valid(u,v,w));\n\
    \t\tif(same(u,v))return 0;\n\t\tw=op(op(p[u],w),inv(p[v]));\n\t\tu=root(u),v=root(v);\n\
    \t\tif(d[u]>d[v])swap(u,v),w=inv(w);\n\t\td[u]+=d[v];\n\t\td[v]=u;\n\t\tp[v]=w;\n\
    \t\treturn 1;\n\t}\n};\n"
  code: "//non commutative group\n//from root & right operation\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\n\
    //https://judge.yosupo.jp/submission/292501\ntemplate<class T,T(*op)(T,T),T(*e)(),T(*inv)(T)>\n\
    struct weighted_uf{\n\tint n=0;\n\tvector<int>d;\n\tvector<T>p;\n\tweighted_uf(){}\n\
    \tweighted_uf(int n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\td.assign(n,-1);\n\
    \t\tp.assign(n,e());\n\t}\n\tint root(int u){\n\t\tint v=d[u];\n\t\tif(v<0)return\
    \ u;\n\t\td[u]=root(v);\n\t\tp[u]=op(p[v],p[u]);\n\t\treturn d[u];\n\t}\n\tbool\
    \ same(int u,int v){return root(u)==root(v);}\n\tint size(){return n;}\n\tint\
    \ size(int u){return -d[root(u)];}\n\tT diff(int u,int v){\n\t\tassert(same(u,v));\n\
    \t\treturn op(inv(p[u]),p[v]);\n\t}\n\tbool valid(int u,int v,T w){\n\t\treturn\
    \ !same(u,v)||diff(u,v)==w;\n\t}\n\tbool unite(int u,int v,T w){\n\t\tassert(valid(u,v,w));\n\
    \t\tif(same(u,v))return 0;\n\t\tw=op(op(p[u],w),inv(p[v]));\n\t\tu=root(u),v=root(v);\n\
    \t\tif(d[u]>d[v])swap(u,v),w=inv(w);\n\t\td[u]+=d[v];\n\t\td[v]=u;\n\t\tp[v]=w;\n\
    \t\treturn 1;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/weighted_uf_20250612_2.hpp
  requiredBy:
  - work/1.cpp
  timestamp: '2025-06-12 13:15:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/weighted_uf_20250612_2_2.test.cpp
  - work/lib/weighted_uf_20250612_2.test.cpp
documentation_of: work/lib/weighted_uf_20250612_2.hpp
layout: document
redirect_from:
- /library/work/lib/weighted_uf_20250612_2.hpp
- /library/work/lib/weighted_uf_20250612_2.hpp.html
title: work/lib/weighted_uf_20250612_2.hpp
---
