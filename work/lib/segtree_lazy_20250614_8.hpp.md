---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_8_1.test.cpp
    title: work/lib/segtree_lazy_20250614_8_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_8_2.test.cpp
    title: work/lib/segtree_lazy_20250614_8_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_8_3.test.cpp
    title: work/lib/segtree_lazy_20250614_8_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_8_4.test.cpp
    title: work/lib/segtree_lazy_20250614_8_4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/66708645
    - https://atcoder.jp/contests/practice2/submissions/66708655
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250614_8.hpp\"\n//recursive\n//binary\
    \ search\n//\u679D\u5208\u308A\n//https://atcoder.jp/contests/practice2/submissions/66708645\n\
    //https://atcoder.jp/contests/practice2/submissions/66708655\ntemplate<class X,X(*op)(X,X),X(*e)(),class\
    \ F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\nstruct segtree_lazy{\n\
    \tint n,w=1,h=1;\n\tvector<X>d;vector<F>lz;\n\tsegtree_lazy(int n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e()),lz.assign(w,id());}\n\
    \tvoid _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\
    \tvoid push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid\
    \ merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid pull(int i){for(int j=h;--j;)push(i>>j);}\n\
    \tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w),d[i]=x;while(i>>=1)merge(i);}\n\
    \tvoid apply(int i,F f){assert(0<=i&&i<n);pull(i+=w),_apply(i,f);while(i>>=1)merge(i);}\n\
    \tX get(int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}\n\tX operator[](int\
    \ i){return get(i);}\n\tvoid apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return;\n\t\tif(l+1==r)return apply(l,f);\n\t\tapply(l,r,f,1,0,w);\n\
    \t}\n\tvoid apply(int L,int R,const F&f,int i,int l,int r){\n\t\tif(L<=l&&r<=R)return\
    \ _apply(i,f);\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tif(L<c)apply(L,R,f,i<<1,l,c);\n\
    \t\tif(c<R)apply(L,R,f,i<<1|1,c,r);\n\t\tmerge(i);\n\t}\n\tX prod(int l,int r){\n\
    \t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return e();\n\t\tif(l+1==r)return get(l);\n\
    \t\treturn prod(l,r,1,0,w);\n\t}\n\tX prod(int L,int R,int i,int l,int r){\n\t\
    \tif(L<=l&&r<=R)return d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tif(R<=c)return\
    \ prod(L,R,i<<1,l,c);\n\t\tif(c<=L)return prod(L,R,i<<1|1,c,r);\n\t\treturn op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int l,G f){\n\t\tassert(0<=l&&l<=n);\n\
    \t\tif(l==n)return n;\n\t\tX x=e();\n\t\treturn max_right(l,f,x,0,w,1);\n\t}\n\
    \ttemplate<class G>\n\tint max_right(int L,G f,X&x,int l,int r,int i){\n\t\tif(r<=L)return\
    \ L;\n\t\tif(L<=l){\n\t\t\tif(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}\n\t\
    \t\tif(l+1==r)return l;\n\t\t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=max_right(L,f,x,l,c,i<<1);\n\
    \t\treturn j<c||j==n?j:max_right(L,f,x,c,r,i<<1|1);\n\t}\n\ttemplate<class G>\n\
    \tint min_left(int r,G f){\n\t\tassert(0<=r&&r<=n);\n\t\tif(r==0)return 0;\n\t\
    \tX x=e();\n\t\treturn min_left(r,f,x,0,w,1);\n\t}\n\ttemplate<class G>\n\tint\
    \ min_left(int R,G f,X&x,int l,int r,int i){\n\t\tif(R<=l)return R;\n\t\tif(r<=R){\n\
    \t\t\tif(f(op(d[i],x))){x=op(d[i],x);return l;}\n\t\t\tif(l+1==r)return r;\n\t\
    \t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=min_left(R,f,x,c,r,i<<1|1);\n\t\treturn\
    \ c<j?j:min_left(R,f,x,l,c,i<<1);\n\t}\n};\n"
  code: "//recursive\n//binary search\n//\u679D\u5208\u308A\n//https://atcoder.jp/contests/practice2/submissions/66708645\n\
    //https://atcoder.jp/contests/practice2/submissions/66708655\ntemplate<class X,X(*op)(X,X),X(*e)(),class\
    \ F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\nstruct segtree_lazy{\n\
    \tint n,w=1,h=1;\n\tvector<X>d;vector<F>lz;\n\tsegtree_lazy(int n):n(n){while(w<n)w<<=1,++h;d.assign(w+w,e()),lz.assign(w,id());}\n\
    \tvoid _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\
    \tvoid push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid\
    \ merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid pull(int i){for(int j=h;--j;)push(i>>j);}\n\
    \tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w),d[i]=x;while(i>>=1)merge(i);}\n\
    \tvoid apply(int i,F f){assert(0<=i&&i<n);pull(i+=w),_apply(i,f);while(i>>=1)merge(i);}\n\
    \tX get(int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}\n\tX operator[](int\
    \ i){return get(i);}\n\tvoid apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return;\n\t\tif(l+1==r)return apply(l,f);\n\t\tapply(l,r,f,1,0,w);\n\
    \t}\n\tvoid apply(int L,int R,const F&f,int i,int l,int r){\n\t\tif(L<=l&&r<=R)return\
    \ _apply(i,f);\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tif(L<c)apply(L,R,f,i<<1,l,c);\n\
    \t\tif(c<R)apply(L,R,f,i<<1|1,c,r);\n\t\tmerge(i);\n\t}\n\tX prod(int l,int r){\n\
    \t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return e();\n\t\tif(l+1==r)return get(l);\n\
    \t\treturn prod(l,r,1,0,w);\n\t}\n\tX prod(int L,int R,int i,int l,int r){\n\t\
    \tif(L<=l&&r<=R)return d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tif(R<=c)return\
    \ prod(L,R,i<<1,l,c);\n\t\tif(c<=L)return prod(L,R,i<<1|1,c,r);\n\t\treturn op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int l,G f){\n\t\tassert(0<=l&&l<=n);\n\
    \t\tif(l==n)return n;\n\t\tX x=e();\n\t\treturn max_right(l,f,x,0,w,1);\n\t}\n\
    \ttemplate<class G>\n\tint max_right(int L,G f,X&x,int l,int r,int i){\n\t\tif(r<=L)return\
    \ L;\n\t\tif(L<=l){\n\t\t\tif(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}\n\t\
    \t\tif(l+1==r)return l;\n\t\t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=max_right(L,f,x,l,c,i<<1);\n\
    \t\treturn j<c||j==n?j:max_right(L,f,x,c,r,i<<1|1);\n\t}\n\ttemplate<class G>\n\
    \tint min_left(int r,G f){\n\t\tassert(0<=r&&r<=n);\n\t\tif(r==0)return 0;\n\t\
    \tX x=e();\n\t\treturn min_left(r,f,x,0,w,1);\n\t}\n\ttemplate<class G>\n\tint\
    \ min_left(int R,G f,X&x,int l,int r,int i){\n\t\tif(R<=l)return R;\n\t\tif(r<=R){\n\
    \t\t\tif(f(op(d[i],x))){x=op(d[i],x);return l;}\n\t\t\tif(l+1==r)return r;\n\t\
    \t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=min_left(R,f,x,c,r,i<<1|1);\n\t\treturn\
    \ c<j?j:min_left(R,f,x,l,c,i<<1);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250614_8.hpp
  requiredBy: []
  timestamp: '2025-06-14 15:56:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250614_8_4.test.cpp
  - work/lib/segtree_lazy_20250614_8_2.test.cpp
  - work/lib/segtree_lazy_20250614_8_3.test.cpp
  - work/lib/segtree_lazy_20250614_8_1.test.cpp
documentation_of: work/lib/segtree_lazy_20250614_8.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250614_8.hpp
- /library/work/lib/segtree_lazy_20250614_8.hpp.html
title: work/lib/segtree_lazy_20250614_8.hpp
---
