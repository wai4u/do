---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250613_3_1.test.cpp
    title: work/lib/segtree_lazy_20250613_3_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250613_3_2.test.cpp
    title: work/lib/segtree_lazy_20250613_3_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250613_3_3.test.cpp
    title: work/lib/segtree_lazy_20250613_3_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250613_3_4.test.cpp
    title: work/lib/segtree_lazy_20250613_3_4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250613_3.hpp\"\n//proxy set\n//non\
    \ commutative monoid\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\ntemplate<class\
    \ X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\n\
    struct segtree_lazy{\n\tint n,w=1;\n\tvector<X>d;\n\tvector<F>lz;\n\tsegtree_lazy(int\
    \ n):n(n){while(w<n)w<<=1;d.assign(w+w,e()),lz.assign(w,id());}\n\tvoid _apply(int\
    \ i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid pull(int i){if(i)for(int\
    \ j=(32-__builtin_clz(i));--j;)push(i>>j);}\n\tvoid upd(int i){while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tstruct proxy{\n\t\tsegtree_lazy&seg;\n\t\tint i;\n\t\tproxy(segtree_lazy&seg,int\
    \ i):seg(seg),i(i){seg.pull(i);}\n\t\tproxy&operator=(X x){seg.d[i]=x,seg.upd(i);return\
    \ *this;}\n\t\tvoid apply(F f){seg._apply(i,f),seg.upd(i);}\n\t\toperator X()const{return\
    \ seg.d[i];}\n\t};\n\tproxy operator[](int i){return proxy(*this,i+w);}\n\tvoid\
    \ apply(int l,int r,F f){\n\t\tl+=w,r+=w;int L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\
    \t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);l>>=1;\n\t\t\tif(r&1)_apply(--r,f);r>>=1;\n\
    \t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX prod(int l,int r){\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);l>>=1;\n\t\
    \t\tif(r&1)vr=op(d[--r],vr);r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t}\n};\n"
  code: "//proxy set\n//non commutative monoid\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\ntemplate<class\
    \ X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\n\
    struct segtree_lazy{\n\tint n,w=1;\n\tvector<X>d;\n\tvector<F>lz;\n\tsegtree_lazy(int\
    \ n):n(n){while(w<n)w<<=1;d.assign(w+w,e()),lz.assign(w,id());}\n\tvoid _apply(int\
    \ i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid pull(int i){if(i)for(int\
    \ j=(32-__builtin_clz(i));--j;)push(i>>j);}\n\tvoid upd(int i){while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tstruct proxy{\n\t\tsegtree_lazy&seg;\n\t\tint i;\n\t\tproxy(segtree_lazy&seg,int\
    \ i):seg(seg),i(i){seg.pull(i);}\n\t\tproxy&operator=(X x){seg.d[i]=x,seg.upd(i);return\
    \ *this;}\n\t\tvoid apply(F f){seg._apply(i,f),seg.upd(i);}\n\t\toperator X()const{return\
    \ seg.d[i];}\n\t};\n\tproxy operator[](int i){return proxy(*this,i+w);}\n\tvoid\
    \ apply(int l,int r,F f){\n\t\tl+=w,r+=w;int L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\
    \t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);l>>=1;\n\t\t\tif(r&1)_apply(--r,f);r>>=1;\n\
    \t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX prod(int l,int r){\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);l>>=1;\n\t\
    \t\tif(r&1)vr=op(d[--r],vr);r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250613_3.hpp
  requiredBy: []
  timestamp: '2025-06-13 19:41:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250613_3_2.test.cpp
  - work/lib/segtree_lazy_20250613_3_1.test.cpp
  - work/lib/segtree_lazy_20250613_3_3.test.cpp
  - work/lib/segtree_lazy_20250613_3_4.test.cpp
documentation_of: work/lib/segtree_lazy_20250613_3.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250613_3.hpp
- /library/work/lib/segtree_lazy_20250613_3.hpp.html
title: work/lib/segtree_lazy_20250613_3.hpp
---
