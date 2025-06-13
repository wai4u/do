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
    - https://atcoder.jp/contests/practice2/submissions/64400765
    - https://atcoder.jp/contests/practice2/submissions/64400783
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250614_3.hpp\"\n//recursive\n//https://atcoder.jp/contests/practice2/submissions/64400765\n\
    //https://atcoder.jp/contests/practice2/submissions/64400783\ntemplate<class X,auto\
    \ op,auto e,class F=X,auto mapping=op,auto composition=op,auto id=e>\nstruct segtree{\n\
    \tint n,w=1,h=0;\n\tvector<X>d;vector<F>lz;\n\tvoid _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\
    \tvoid push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid\
    \ pull(int i){for(int j=h+1;--j;)push(i>>j);}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tvoid upd(int i){while(i>>=1)merge(i);}\n\tsegtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());lz.assign(w,id());}\n\
    \tsegtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int\
    \ i=w;--i;)merge(i);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}\n\
    \tvoid _apply(int l,int r,int i,F f,int L,int R){\n\t\tif(r<=L||R<=l)return;\n\
    \t\tif(L<=l&&r<=R){_apply(i,f);return;}\n\t\tint c=l+r>>1;\n\t\tpush(i),_apply(l,c,i<<1,f,L,R),_apply(c,r,i<<1|1,f,L,R),merge(i);\n\
    \t}\n\tX fold(int l,int r){assert(0<=l&&l<=r&&r<=n);return _fold(0,w,1,l,r);}\n\
    \tX _fold(int l,int r,int i,int L,int R){\n\t\tif(r<=L||R<=l)return e();\n\t\t\
    if(L<=l&&r<=R)return d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);return op(_fold(l,c,i<<1,L,R),_fold(c,r,i<<1|1,L,R));\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int l,G ok){\n\t\tassert(0<=l&&l<=n);\n\
    \t\tX y=e();assert(ok(y));\n\t\treturn min(_max_right(0,w,1,y,ok,l),n);\n\t}\n\
    \ttemplate<class G>\n\tint _max_right(int l,int r,int i,X&y,G ok,int L){\n\t\t\
    if(r<=L)return L;\n\t\tif(L<=l){\n\t\t\tif(ok(op(y,d[i]))){y=op(y,d[i]);return\
    \ r;}\n\t\t\tif(r-l==1)return l;\n\t\t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=_max_right(l,c,i<<1,y,ok,L);\n\
    \t\treturn j<c?j:_max_right(c,r,i<<1|1,y,ok,L);\n\t}\n\ttemplate<class G>\n\t\
    int min_left(int r,G ok){\n\t\tassert(0<=r&&r<=n);\n\t\tX y=e();assert(ok(y));\n\
    \t\treturn _min_left(0,w,1,y,ok,r);\n\t}\n\ttemplate<class G>\n\tint _min_left(int\
    \ l,int r,int i,X&y,G ok,int R){\n\t\tif(R<=l)return R;\n\t\tif(r<=R){\n\t\t\t\
    if(ok(op(d[i],y))){y=op(d[i],y);return l;}\n\t\t\tif(r-l==1)return r;\n\t\t}\n\
    \t\tpush(i);\n\t\tint c=l+r>>1,j=_min_left(c,r,i<<1|1,y,ok,R);\n\t\treturn c<j?j:_min_left(l,c,i<<1,y,ok,R);\n\
    \t}\n};\n"
  code: "//recursive\n//https://atcoder.jp/contests/practice2/submissions/64400765\n\
    //https://atcoder.jp/contests/practice2/submissions/64400783\ntemplate<class X,auto\
    \ op,auto e,class F=X,auto mapping=op,auto composition=op,auto id=e>\nstruct segtree{\n\
    \tint n,w=1,h=0;\n\tvector<X>d;vector<F>lz;\n\tvoid _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\
    \tvoid push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid\
    \ pull(int i){for(int j=h+1;--j;)push(i>>j);}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tvoid upd(int i){while(i>>=1)merge(i);}\n\tsegtree(int n):n(n){while(w<n)w<<=1,h++;d.assign(w+w,e());lz.assign(w,id());}\n\
    \tsegtree(vector<X>a):segtree(a.size()){for(int i=0;i<n;i++)d[w+i]=a[i];for(int\
    \ i=w;--i;)merge(i);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w);d[i]=x;upd(i);}\n\
    \tvoid _apply(int l,int r,int i,F f,int L,int R){\n\t\tif(r<=L||R<=l)return;\n\
    \t\tif(L<=l&&r<=R){_apply(i,f);return;}\n\t\tint c=l+r>>1;\n\t\tpush(i),_apply(l,c,i<<1,f,L,R),_apply(c,r,i<<1|1,f,L,R),merge(i);\n\
    \t}\n\tX fold(int l,int r){assert(0<=l&&l<=r&&r<=n);return _fold(0,w,1,l,r);}\n\
    \tX _fold(int l,int r,int i,int L,int R){\n\t\tif(r<=L||R<=l)return e();\n\t\t\
    if(L<=l&&r<=R)return d[i];\n\t\tint c=l+r>>1;\n\t\tpush(i);return op(_fold(l,c,i<<1,L,R),_fold(c,r,i<<1|1,L,R));\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int l,G ok){\n\t\tassert(0<=l&&l<=n);\n\
    \t\tX y=e();assert(ok(y));\n\t\treturn min(_max_right(0,w,1,y,ok,l),n);\n\t}\n\
    \ttemplate<class G>\n\tint _max_right(int l,int r,int i,X&y,G ok,int L){\n\t\t\
    if(r<=L)return L;\n\t\tif(L<=l){\n\t\t\tif(ok(op(y,d[i]))){y=op(y,d[i]);return\
    \ r;}\n\t\t\tif(r-l==1)return l;\n\t\t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=_max_right(l,c,i<<1,y,ok,L);\n\
    \t\treturn j<c?j:_max_right(c,r,i<<1|1,y,ok,L);\n\t}\n\ttemplate<class G>\n\t\
    int min_left(int r,G ok){\n\t\tassert(0<=r&&r<=n);\n\t\tX y=e();assert(ok(y));\n\
    \t\treturn _min_left(0,w,1,y,ok,r);\n\t}\n\ttemplate<class G>\n\tint _min_left(int\
    \ l,int r,int i,X&y,G ok,int R){\n\t\tif(R<=l)return R;\n\t\tif(r<=R){\n\t\t\t\
    if(ok(op(d[i],y))){y=op(d[i],y);return l;}\n\t\t\tif(r-l==1)return r;\n\t\t}\n\
    \t\tpush(i);\n\t\tint c=l+r>>1,j=_min_left(c,r,i<<1|1,y,ok,R);\n\t\treturn c<j?j:_min_left(l,c,i<<1,y,ok,R);\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250614_3.hpp
  requiredBy: []
  timestamp: '2025-06-14 06:14:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/segtree_lazy_20250614_3.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250614_3.hpp
- /library/work/lib/segtree_lazy_20250614_3.hpp.html
title: work/lib/segtree_lazy_20250614_3.hpp
---
