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
    - https://atcoder.jp/contests/practice2/submissions/64392921
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250612_3.hpp\"\n//https://atcoder.jp/contests/practice2/submissions/64392921\n\
    int bitlen(int x){return x?32-__builtin_clz(x):0;}\ntemplate<class X,auto op,auto\
    \ e,class F,auto mapping,auto composition,auto id>\nstruct segtree{\n\tint n,w=1;\n\
    \tvector<X>d;vector<F>p;\n\tsegtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());p.assign(w,id());}\n\
    \tvoid _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)p[i]=composition(f,p[i]);}\n\
    \tvoid push(int i){_apply(i<<1,p[i]),_apply(i<<1|1,p[i]),p[i]=id();}\n\tvoid pull(int\
    \ i){for(int j=bitlen(i);--j>0;)push(i>>j);}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tvoid upd(int i){while(i>>=1)merge(i);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}\n\
    \tvoid apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;int\
    \ L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);l>>=1;\n\
    \t\t\tif(r&1)_apply(--r,f);r>>=1;\n\t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX fold(int\
    \ l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l));pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);l>>=1;\n\t\
    \t\tif(r&1)vr=op(d[--r],vr);r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t}\n};\n"
  code: "//https://atcoder.jp/contests/practice2/submissions/64392921\nint bitlen(int\
    \ x){return x?32-__builtin_clz(x):0;}\ntemplate<class X,auto op,auto e,class F,auto\
    \ mapping,auto composition,auto id>\nstruct segtree{\n\tint n,w=1;\n\tvector<X>d;vector<F>p;\n\
    \tsegtree(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e());p.assign(w,id());}\n\t\
    void _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)p[i]=composition(f,p[i]);}\n\
    \tvoid push(int i){_apply(i<<1,p[i]),_apply(i<<1|1,p[i]),p[i]=id();}\n\tvoid pull(int\
    \ i){for(int j=bitlen(i);--j>0;)push(i>>j);}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tvoid upd(int i){while(i>>=1)merge(i);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}\n\
    \tvoid apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;int\
    \ L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);l>>=1;\n\
    \t\t\tif(r&1)_apply(--r,f);r>>=1;\n\t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX fold(int\
    \ l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l));pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);l>>=1;\n\t\
    \t\tif(r&1)vr=op(d[--r],vr);r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250612_3.hpp
  requiredBy: []
  timestamp: '2025-06-13 09:18:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/segtree_lazy_20250612_3.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250612_3.hpp
- /library/work/lib/segtree_lazy_20250612_3.hpp.html
title: work/lib/segtree_lazy_20250612_3.hpp
---
