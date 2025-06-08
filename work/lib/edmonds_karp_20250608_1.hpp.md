---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"work/lib/edmonds_karp_20250608_1.hpp\"\n//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\n\
    template<class T>\nstruct maxflow{\n\tint n;\n\tvector<vector<T>>c;\n\tvector<int>p,que;\n\
    \tmaxflow(int n):n(n),c(n,vector<T>(n,0)){}\n\tvoid add_edge(int u,int v,T w){c[u][v]+=w;}\n\
    \tT flow(int s,int t){\n\t\tT ans=0;\n\t\twhile(1){\n\t\t\tp.assign(n,-1);\n\t\
    \t\tque.clear();\n\t\t\tque.push_back(s);\n\t\t\tfor(int i=0;i<que.size();i++){\n\
    \t\t\t\tint u=que[i];\n\t\t\t\tfor(int v=0;v<n;v++)if(p[v]<0&&c[u][v]){\n\t\t\t\
    \t\tp[v]=u;\n\t\t\t\t\tque.push_back(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(p[t]<0)break;\n\
    \t\t\tint u=p[t];\n\t\t\tT f=c[u][t];\n\t\t\twhile(u!=s){\n\t\t\t\tf=min(f,c[p[u]][u]);\n\
    \t\t\t\tu=p[u];\n\t\t\t}\n\t\t\tu=t;\n\t\t\twhile(u!=s){\n\t\t\t\tint v=p[u];\n\
    \t\t\t\tc[v][u]-=f;\n\t\t\t\tc[u][v]+=f;\n\t\t\t\tu=v;\n\t\t\t}\n\t\t\tans+=f;\n\
    \t\t}\n\t\treturn ans;\n\t}\n};\n"
  code: "//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\ntemplate<class\
    \ T>\nstruct maxflow{\n\tint n;\n\tvector<vector<T>>c;\n\tvector<int>p,que;\n\t\
    maxflow(int n):n(n),c(n,vector<T>(n,0)){}\n\tvoid add_edge(int u,int v,T w){c[u][v]+=w;}\n\
    \tT flow(int s,int t){\n\t\tT ans=0;\n\t\twhile(1){\n\t\t\tp.assign(n,-1);\n\t\
    \t\tque.clear();\n\t\t\tque.push_back(s);\n\t\t\tfor(int i=0;i<que.size();i++){\n\
    \t\t\t\tint u=que[i];\n\t\t\t\tfor(int v=0;v<n;v++)if(p[v]<0&&c[u][v]){\n\t\t\t\
    \t\tp[v]=u;\n\t\t\t\t\tque.push_back(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(p[t]<0)break;\n\
    \t\t\tint u=p[t];\n\t\t\tT f=c[u][t];\n\t\t\twhile(u!=s){\n\t\t\t\tf=min(f,c[p[u]][u]);\n\
    \t\t\t\tu=p[u];\n\t\t\t}\n\t\t\tu=t;\n\t\t\twhile(u!=s){\n\t\t\t\tint v=p[u];\n\
    \t\t\t\tc[v][u]-=f;\n\t\t\t\tc[u][v]+=f;\n\t\t\t\tu=v;\n\t\t\t}\n\t\t\tans+=f;\n\
    \t\t}\n\t\treturn ans;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/edmonds_karp_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/edmonds_karp_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/edmonds_karp_20250608_1.hpp
- /library/work/lib/edmonds_karp_20250608_1.hpp.html
title: work/lib/edmonds_karp_20250608_1.hpp
---
