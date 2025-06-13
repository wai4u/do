---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/1.cpp
    title: work/1.cpp
  - icon: ':warning:'
    path: work/cp/segtree_lazy.hpp
    title: work/cp/segtree_lazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_1.test.cpp
    title: work/lib/segtree_lazy_20250612_1_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_2.test.cpp
    title: work/lib/segtree_lazy_20250612_1_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_3.test.cpp
    title: work/lib/segtree_lazy_20250612_1_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_4.test.cpp
    title: work/lib/segtree_lazy_20250612_1_4.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_5.test.cpp
    title: work/lib/segtree_lazy_20250612_1_5.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_6.test.cpp
    title: work/lib/segtree_lazy_20250612_1_6.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_7.test.cpp
    title: work/lib/segtree_lazy_20250612_1_7.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_8.test.cpp
    title: work/lib/segtree_lazy_20250612_1_8.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250612_1_9.test.cpp
    title: work/lib/segtree_lazy_20250612_1_9.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/66685138
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250612_1.hpp\"\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n//https://atcoder.jp/contests/practice2/submissions/66685138\n\
    template<\nclass X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,\nF(*composition)(F,F)=op,F(*id)()=e\n\
    >\nstruct segtree_lazy{\n\tint n=0,w=0;\n\tvector<X>d;\n\tvector<F>lz;\n\tbool\
    \ built=0,hung=0;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\ttemplate<class\
    \ G>\n\tsegtree_lazy(int n,G f){init(n,f);}\n\ttemplate<class U>\n\tsegtree_lazy(const\
    \ vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\tw=1;while(w<n)w<<=1;\n\
    \t\td.assign(w+w,e());\n\t\tlz.assign(w,id());\n\t\thung=built=0;\n\t}\n\ttemplate<class\
    \ G>\n\tvoid init(int n,G f){\n\t\tinit(n);\n\t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\
    \t}\n\ttemplate<class U>\n\tvoid init(const vector<U>&a){\n\t\tinit(a.size(),[&](int\
    \ i){return a[i];});\n\t}\n\tvoid _apply(int i,F f){\n\t\t//d[i]=mapping(f,d[i]);\n\
    \t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){\n\t\t_apply(i<<1,lz[i]);\n\t\t_apply(i<<1|1,lz[i]);\n\
    \t\tlz[i]=id();\n\t}\n\tvoid pull(int i){\n\t\tif(!i)return;\n\t\tfor(int j=(32-__builtin_clz(i));--j;)push(i>>j);\n\
    \t}\n\tvoid update_all(){\n\t\tif(!hung)return;\n\t\thung=0;\n\t\tfor(int i=1;i<w;i++)push(i);\n\
    \t}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){while(i>>=1)merge(i);}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tif(hung)update_all();\n\t\tbuilt=1;\n\
    \t\tfor(int i=w;--i;)merge(i);\n\t\t/*\n\t\tbuilt=1;\n\t\tfor(int i=w;--i;){\n\
    \t\t\tmerge(i);\n\t\t\td[i]=mapping(lz[i],d[i]);\n\t\t}\n\t\t*/\n\t}\n\tconst\
    \ X&get(int i){\n\t\tassert(0<=i&&i<n);\n\t\ti+=w;\n\t\tif(hung)pull(i);\n\t\t\
    return d[i];\n\t}\n\tconst X&operator[](int i){return get(i);}\n\tvector<X>get_all(){\n\
    \t\tupdate_all();\n\t\treturn{d.begin()+w,d.begin()+w+n};\n\t}\n\tvoid set(int\
    \ i,X x){\n\t\tget(i);\n\t\td[i+w]=x;\n\t\tif(built)upd(i+w);\n\t}\n\tvoid apply(int\
    \ i,F f){\n\t\tget(i);\n\t\t_apply(i+w,f);\n\t\tif(built)upd(i+w);\n\t}\n\tvoid\
    \ apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\
    \t\tif(l+1==r)return apply(l,f);\n\t\tl+=w,r+=w;\n\t\tint L=l/(l&-l),R=r/(r&-r)-1;\n\
    \t\tif(hung)pull(L),pull(R);\n\t\thung=1;\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);\n\
    \t\t\tif(r&1)_apply(--r,f);\n\t\t\tl>>=1,r>>=1;\n\t\t}\n\t\tif(built)upd(L),upd(R);\n\
    \t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return\
    \ e();\n\t\tif(l+1==r)return get(l);\n\t\tl+=w,r+=w;\n\t\tbuild();\n\t\tif(hung)pull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);\n\t\t\t\
    if(r&1)vr=op(d[--r],vr);\n\t\t\tl>>=1,r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t\
    }\n};\n"
  code: "//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n\
    //https://atcoder.jp/contests/practice2/submissions/66685138\ntemplate<\nclass\
    \ X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,\nF(*composition)(F,F)=op,F(*id)()=e\n\
    >\nstruct segtree_lazy{\n\tint n=0,w=0;\n\tvector<X>d;\n\tvector<F>lz;\n\tbool\
    \ built=0,hung=0;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\ttemplate<class\
    \ G>\n\tsegtree_lazy(int n,G f){init(n,f);}\n\ttemplate<class U>\n\tsegtree_lazy(const\
    \ vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\tw=1;while(w<n)w<<=1;\n\
    \t\td.assign(w+w,e());\n\t\tlz.assign(w,id());\n\t\thung=built=0;\n\t}\n\ttemplate<class\
    \ G>\n\tvoid init(int n,G f){\n\t\tinit(n);\n\t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\
    \t}\n\ttemplate<class U>\n\tvoid init(const vector<U>&a){\n\t\tinit(a.size(),[&](int\
    \ i){return a[i];});\n\t}\n\tvoid _apply(int i,F f){\n\t\t//d[i]=mapping(f,d[i]);\n\
    \t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){\n\t\t_apply(i<<1,lz[i]);\n\t\t_apply(i<<1|1,lz[i]);\n\
    \t\tlz[i]=id();\n\t}\n\tvoid pull(int i){\n\t\tif(!i)return;\n\t\tfor(int j=(32-__builtin_clz(i));--j;)push(i>>j);\n\
    \t}\n\tvoid update_all(){\n\t\tif(!hung)return;\n\t\thung=0;\n\t\tfor(int i=1;i<w;i++)push(i);\n\
    \t}\n\tvoid merge(int i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){while(i>>=1)merge(i);}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tif(hung)update_all();\n\t\tbuilt=1;\n\
    \t\tfor(int i=w;--i;)merge(i);\n\t\t/*\n\t\tbuilt=1;\n\t\tfor(int i=w;--i;){\n\
    \t\t\tmerge(i);\n\t\t\td[i]=mapping(lz[i],d[i]);\n\t\t}\n\t\t*/\n\t}\n\tconst\
    \ X&get(int i){\n\t\tassert(0<=i&&i<n);\n\t\ti+=w;\n\t\tif(hung)pull(i);\n\t\t\
    return d[i];\n\t}\n\tconst X&operator[](int i){return get(i);}\n\tvector<X>get_all(){\n\
    \t\tupdate_all();\n\t\treturn{d.begin()+w,d.begin()+w+n};\n\t}\n\tvoid set(int\
    \ i,X x){\n\t\tget(i);\n\t\td[i+w]=x;\n\t\tif(built)upd(i+w);\n\t}\n\tvoid apply(int\
    \ i,F f){\n\t\tget(i);\n\t\t_apply(i+w,f);\n\t\tif(built)upd(i+w);\n\t}\n\tvoid\
    \ apply(int l,int r,F f){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\
    \t\tif(l+1==r)return apply(l,f);\n\t\tl+=w,r+=w;\n\t\tint L=l/(l&-l),R=r/(r&-r)-1;\n\
    \t\tif(hung)pull(L),pull(R);\n\t\thung=1;\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);\n\
    \t\t\tif(r&1)_apply(--r,f);\n\t\t\tl>>=1,r>>=1;\n\t\t}\n\t\tif(built)upd(L),upd(R);\n\
    \t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return\
    \ e();\n\t\tif(l+1==r)return get(l);\n\t\tl+=w,r+=w;\n\t\tbuild();\n\t\tif(hung)pull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\t\tif(l&1)vl=op(vl,d[l++]);\n\t\t\t\
    if(r&1)vr=op(d[--r],vr);\n\t\t\tl>>=1,r>>=1;\n\t\t}\n\t\treturn op(vl,vr);\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250612_1.hpp
  requiredBy:
  - work/1.cpp
  - work/cp/segtree_lazy.hpp
  timestamp: '2025-06-13 09:18:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250612_1_2.test.cpp
  - work/lib/segtree_lazy_20250612_1_5.test.cpp
  - work/lib/segtree_lazy_20250612_1_3.test.cpp
  - work/lib/segtree_lazy_20250612_1_9.test.cpp
  - work/lib/segtree_lazy_20250612_1_1.test.cpp
  - work/lib/segtree_lazy_20250612_1_4.test.cpp
  - work/lib/segtree_lazy_20250612_1_8.test.cpp
  - work/lib/segtree_lazy_20250612_1_6.test.cpp
  - work/lib/segtree_lazy_20250612_1_7.test.cpp
documentation_of: work/lib/segtree_lazy_20250612_1.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250612_1.hpp
- /library/work/lib/segtree_lazy_20250612_1.hpp.html
title: work/lib/segtree_lazy_20250612_1.hpp
---
