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
    - https://atcoder.jp/contests/abc407/submissions/66499853
  bundledCode: "#line 1 \"work/lib/mcf_ssp_bellmandijkstra_20250608_1.hpp\"\n//https://atcoder.jp/contests/abc407/submissions/66499853\n\
    //SSP(successive shortest path)\n//s->t flow\n//\u65E5\u672C\u8A9E\u306E\u8A18\
    \u4E8B\u3067\u306Fprimal-dual\u3068\u304B\u547C\u3070\u308C\u3066\u3044\u308B\u3053\
    \u3068\u3082\u3042\u308B\u304C\u3001\n//\u6700\u5C0F\u8CBB\u7528\u6D41\u81EA\u4F53\
    \u304Cprimal-dual\u7684\u898B\u65B9\u304C\u3067\u304D\u308B\u306E\u3067\u3042\u3063\
    \u3066primal-dual\u306F\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306E\u540D\u79F0\u3067\
    \u306F\u306A\u3044\u3002\n//repeat dijkstra O(NM+FMlogM)\n//initial bellman +\
    \ repeat dijkstra O(NM+FMlogM) (\u8CA0\u8FBA\u3042\u308A)\ntemplate<class T,class\
    \ W>\nstruct MCF{\n\tstruct edge{int to,rev;T c;W w;};\n\tint n;\n\tvector<vector<edge>>g;\n\
    \tbool neg;\n\tvector<W>h,d;\n\tvector<pair<int,int>>p;\n\tstatic constexpr W\
    \ inf=numeric_limits<W>::max();\n\tstatic constexpr T inflow=numeric_limits<T>::max();\n\
    \tMCF(int n,bool neg=0):n(n),g(n),neg(neg){}\n\tvoid add_edge(int u,int v,T c,W\
    \ w){\n\t\tassert(0<=u&&u<n&&0<=v&&v<n);\n\t\tassert(c>=0);\n\t\tif(!neg)assert(w>=0);\n\
    \t\tg[u].push_back({v,(int)g[v].size(),c,w});\n\t\tg[v].push_back({u,(int)g[u].size()-1,0,-w});\n\
    \t}\n\tvoid init_potential(){\n\t\tfor(int t=1;t<=n;t++){\n\t\t\tbool upd=0;\n\
    \t\t\tfor(int u=0;u<n;u++)if(h[u]<inf){\n\t\t\t\tfor(auto&e:g[u])if(e.c&&h[u]+e.w<h[e.to]){\n\
    \t\t\t\t\th[e.to]=h[u]+e.w;\n\t\t\t\t\tupd=1;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(!upd)break;\n\
    \t\t\tassert(t<n);\n\t\t}\n\t}\n\tvector<pair<T,W>>slope(int s,int t,T in=inflow){\n\
    \t\tif(neg){\n\t\t\th.assign(n,inf),h[s]=0;\n\t\t\tinit_potential();\n\t\t}else\
    \ h.assign(n,0);\n\t\tT out=0;\n\t\tW cost=0;\n\t\tp.resize(n);\n\t\tusing P=pair<W,int>;\n\
    \t\tpriority_queue<P,vector<P>,greater<P>>que;\n\t\tvector<pair<T,W>>res{{0,0}};\n\
    \t\twhile(in>0){\n\t\t\td.assign(n,inf),d[s]=0;\n\t\t\tque.push(make_pair(0,s));\n\
    \t\t\twhile(que.size()){\n\t\t\t\tauto[du,u]=que.top();que.pop();\n\t\t\t\tif(du>d[u])continue;\n\
    \t\t\t\tint i=-1;\n\t\t\t\tfor(auto&e:g[u]){\n\t\t\t\t\ti++;\n\t\t\t\t\tif(!e.c)continue;\n\
    \t\t\t\t\tint v=e.to;\n\t\t\t\t\tW dv=du+e.w+h[u]-h[v];\n\t\t\t\t\tif(dv<d[v]){\n\
    \t\t\t\t\t\td[v]=dv;\n\t\t\t\t\t\tque.push(make_pair(dv,v));\n\t\t\t\t\t\tp[v]=make_pair(u,i);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(d[t]==inf)break;\n\t\t\tfor(int i=0;i<n;i++)if(d[i]<inf)h[i]+=d[i];\n\
    \t\t\t//for(int i=0;i<n;i++)h[i]+=d[i];//inf\u306B\u306A\u3063\u305F\u3089\u4E8C\
    \u5EA6\u3068\u4F7F\u308F\u306A\u3044\u304B\u3089overflow\u3057\u3066\u3082\u826F\
    \u3044\n\t\t\tT f=in;\n\t\t\tint u=t;\n\t\t\twhile(u!=s){\n\t\t\t\tauto[v,i]=p[u];\n\
    \t\t\t\tf=min(f,g[v][i].c);\n\t\t\t\tu=v;\n\t\t\t}\n\t\t\tu=t;\n\t\t\twhile(u!=s){\n\
    \t\t\t\tauto[v,i]=p[u];\n\t\t\t\tauto&e=g[v][i];\n\t\t\t\te.c-=f;\n\t\t\t\tg[u][e.rev].c+=f;\n\
    \t\t\t\tu=v;\n\t\t\t}\n\t\t\tin-=f;\n\t\t\tout+=f;\n\t\t\tcost+=f*h[t];\n\t\t\t\
    if(!d[t]&&res.size()>1)res.pop_back();\n\t\t\tres.push_back({out,cost});\n\t\t\
    }\n\t\treturn res;\n\t}\n\tpair<T,W>maxflow_mincost(int s,int t,T in=inflow){return\
    \ slope(s,t,in).back();}\n\tpair<T,W>mincost_flow(int s,int t,T in=inflow,bool\
    \ mn=0){\n\t\tauto res=slope(s,t,in);\n\t\tfor(int i=0;i<res.size()-1;i++){\n\t\
    \t\tif(res[i+1].second-res[i].second>=0+!mn)return res[i];\n\t\t}\n\t\treturn\
    \ res.back();\n\t}\n\tpair<T,W>mincost_maxflow(int s,int t,T in=inflow){return\
    \ mincost_flow(s,t,in,0);}\n\tpair<T,W>mincost_minflow(int s,int t,T in=inflow){return\
    \ mincost_flow(s,t,in,1);}\n};\n"
  code: "//https://atcoder.jp/contests/abc407/submissions/66499853\n//SSP(successive\
    \ shortest path)\n//s->t flow\n//\u65E5\u672C\u8A9E\u306E\u8A18\u4E8B\u3067\u306F\
    primal-dual\u3068\u304B\u547C\u3070\u308C\u3066\u3044\u308B\u3053\u3068\u3082\u3042\
    \u308B\u304C\u3001\n//\u6700\u5C0F\u8CBB\u7528\u6D41\u81EA\u4F53\u304Cprimal-dual\u7684\
    \u898B\u65B9\u304C\u3067\u304D\u308B\u306E\u3067\u3042\u3063\u3066primal-dual\u306F\
    \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306E\u540D\u79F0\u3067\u306F\u306A\u3044\
    \u3002\n//repeat dijkstra O(NM+FMlogM)\n//initial bellman + repeat dijkstra O(NM+FMlogM)\
    \ (\u8CA0\u8FBA\u3042\u308A)\ntemplate<class T,class W>\nstruct MCF{\n\tstruct\
    \ edge{int to,rev;T c;W w;};\n\tint n;\n\tvector<vector<edge>>g;\n\tbool neg;\n\
    \tvector<W>h,d;\n\tvector<pair<int,int>>p;\n\tstatic constexpr W inf=numeric_limits<W>::max();\n\
    \tstatic constexpr T inflow=numeric_limits<T>::max();\n\tMCF(int n,bool neg=0):n(n),g(n),neg(neg){}\n\
    \tvoid add_edge(int u,int v,T c,W w){\n\t\tassert(0<=u&&u<n&&0<=v&&v<n);\n\t\t\
    assert(c>=0);\n\t\tif(!neg)assert(w>=0);\n\t\tg[u].push_back({v,(int)g[v].size(),c,w});\n\
    \t\tg[v].push_back({u,(int)g[u].size()-1,0,-w});\n\t}\n\tvoid init_potential(){\n\
    \t\tfor(int t=1;t<=n;t++){\n\t\t\tbool upd=0;\n\t\t\tfor(int u=0;u<n;u++)if(h[u]<inf){\n\
    \t\t\t\tfor(auto&e:g[u])if(e.c&&h[u]+e.w<h[e.to]){\n\t\t\t\t\th[e.to]=h[u]+e.w;\n\
    \t\t\t\t\tupd=1;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(!upd)break;\n\t\t\tassert(t<n);\n\
    \t\t}\n\t}\n\tvector<pair<T,W>>slope(int s,int t,T in=inflow){\n\t\tif(neg){\n\
    \t\t\th.assign(n,inf),h[s]=0;\n\t\t\tinit_potential();\n\t\t}else h.assign(n,0);\n\
    \t\tT out=0;\n\t\tW cost=0;\n\t\tp.resize(n);\n\t\tusing P=pair<W,int>;\n\t\t\
    priority_queue<P,vector<P>,greater<P>>que;\n\t\tvector<pair<T,W>>res{{0,0}};\n\
    \t\twhile(in>0){\n\t\t\td.assign(n,inf),d[s]=0;\n\t\t\tque.push(make_pair(0,s));\n\
    \t\t\twhile(que.size()){\n\t\t\t\tauto[du,u]=que.top();que.pop();\n\t\t\t\tif(du>d[u])continue;\n\
    \t\t\t\tint i=-1;\n\t\t\t\tfor(auto&e:g[u]){\n\t\t\t\t\ti++;\n\t\t\t\t\tif(!e.c)continue;\n\
    \t\t\t\t\tint v=e.to;\n\t\t\t\t\tW dv=du+e.w+h[u]-h[v];\n\t\t\t\t\tif(dv<d[v]){\n\
    \t\t\t\t\t\td[v]=dv;\n\t\t\t\t\t\tque.push(make_pair(dv,v));\n\t\t\t\t\t\tp[v]=make_pair(u,i);\n\
    \t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(d[t]==inf)break;\n\t\t\tfor(int i=0;i<n;i++)if(d[i]<inf)h[i]+=d[i];\n\
    \t\t\t//for(int i=0;i<n;i++)h[i]+=d[i];//inf\u306B\u306A\u3063\u305F\u3089\u4E8C\
    \u5EA6\u3068\u4F7F\u308F\u306A\u3044\u304B\u3089overflow\u3057\u3066\u3082\u826F\
    \u3044\n\t\t\tT f=in;\n\t\t\tint u=t;\n\t\t\twhile(u!=s){\n\t\t\t\tauto[v,i]=p[u];\n\
    \t\t\t\tf=min(f,g[v][i].c);\n\t\t\t\tu=v;\n\t\t\t}\n\t\t\tu=t;\n\t\t\twhile(u!=s){\n\
    \t\t\t\tauto[v,i]=p[u];\n\t\t\t\tauto&e=g[v][i];\n\t\t\t\te.c-=f;\n\t\t\t\tg[u][e.rev].c+=f;\n\
    \t\t\t\tu=v;\n\t\t\t}\n\t\t\tin-=f;\n\t\t\tout+=f;\n\t\t\tcost+=f*h[t];\n\t\t\t\
    if(!d[t]&&res.size()>1)res.pop_back();\n\t\t\tres.push_back({out,cost});\n\t\t\
    }\n\t\treturn res;\n\t}\n\tpair<T,W>maxflow_mincost(int s,int t,T in=inflow){return\
    \ slope(s,t,in).back();}\n\tpair<T,W>mincost_flow(int s,int t,T in=inflow,bool\
    \ mn=0){\n\t\tauto res=slope(s,t,in);\n\t\tfor(int i=0;i<res.size()-1;i++){\n\t\
    \t\tif(res[i+1].second-res[i].second>=0+!mn)return res[i];\n\t\t}\n\t\treturn\
    \ res.back();\n\t}\n\tpair<T,W>mincost_maxflow(int s,int t,T in=inflow){return\
    \ mincost_flow(s,t,in,0);}\n\tpair<T,W>mincost_minflow(int s,int t,T in=inflow){return\
    \ mincost_flow(s,t,in,1);}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/mcf_ssp_bellmandijkstra_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/mcf_ssp_bellmandijkstra_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/mcf_ssp_bellmandijkstra_20250608_1.hpp
- /library/work/lib/mcf_ssp_bellmandijkstra_20250608_1.hpp.html
title: work/lib/mcf_ssp_bellmandijkstra_20250608_1.hpp
---
