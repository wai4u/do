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
    - https://atcoder.jp/contests/abc239/submissions/66446109
  bundledCode: "#line 1 \"work/lib/maxflow_dense_20250608_1.hpp\"\ntemplate<class\
    \ T>\nstruct maxflow{\n\tint n;\n\tvector<vector<T>>c;\n\tvector<bool>vis;\n\t\
    vector<int>d,que;\n\tmaxflow(int n):n(n),c(n,vector<T>(n,0)){}\n\tvoid add_edge(int\
    \ u,int v,T w){c[u][v]+=w;}\n\tT dfs(int u,int t,T in){\n\t\tif(u==t)return in;\n\
    \t\tif(vis[u])return 0;\n\t\tvis[u]=1;\n\t\tT out=0;\n\t\tfor(int v=0;v<n;v++){\n\
    \t\t\tif(!in)break;\n\t\t\tif(d[v]<=d[u]||!c[u][v])continue;\n\t\t\tT f=dfs(v,t,min(c[u][v],in));\n\
    \t\t\tc[u][v]-=f;\n\t\t\tc[v][u]+=f;\n\t\t\tin-=f;\n\t\t\tout+=f;\n\t\t}\n\t\t\
    return out;\n\t};\n\tT flow(int s,int t){\n\t\tT ans=0,inf=numeric_limits<T>::max();\n\
    \t\twhile(1){\n\t\t\tvis.assign(n,0);\n\t\t\td.assign(n,-1),que.clear();\n\t\t\
    \td[s]=0,que.push_back(s);\n\t\t\tfor(int i=0;i<que.size();i++){\n\t\t\t\tint\
    \ u=que[i];\n\t\t\t\tfor(int v=0;v<n;v++)if(c[u][v]&&d[v]<0){\n\t\t\t\t\td[v]=d[u]+1;\n\
    \t\t\t\t\tque.push_back(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(d[t]<0)break;\n\t\t\t\
    ans+=dfs(s,t,inf);\n\t\t}\n\t\treturn ans;\n\t}\n\t//call after flow(s,t).1->0\
    \ edge is in a cut\n\t//https://atcoder.jp/contests/abc239/submissions/66446109\n\
    \tvector<bool>partition(){\n\t\tfor(int i=0;i<n;i++)vis[i]=d[i]>-1;\n\t\treturn\
    \ vis;\n\t}\n};\n"
  code: "template<class T>\nstruct maxflow{\n\tint n;\n\tvector<vector<T>>c;\n\tvector<bool>vis;\n\
    \tvector<int>d,que;\n\tmaxflow(int n):n(n),c(n,vector<T>(n,0)){}\n\tvoid add_edge(int\
    \ u,int v,T w){c[u][v]+=w;}\n\tT dfs(int u,int t,T in){\n\t\tif(u==t)return in;\n\
    \t\tif(vis[u])return 0;\n\t\tvis[u]=1;\n\t\tT out=0;\n\t\tfor(int v=0;v<n;v++){\n\
    \t\t\tif(!in)break;\n\t\t\tif(d[v]<=d[u]||!c[u][v])continue;\n\t\t\tT f=dfs(v,t,min(c[u][v],in));\n\
    \t\t\tc[u][v]-=f;\n\t\t\tc[v][u]+=f;\n\t\t\tin-=f;\n\t\t\tout+=f;\n\t\t}\n\t\t\
    return out;\n\t};\n\tT flow(int s,int t){\n\t\tT ans=0,inf=numeric_limits<T>::max();\n\
    \t\twhile(1){\n\t\t\tvis.assign(n,0);\n\t\t\td.assign(n,-1),que.clear();\n\t\t\
    \td[s]=0,que.push_back(s);\n\t\t\tfor(int i=0;i<que.size();i++){\n\t\t\t\tint\
    \ u=que[i];\n\t\t\t\tfor(int v=0;v<n;v++)if(c[u][v]&&d[v]<0){\n\t\t\t\t\td[v]=d[u]+1;\n\
    \t\t\t\t\tque.push_back(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(d[t]<0)break;\n\t\t\t\
    ans+=dfs(s,t,inf);\n\t\t}\n\t\treturn ans;\n\t}\n\t//call after flow(s,t).1->0\
    \ edge is in a cut\n\t//https://atcoder.jp/contests/abc239/submissions/66446109\n\
    \tvector<bool>partition(){\n\t\tfor(int i=0;i<n;i++)vis[i]=d[i]>-1;\n\t\treturn\
    \ vis;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/maxflow_dense_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/maxflow_dense_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/maxflow_dense_20250608_1.hpp
- /library/work/lib/maxflow_dense_20250608_1.hpp.html
title: work/lib/maxflow_dense_20250608_1.hpp
---
