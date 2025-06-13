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
    - https://atcoder.jp/contests/practice2/submissions/64392961
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250612_2.hpp\"\n//recursive\n//https://atcoder.jp/contests/practice2/submissions/64392961\n\
    template<class X,auto op,auto e,class F,auto mapping,auto composition,auto id>\n\
    class segtree{\n\tint w=1,h=0;\n\tvector<X>d;vector<F>lz;\n\tvoid _apply(int i,F\
    \ f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid pull(int i){for(int\
    \ j=h+1;--j;)push(i>>j);}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\t\
    void upd(int i){while(i>>=1)merge(i);}\npublic:\n\tint n;\n\tsegtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());lz.assign(w,id());}\n\
    \tsegtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int\
    \ i=w;--i;)merge(i);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}\n\
    \tvoid apply(int l,int r,F f){assert(0<=l&&l<=r&&r<=n);_apply(0,w,1,f,l,r);}\n\
    \tvoid _apply(int l,int r,int i,F f,int L,int R){\n\t\tif(r<=L||R<=l)return;\n\
    \t\tif(L<=l&&r<=R){_apply(i,f);return;}\n\t\tint c=l+r>>1;\n\t\tpush(i),_apply(l,c,i<<1,f,L,R),_apply(c,r,i<<1|1,f,L,R),merge(i);\n\
    \t}\n\tX fold(int l,int r){assert(0<=l&&l<=r&&r<=n);return _fold(0,w,1,l,r);}\n\
    \tX _fold(int l,int r,int i,int L,int R){\n\t\tif(r<=L||R<=l)return e();\n\t\t\
    if(L<=l&&r<=R)return d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);return op(_fold(l,c,i<<1,L,R),_fold(c,r,i<<1|1,L,R));\n\
    \t}\n};\n"
  code: "//recursive\n//https://atcoder.jp/contests/practice2/submissions/64392961\n\
    template<class X,auto op,auto e,class F,auto mapping,auto composition,auto id>\n\
    class segtree{\n\tint w=1,h=0;\n\tvector<X>d;vector<F>lz;\n\tvoid _apply(int i,F\
    \ f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid pull(int i){for(int\
    \ j=h+1;--j;)push(i>>j);}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\t\
    void upd(int i){while(i>>=1)merge(i);}\npublic:\n\tint n;\n\tsegtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());lz.assign(w,id());}\n\
    \tsegtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int\
    \ i=w;--i;)merge(i);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}\n\
    \tvoid apply(int l,int r,F f){assert(0<=l&&l<=r&&r<=n);_apply(0,w,1,f,l,r);}\n\
    \tvoid _apply(int l,int r,int i,F f,int L,int R){\n\t\tif(r<=L||R<=l)return;\n\
    \t\tif(L<=l&&r<=R){_apply(i,f);return;}\n\t\tint c=l+r>>1;\n\t\tpush(i),_apply(l,c,i<<1,f,L,R),_apply(c,r,i<<1|1,f,L,R),merge(i);\n\
    \t}\n\tX fold(int l,int r){assert(0<=l&&l<=r&&r<=n);return _fold(0,w,1,l,r);}\n\
    \tX _fold(int l,int r,int i,int L,int R){\n\t\tif(r<=L||R<=l)return e();\n\t\t\
    if(L<=l&&r<=R)return d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);return op(_fold(l,c,i<<1,L,R),_fold(c,r,i<<1|1,L,R));\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250612_2.hpp
  requiredBy: []
  timestamp: '2025-06-13 09:18:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/segtree_lazy_20250612_2.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250612_2.hpp
- /library/work/lib/segtree_lazy_20250612_2.hpp.html
title: work/lib/segtree_lazy_20250612_2.hpp
---
