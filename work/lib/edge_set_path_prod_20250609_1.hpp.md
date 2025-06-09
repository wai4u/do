---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_bit.hpp
    title: atcoder/internal_bit.hpp
  - icon: ':warning:'
    path: atcoder/segtree.hpp
    title: atcoder/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc294/submissions/66630811
  bundledCode: "#line 1 \"work/lib/edge_set_path_prod_20250609_1.hpp\"\n//euler tour\n\
    //non commutative group\n//https://atcoder.jp/contests/abc294/submissions/66630811\n\
    #include<atcoder/segtree>\ntemplate<class T,T(*op)(T,T),T(*e)(),T(*inv)(T)>\n\
    struct edge_set_path_prod{\n\tint n,m=0;\n\tvector<vector<tuple<int,int,T>>>g;\n\
    \tbool built=0;\n\tvector<int>L,R,ev;\n\tstatic int lop(int x,int y){return min(x,y);}\n\
    \tstatic int loe(){return 1e9;}\n\tstatic T opr(T x,T y){return op(y,x);}\n\t\
    atcoder::segtree<int,lop,loe>low;\n\tatcoder::segtree<T,op,e>sl;\n\tatcoder::segtree<T,opr,e>sr;\n\
    \tedge_set_path_prod(int n):n(n),g(n),low(n+n-1),sl(n+n),sr(n+n),L(n),R(n),ev(n-1){}\n\
    \tvoid add_edge(int u,int v,T w,int id=-1){\n\t\tif(id==-1)id=m;\n\t\tassert(0<=id&&id<n-1);\n\
    \t\tg[u].emplace_back(id,v,w);\n\t\tg[v].emplace_back(id,u,w);\n\t\tm++;\n\t}\n\
    \tvoid build(){\n\t\tassert(m==n-1);\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\t\
    int k=0;\n\t\tdfs(0,-1,k);\n\t\tassert(k==n+n);\n\t}\n\tvoid dfs(int u,int p,int&k){\n\
    \t\tlow.set(k,k);\n\t\tL[u]=k++;\n\t\tfor(auto[i,v,w]:g[u])if(v!=p){\n\t\t\tev[i]=v;\n\
    \t\t\tsl.set(k,w),sr.set(k,w);\n\t\t\tdfs(v,u,k);\n\t\t\tsl.set(k-1,inv(w)),sr.set(k-1,inv(w));\n\
    \t\t\tlow.set(k-1,L[u]);\n\t\t}\n\t\tR[u]=k++;\n\t}\n\tvoid set(int i,T x){\n\t\
    \tassert(0<=i&&i<m);\n\t\tbuild();\n\t\tint l=L[ev[i]],r=R[ev[i]];\n\t\tsl.set(l,x),sl.set(r,inv(x));\n\
    \t\tsr.set(l,x),sr.set(r,inv(x));\n\t}\n\tT prod(int u,int v){\n\t\tassert(0<=u&&u<n&&0<=v&&v<n);\n\
    \t\tbuild();\n\t\tint l=low.prod(min(L[u],L[v]),max(L[u],L[v])+1)+1;\n\t\treturn\
    \ op(sr.prod(l,L[u]+1),sl.prod(l,L[v]+1));\n\t}\n};\n"
  code: "//euler tour\n//non commutative group\n//https://atcoder.jp/contests/abc294/submissions/66630811\n\
    #include<atcoder/segtree>\ntemplate<class T,T(*op)(T,T),T(*e)(),T(*inv)(T)>\n\
    struct edge_set_path_prod{\n\tint n,m=0;\n\tvector<vector<tuple<int,int,T>>>g;\n\
    \tbool built=0;\n\tvector<int>L,R,ev;\n\tstatic int lop(int x,int y){return min(x,y);}\n\
    \tstatic int loe(){return 1e9;}\n\tstatic T opr(T x,T y){return op(y,x);}\n\t\
    atcoder::segtree<int,lop,loe>low;\n\tatcoder::segtree<T,op,e>sl;\n\tatcoder::segtree<T,opr,e>sr;\n\
    \tedge_set_path_prod(int n):n(n),g(n),low(n+n-1),sl(n+n),sr(n+n),L(n),R(n),ev(n-1){}\n\
    \tvoid add_edge(int u,int v,T w,int id=-1){\n\t\tif(id==-1)id=m;\n\t\tassert(0<=id&&id<n-1);\n\
    \t\tg[u].emplace_back(id,v,w);\n\t\tg[v].emplace_back(id,u,w);\n\t\tm++;\n\t}\n\
    \tvoid build(){\n\t\tassert(m==n-1);\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\t\
    int k=0;\n\t\tdfs(0,-1,k);\n\t\tassert(k==n+n);\n\t}\n\tvoid dfs(int u,int p,int&k){\n\
    \t\tlow.set(k,k);\n\t\tL[u]=k++;\n\t\tfor(auto[i,v,w]:g[u])if(v!=p){\n\t\t\tev[i]=v;\n\
    \t\t\tsl.set(k,w),sr.set(k,w);\n\t\t\tdfs(v,u,k);\n\t\t\tsl.set(k-1,inv(w)),sr.set(k-1,inv(w));\n\
    \t\t\tlow.set(k-1,L[u]);\n\t\t}\n\t\tR[u]=k++;\n\t}\n\tvoid set(int i,T x){\n\t\
    \tassert(0<=i&&i<m);\n\t\tbuild();\n\t\tint l=L[ev[i]],r=R[ev[i]];\n\t\tsl.set(l,x),sl.set(r,inv(x));\n\
    \t\tsr.set(l,x),sr.set(r,inv(x));\n\t}\n\tT prod(int u,int v){\n\t\tassert(0<=u&&u<n&&0<=v&&v<n);\n\
    \t\tbuild();\n\t\tint l=low.prod(min(L[u],L[v]),max(L[u],L[v])+1)+1;\n\t\treturn\
    \ op(sr.prod(l,L[u]+1),sl.prod(l,L[v]+1));\n\t}\n};\n"
  dependsOn:
  - atcoder/segtree.hpp
  - atcoder/internal_bit.hpp
  isVerificationFile: false
  path: work/lib/edge_set_path_prod_20250609_1.hpp
  requiredBy: []
  timestamp: '2025-06-09 22:54:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/edge_set_path_prod_20250609_1.hpp
layout: document
redirect_from:
- /library/work/lib/edge_set_path_prod_20250609_1.hpp
- /library/work/lib/edge_set_path_prod_20250609_1.hpp.html
title: work/lib/edge_set_path_prod_20250609_1.hpp
---
