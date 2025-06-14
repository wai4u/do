---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/1.cpp
    title: work/1.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_11_1.test.cpp
    title: work/lib/segtree_lazy_20250614_11_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_11_2.test.cpp
    title: work/lib/segtree_lazy_20250614_11_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_11_3.test.cpp
    title: work/lib/segtree_lazy_20250614_11_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_11_4.test.cpp
    title: work/lib/segtree_lazy_20250614_11_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_11_5.test.cpp
    title: work/lib/segtree_lazy_20250614_11_5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/66711863
    - https://atcoder.jp/contests/practice2/submissions/66711875
    - https://atcoder.jp/contests/practice2/submissions/66714342
    - https://judge.yosupo.jp/submission/292924
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250614_11.hpp\"\n//https://atcoder.jp/contests/practice2/submissions/66711875\n\
    //https://atcoder.jp/contests/practice2/submissions/66711863\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n//https://judge.yosupo.jp/submission/292924\n\
    //https://atcoder.jp/contests/practice2/submissions/66714342\ntemplate<class X,X(*op)(X,X),X(*e)(),class\
    \ F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\nstruct segtree_lazy{\n\
    \tint n=0,w=0,h=0;\n\tvector<X>d;vector<F>lz;\n\tbool built=0,hung=0;\n\tsegtree_lazy(){}\n\
    \tsegtree_lazy(int n){init(n);}\n\ttemplate<class G>\n\tsegtree_lazy(int n,G f){init(n,f);}\n\
    \ttemplate<class U>\n\tsegtree_lazy(const vector<U>&a){init(a);}\n\tvoid init(int\
    \ n){\n\t\tthis->n=n;\n\t\tw=h=1;while(w<n)w<<=1,++h;\n\t\td.assign(w+w,e());\n\
    \t\tlz.assign(w,id());\n\t\thung=built=0;\n\t}\n\ttemplate<class G>\n\tvoid init(int\
    \ n,G f){\n\t\tinit(n);\n\t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\t}\n\ttemplate<class\
    \ U>\n\tvoid init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\
    \t}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){if(built)while(i>>=1)merge(i);}\n\
    \tvoid _apply(int i,F f){\n\t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){if(hung){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}}\n\
    \tvoid pull(int i){assert(0<=i&&i<n);if(hung){i+=w;for(int j=h;--j;)push(i>>j);}}\n\
    \tvoid pull_all(){if(hung){for(int i=1;i<w;i++)push(i);hung=0;}}\n\tvector<X>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tpull_all();\n\t\tfor(int i=w;--i;)merge(i);\n\
    \t\tbuilt=1;\n\t}\n\tvoid set(int i,X x){pull(i),d[i+=w]=x,upd(i);}\n\tvoid apply(int\
    \ i,F f){pull(i),_apply(i+=w,f),upd(i);}\n\tconst X&get(int i){pull(i);return\
    \ d[i+w];}\n\tconst X&operator[](int i){return get(i);}\n\tvoid apply(int l,int\
    \ r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\t\tif(l+1==r)return\
    \ apply(l,f);\n\t\tapply(l,r,f,1,0,w);\n\t\thung=1;\n\t}\n\tvoid apply(int L,int\
    \ R,const F&f,int i,int l,int r){\n\t\tif(L<=l&&r<=R)return _apply(i,f);\n\t\t\
    int c=l+r>>1;\n\t\tpush(i);\n\t\tif(L<c)apply(L,R,f,i<<1,l,c);\n\t\tif(c<R)apply(L,R,f,i<<1|1,c,r);\n\
    \t\tmerge(i);\n\t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\t\
    if(l==r)return e();\n\t\tif(l+1==r)return get(l);\n\t\tbuild();\n\t\treturn prod(l,r,1,0,w);\n\
    \t}\n\tX prod(int L,int R,int i,int l,int r){\n\t\tif(L<=l&&r<=R)return d[i];\n\
    \t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tif(R<=c)return prod(L,R,i<<1,l,c);\n\t\t\
    if(c<=L)return prod(L,R,i<<1|1,c,r);\n\t\treturn op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int l,G f){\n\t\tassert(0<=l&&l<=n);\n\
    \t\tif(l==n)return n;\n\t\tbuild();\n\t\tX x=e();\n\t\treturn max_right(l,f,x,1,0,w);\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int L,G f,X&x,int i,int l,int r){\n\t\
    \tif(L<=l){\n\t\t\tif(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}\n\t\t\tif(l+1==r)return\
    \ l;\n\t\t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=c<=L?L:max_right(L,f,x,i<<1,l,c);\n\
    \t\treturn j<c||j==n?j:max_right(L,f,x,i<<1|1,c,r);\n\t}\n\ttemplate<class G>\n\
    \tint min_left(int r,G f){\n\t\tassert(0<=r&&r<=n);\n\t\tif(r==0)return 0;\n\t\
    \tbuild();\n\t\tX x=e();\n\t\treturn min_left(r,f,x,1,0,w);\n\t}\n\ttemplate<class\
    \ G>\n\tint min_left(int R,G f,X&x,int i,int l,int r){\n\t\tif(r<=R){\n\t\t\t\
    if(f(op(d[i],x))){x=op(d[i],x);return l;}\n\t\t\tif(l+1==r)return r;\n\t\t}\n\t\
    \tpush(i);\n\t\tint c=l+r>>1,j=R<=c?R:min_left(R,f,x,i<<1|1,c,r);\n\t\treturn\
    \ c<j?j:min_left(R,f,x,i<<1,l,c);\n\t}\n};\n"
  code: "//https://atcoder.jp/contests/practice2/submissions/66711875\n//https://atcoder.jp/contests/practice2/submissions/66711863\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n\
    //https://judge.yosupo.jp/submission/292924\n//https://atcoder.jp/contests/practice2/submissions/66714342\n\
    template<class X,X(*op)(X,X),X(*e)(),class F=X,X(*mapping)(F,X)=op,F(*composition)(F,F)=op,F(*id)()=e>\n\
    struct segtree_lazy{\n\tint n=0,w=0,h=0;\n\tvector<X>d;vector<F>lz;\n\tbool built=0,hung=0;\n\
    \tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\ttemplate<class G>\n\tsegtree_lazy(int\
    \ n,G f){init(n,f);}\n\ttemplate<class U>\n\tsegtree_lazy(const vector<U>&a){init(a);}\n\
    \tvoid init(int n){\n\t\tthis->n=n;\n\t\tw=h=1;while(w<n)w<<=1,++h;\n\t\td.assign(w+w,e());\n\
    \t\tlz.assign(w,id());\n\t\thung=built=0;\n\t}\n\ttemplate<class G>\n\tvoid init(int\
    \ n,G f){\n\t\tinit(n);\n\t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\t}\n\ttemplate<class\
    \ U>\n\tvoid init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\
    \t}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){if(built)while(i>>=1)merge(i);}\n\
    \tvoid _apply(int i,F f){\n\t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){if(hung){_apply(i<<1,lz[i]),_apply(i<<1|1,lz[i]),lz[i]=id();}}\n\
    \tvoid pull(int i){assert(0<=i&&i<n);if(hung){i+=w;for(int j=h;--j;)push(i>>j);}}\n\
    \tvoid pull_all(){if(hung){for(int i=1;i<w;i++)push(i);hung=0;}}\n\tvector<X>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tpull_all();\n\t\tfor(int i=w;--i;)merge(i);\n\
    \t\tbuilt=1;\n\t}\n\tvoid set(int i,X x){pull(i),d[i+=w]=x,upd(i);}\n\tvoid apply(int\
    \ i,F f){pull(i),_apply(i+=w,f),upd(i);}\n\tconst X&get(int i){pull(i);return\
    \ d[i+w];}\n\tconst X&operator[](int i){return get(i);}\n\tvoid apply(int l,int\
    \ r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\t\tif(l+1==r)return\
    \ apply(l,f);\n\t\tapply(l,r,f,1,0,w);\n\t\thung=1;\n\t}\n\tvoid apply(int L,int\
    \ R,const F&f,int i,int l,int r){\n\t\tif(L<=l&&r<=R)return _apply(i,f);\n\t\t\
    int c=l+r>>1;\n\t\tpush(i);\n\t\tif(L<c)apply(L,R,f,i<<1,l,c);\n\t\tif(c<R)apply(L,R,f,i<<1|1,c,r);\n\
    \t\tmerge(i);\n\t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\t\
    if(l==r)return e();\n\t\tif(l+1==r)return get(l);\n\t\tbuild();\n\t\treturn prod(l,r,1,0,w);\n\
    \t}\n\tX prod(int L,int R,int i,int l,int r){\n\t\tif(L<=l&&r<=R)return d[i];\n\
    \t\tint c=l+r>>1;\n\t\tpush(i);\n\t\tif(R<=c)return prod(L,R,i<<1,l,c);\n\t\t\
    if(c<=L)return prod(L,R,i<<1|1,c,r);\n\t\treturn op(prod(L,R,i<<1,l,c),prod(L,R,i<<1|1,c,r));\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int l,G f){\n\t\tassert(0<=l&&l<=n);\n\
    \t\tif(l==n)return n;\n\t\tbuild();\n\t\tX x=e();\n\t\treturn max_right(l,f,x,1,0,w);\n\
    \t}\n\ttemplate<class G>\n\tint max_right(int L,G f,X&x,int i,int l,int r){\n\t\
    \tif(L<=l){\n\t\t\tif(f(op(x,d[i]))){x=op(x,d[i]);return min(r,n);}\n\t\t\tif(l+1==r)return\
    \ l;\n\t\t}\n\t\tpush(i);\n\t\tint c=l+r>>1,j=c<=L?L:max_right(L,f,x,i<<1,l,c);\n\
    \t\treturn j<c||j==n?j:max_right(L,f,x,i<<1|1,c,r);\n\t}\n\ttemplate<class G>\n\
    \tint min_left(int r,G f){\n\t\tassert(0<=r&&r<=n);\n\t\tif(r==0)return 0;\n\t\
    \tbuild();\n\t\tX x=e();\n\t\treturn min_left(r,f,x,1,0,w);\n\t}\n\ttemplate<class\
    \ G>\n\tint min_left(int R,G f,X&x,int i,int l,int r){\n\t\tif(r<=R){\n\t\t\t\
    if(f(op(d[i],x))){x=op(d[i],x);return l;}\n\t\t\tif(l+1==r)return r;\n\t\t}\n\t\
    \tpush(i);\n\t\tint c=l+r>>1,j=R<=c?R:min_left(R,f,x,i<<1|1,c,r);\n\t\treturn\
    \ c<j?j:min_left(R,f,x,i<<1,l,c);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250614_11.hpp
  requiredBy:
  - work/1.cpp
  timestamp: '2025-06-14 18:32:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250614_11_3.test.cpp
  - work/lib/segtree_lazy_20250614_11_4.test.cpp
  - work/lib/segtree_lazy_20250614_11_1.test.cpp
  - work/lib/segtree_lazy_20250614_11_5.test.cpp
  - work/lib/segtree_lazy_20250614_11_2.test.cpp
documentation_of: work/lib/segtree_lazy_20250614_11.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250614_11.hpp
- /library/work/lib/segtree_lazy_20250614_11.hpp.html
title: work/lib/segtree_lazy_20250614_11.hpp
---
