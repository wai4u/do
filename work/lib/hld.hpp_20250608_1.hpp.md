---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"work/lib/hld.hpp_20250608_1.hpp\"\nstruct HLD{\n\tint n=0,m=0;\n\
    \tvector<vector<pair<int,int>>>g;\n\tvector<int>ord,pos,p,dep,hd,sz,L,R,ve,ev;\n\
    \tHLD(int n):n(n),g(n){}\n\tvoid add_edge(int u,int v,int id=-1){\n\t\tif(id==-1)id=m;\n\
    \t\tg[u].push_back(make_pair(v,id));\n\t\tg[v].push_back(make_pair(u,id));\n\t\
    \tm++;\n\t}\n\tvoid build(int r){\n\t\tassert(m==n-1);\n\t\tord.clear();\n\t\t\
    pos.resize(n);\n\t\tp.assign(n,-1);\n\t\tdep.assign(n,0);\n\t\thd.assign(n,-1);\n\
    \t\thd[r]=r;\n\t\tsz.assign(n,1);\n\t\tL.resize(n);\n\t\tR.resize(n);\n\t\tev.resize(m);\n\
    \t\tve.assign(n,-1);\n\t\tdfs(r);\n\t\tint k=0;\n\t\tefs(r,k);\n\t}\n\tvoid dfs(int\
    \ u){\n\t\tif(g[u][0].first==p[u])swap(g[u][0],g[u].back());\n\t\tfor(auto&e:g[u])if(e.first!=p[u]){\n\
    \t\t\tauto&[v,id]=e;\n\t\t\tp[v]=u;\n\t\t\tev[id]=v;\n\t\t\tve[v]=id;\n\t\t\t\
    dep[v]=dep[u]+1;\n\t\t\tdfs(v);\n\t\t\tsz[u]+=sz[v];\n\t\t\tif(sz[v]>sz[g[u][0].first])swap(e,g[u][0]);\n\
    \t\t}\n\t};\n\tvoid efs(int u,int&k){\n\t\tpos[u]=L[u]=k++;\n\t\tord.push_back(u);\n\
    \t\tbool used=0;\n\t\tfor(auto[v,_]:g[u])if(v!=p[u]){\n\t\t\thd[v]=used?v:hd[u];\n\
    \t\t\tused=1;\n\t\t\tefs(v,k);\n\t\t}\n\t\tR[u]=k;\n\t}\n\tbool in_subtree(int\
    \ u,int v){\n\t\t//u<=subtree(v);\n\t\treturn L[v]<=L[u]&&L[u]<R[v];\n\t}\n\t\
    int LA(int u,int k){\n\t\tif(k>dep[u])return -1;\n\t\t//assert(k<=dep[u]);\n\t\
    \twhile(1){\n\t\t\tint v=hd[u];\n\t\t\tint d=L[u]-L[v];\n\t\t\tif(k<=d)return\
    \ ord[L[u]-k];\n\t\t\tk-=d+1;\n\t\t\tu=p[v];\n\t\t}\n\t}\n\tint lca(int u,int\
    \ v){\n\t\twhile(1){\n\t\t\tif(L[u]>L[v])swap(u,v);\n\t\t\tif(hd[u]==hd[v])return\
    \ u;\n\t\t\tv=p[hd[v]];\n\t\t}\n\t};\n\tint dist(int u,int v){\n\t\tint w=lca(u,v);\n\
    \t\treturn dep[u]+dep[v]-2*dep[w];\n\t};\n\tint jump(int u,int v,int k){//u->v\
    \ kth\n\t\tint w=lca(u,v);\n\t\tint du=dep[u]-dep[w];\n\t\tint dv=dep[v]-dep[w];\n\
    \t\tif(k<=du)return LA(u,k);\n\t\tk-=du;\n\t\t//assert(k<=dv);\n\t\t//return LCA(v,dv-k);\n\
    \t\tif(k<=dv)return LA(v,dv-k);\n\t\treturn -1;\n\t};\n};\n"
  code: "struct HLD{\n\tint n=0,m=0;\n\tvector<vector<pair<int,int>>>g;\n\tvector<int>ord,pos,p,dep,hd,sz,L,R,ve,ev;\n\
    \tHLD(int n):n(n),g(n){}\n\tvoid add_edge(int u,int v,int id=-1){\n\t\tif(id==-1)id=m;\n\
    \t\tg[u].push_back(make_pair(v,id));\n\t\tg[v].push_back(make_pair(u,id));\n\t\
    \tm++;\n\t}\n\tvoid build(int r){\n\t\tassert(m==n-1);\n\t\tord.clear();\n\t\t\
    pos.resize(n);\n\t\tp.assign(n,-1);\n\t\tdep.assign(n,0);\n\t\thd.assign(n,-1);\n\
    \t\thd[r]=r;\n\t\tsz.assign(n,1);\n\t\tL.resize(n);\n\t\tR.resize(n);\n\t\tev.resize(m);\n\
    \t\tve.assign(n,-1);\n\t\tdfs(r);\n\t\tint k=0;\n\t\tefs(r,k);\n\t}\n\tvoid dfs(int\
    \ u){\n\t\tif(g[u][0].first==p[u])swap(g[u][0],g[u].back());\n\t\tfor(auto&e:g[u])if(e.first!=p[u]){\n\
    \t\t\tauto&[v,id]=e;\n\t\t\tp[v]=u;\n\t\t\tev[id]=v;\n\t\t\tve[v]=id;\n\t\t\t\
    dep[v]=dep[u]+1;\n\t\t\tdfs(v);\n\t\t\tsz[u]+=sz[v];\n\t\t\tif(sz[v]>sz[g[u][0].first])swap(e,g[u][0]);\n\
    \t\t}\n\t};\n\tvoid efs(int u,int&k){\n\t\tpos[u]=L[u]=k++;\n\t\tord.push_back(u);\n\
    \t\tbool used=0;\n\t\tfor(auto[v,_]:g[u])if(v!=p[u]){\n\t\t\thd[v]=used?v:hd[u];\n\
    \t\t\tused=1;\n\t\t\tefs(v,k);\n\t\t}\n\t\tR[u]=k;\n\t}\n\tbool in_subtree(int\
    \ u,int v){\n\t\t//u<=subtree(v);\n\t\treturn L[v]<=L[u]&&L[u]<R[v];\n\t}\n\t\
    int LA(int u,int k){\n\t\tif(k>dep[u])return -1;\n\t\t//assert(k<=dep[u]);\n\t\
    \twhile(1){\n\t\t\tint v=hd[u];\n\t\t\tint d=L[u]-L[v];\n\t\t\tif(k<=d)return\
    \ ord[L[u]-k];\n\t\t\tk-=d+1;\n\t\t\tu=p[v];\n\t\t}\n\t}\n\tint lca(int u,int\
    \ v){\n\t\twhile(1){\n\t\t\tif(L[u]>L[v])swap(u,v);\n\t\t\tif(hd[u]==hd[v])return\
    \ u;\n\t\t\tv=p[hd[v]];\n\t\t}\n\t};\n\tint dist(int u,int v){\n\t\tint w=lca(u,v);\n\
    \t\treturn dep[u]+dep[v]-2*dep[w];\n\t};\n\tint jump(int u,int v,int k){//u->v\
    \ kth\n\t\tint w=lca(u,v);\n\t\tint du=dep[u]-dep[w];\n\t\tint dv=dep[v]-dep[w];\n\
    \t\tif(k<=du)return LA(u,k);\n\t\tk-=du;\n\t\t//assert(k<=dv);\n\t\t//return LCA(v,dv-k);\n\
    \t\tif(k<=dv)return LA(v,dv-k);\n\t\treturn -1;\n\t};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/hld.hpp_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/hld.hpp_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/hld.hpp_20250608_1.hpp
- /library/work/lib/hld.hpp_20250608_1.hpp.html
title: work/lib/hld.hpp_20250608_1.hpp
---
