---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_7_1.test.cpp
    title: work/lib/segtree_lazy_20250614_7_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_7_2.test.cpp
    title: work/lib/segtree_lazy_20250614_7_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_7_3.test.cpp
    title: work/lib/segtree_lazy_20250614_7_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_7_4.test.cpp
    title: work/lib/segtree_lazy_20250614_7_4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/66706854
    - https://atcoder.jp/contests/practice2/submissions/66706958
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250614_7.hpp\"\n//binary search\n\
    //https://atcoder.jp/contests/practice2/submissions/66706958\n//https://atcoder.jp/contests/practice2/submissions/66706854\n\
    template<class X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\n\
    struct segtree_lazy{\n\tint n,w=1;\n\tvector<X>d;\n\tvector<F>lz;\n\tsegtree_lazy(int\
    \ n):n(n){while(w<n)w<<=1;d.assign(w+w,e()),lz.assign(w,id());}\n\tvoid _apply(int\
    \ i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\tvoid push(int\
    \ i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid pull(int i){if(i)for(int\
    \ j=(32-__builtin_clz(i));--j;)push(i>>j);}\n\tvoid upd(int i){while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}\n\
    \tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}\n\tvoid set(int\
    \ i,X x){assert(0<=i&&i<n);pull(i+=w),d[i]=x,upd(i);}\n\tvoid apply(int l,int\
    \ r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;int L=l/(l&-l),R=r/(r&-r)-1;\n\
    \t\tpull(L),pull(R);\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);l>>=1;\n\t\t\
    \tif(r&1)_apply(--r,f);r>>=1;\n\t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX prod(int l,int\
    \ r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);l>>=1;\n\t\
    \t\tif(r&1)vr=op(d[--r],vr);r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t}\n\ttemplate<class\
    \ G>\n\tint max_right(int i,G f){\n\t\tassert(0<=i&&i<=n);\n\t\t//assert(f(e()));//f(e)=false\u3092\
    \u8A31\u5BB9\u3059\u308B\u65B9\u304C\u4F7F\u3044\u52DD\u624B\u304C\u826F\u3044\
    \n\t\tif(i==n)return n;\n\t\tX x=e();\n\t\ti+=w,pull(i/=i&-i);\n\t\twhile(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return\
    \ n;}\n\t\twhile(i<w){push(i);if(f(op(x,d[i<<=1])))x=op(x,d[i++]);}\n\t\tassert(i<w+n);\n\
    \t\treturn i-w;\n\t}\n\ttemplate<class G>\n\tint min_left(int i,G f){\n\t\tassert(0<=i&&i<=n);\n\
    \t\tif(i==0)return 0;\n\t\tX x=e();\n\t\ti+=w,pull(i/=i&-i);\n\t\tif(i==1)i=2;\n\
    \t\twhile(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return 0;}\n\t\twhile(i<=w){push(i-1);if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);}\n\
    \t\tassert(w<i&&i<=w+n);\n\t\treturn i-w;\n\t}\n};\n"
  code: "//binary search\n//https://atcoder.jp/contests/practice2/submissions/66706958\n\
    //https://atcoder.jp/contests/practice2/submissions/66706854\ntemplate<class X,X(*op)(X,X),X(*e)(),\n\
    class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\nstruct segtree_lazy{\n\
    \tint n,w=1;\n\tvector<X>d;\n\tvector<F>lz;\n\tsegtree_lazy(int n):n(n){while(w<n)w<<=1;d.assign(w+w,e()),lz.assign(w,id());}\n\
    \tvoid _apply(int i,F f){d[i]=mapping(f,d[i]);if(i<w)lz[i]=composition(f,lz[i]);}\n\
    \tvoid push(int i){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}\n\tvoid\
    \ pull(int i){if(i)for(int j=(32-__builtin_clz(i));--j;)push(i>>j);}\n\tvoid upd(int\
    \ i){while(i>>=1)d[i]=op(d[i<<1],d[i<<1|1]);}\n\tX operator[](int i){assert(0<=i&&i<n);pull(i+=w);return\
    \ d[i];}\n\tvoid set(int i,X x){assert(0<=i&&i<n);pull(i+=w),d[i]=x,upd(i);}\n\
    \tvoid apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;int\
    \ L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);l>>=1;\n\
    \t\t\tif(r&1)_apply(--r,f);r>>=1;\n\t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX prod(int\
    \ l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);l>>=1;\n\t\
    \t\tif(r&1)vr=op(d[--r],vr);r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t}\n\ttemplate<class\
    \ G>\n\tint max_right(int i,G f){\n\t\tassert(0<=i&&i<=n);\n\t\t//assert(f(e()));//f(e)=false\u3092\
    \u8A31\u5BB9\u3059\u308B\u65B9\u304C\u4F7F\u3044\u52DD\u624B\u304C\u826F\u3044\
    \n\t\tif(i==n)return n;\n\t\tX x=e();\n\t\ti+=w,pull(i/=i&-i);\n\t\twhile(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return\
    \ n;}\n\t\twhile(i<w){push(i);if(f(op(x,d[i<<=1])))x=op(x,d[i++]);}\n\t\tassert(i<w+n);\n\
    \t\treturn i-w;\n\t}\n\ttemplate<class G>\n\tint min_left(int i,G f){\n\t\tassert(0<=i&&i<=n);\n\
    \t\tif(i==0)return 0;\n\t\tX x=e();\n\t\ti+=w,pull(i/=i&-i);\n\t\tif(i==1)i=2;\n\
    \t\twhile(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return 0;}\n\t\twhile(i<=w){push(i-1);if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);}\n\
    \t\tassert(w<i&&i<=w+n);\n\t\treturn i-w;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250614_7.hpp
  requiredBy: []
  timestamp: '2025-06-14 12:19:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250614_7_4.test.cpp
  - work/lib/segtree_lazy_20250614_7_2.test.cpp
  - work/lib/segtree_lazy_20250614_7_1.test.cpp
  - work/lib/segtree_lazy_20250614_7_3.test.cpp
documentation_of: work/lib/segtree_lazy_20250614_7.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250614_7.hpp
- /library/work/lib/segtree_lazy_20250614_7.hpp.html
title: work/lib/segtree_lazy_20250614_7.hpp
---
