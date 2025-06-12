---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/weighted_uf_20250612_1.test.cpp
    title: work/lib/weighted_uf_20250612_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"work/lib/weighted_uf_20250612_1.hpp\"\n//potential from\
    \ root\n//left operation\n//non commutative group\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\n\
    template<class T>\nstruct weighted_uf{\n\tint n=0;\n\tvector<int>d;\n\tvector<T>p;//root(u)->u\n\
    \tweighted_uf(){}\n\tweighted_uf(int n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\
    \t\td.assign(n,-1);\n\t\tp.assign(n,T{});\n\t}\n\tint root(int u){\n\t\tint v=d[u];\n\
    \t\tif(v<0)return u;\n\t\td[u]=root(v);\n\t\tp[u]+=p[v];//(p[v]\u306Bp[u]\u304C\
    \u5DE6\u4F5C\u7528)\n\t\treturn d[u];\n\t}\n\tbool same(int u,int v){return root(u)==root(v);}\n\
    \tint size(){return n;}\n\tint size(int u){return -d[root(u)];}\n\tT diff(int\
    \ u,int v){\n\t\tassert(same(u,v));\n\t\treturn p[v]-p[u];\n\t}\n\tbool valid(int\
    \ u,int v,T w){\n\t\treturn !same(u,v)||diff(u,v)==w;\n\t}\n\tbool unite(int u,int\
    \ v,T w){\n\t\tassert(valid(u,v,w));\n\t\tif(same(u,v))return 0;\n\t\tw=-p[v]+w+p[u];\n\
    \t\tu=root(u),v=root(v);\n\t\tif(d[u]>d[v])swap(u,v),w=-w;\n\t\td[u]+=d[v];\n\t\
    \td[v]=u;\n\t\tp[v]=w;\n\t\treturn 1;\n\t}\n};\n"
  code: "//potential from root\n//left operation\n//non commutative group\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\n\
    template<class T>\nstruct weighted_uf{\n\tint n=0;\n\tvector<int>d;\n\tvector<T>p;//root(u)->u\n\
    \tweighted_uf(){}\n\tweighted_uf(int n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\
    \t\td.assign(n,-1);\n\t\tp.assign(n,T{});\n\t}\n\tint root(int u){\n\t\tint v=d[u];\n\
    \t\tif(v<0)return u;\n\t\td[u]=root(v);\n\t\tp[u]+=p[v];//(p[v]\u306Bp[u]\u304C\
    \u5DE6\u4F5C\u7528)\n\t\treturn d[u];\n\t}\n\tbool same(int u,int v){return root(u)==root(v);}\n\
    \tint size(){return n;}\n\tint size(int u){return -d[root(u)];}\n\tT diff(int\
    \ u,int v){\n\t\tassert(same(u,v));\n\t\treturn p[v]-p[u];\n\t}\n\tbool valid(int\
    \ u,int v,T w){\n\t\treturn !same(u,v)||diff(u,v)==w;\n\t}\n\tbool unite(int u,int\
    \ v,T w){\n\t\tassert(valid(u,v,w));\n\t\tif(same(u,v))return 0;\n\t\tw=-p[v]+w+p[u];\n\
    \t\tu=root(u),v=root(v);\n\t\tif(d[u]>d[v])swap(u,v),w=-w;\n\t\td[u]+=d[v];\n\t\
    \td[v]=u;\n\t\tp[v]=w;\n\t\treturn 1;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/weighted_uf_20250612_1.hpp
  requiredBy: []
  timestamp: '2025-06-12 12:54:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/weighted_uf_20250612_1.test.cpp
documentation_of: work/lib/weighted_uf_20250612_1.hpp
layout: document
redirect_from:
- /library/work/lib/weighted_uf_20250612_1.hpp
- /library/work/lib/weighted_uf_20250612_1.hpp.html
title: work/lib/weighted_uf_20250612_1.hpp
---
