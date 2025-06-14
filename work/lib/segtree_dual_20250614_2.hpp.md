---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/1.cpp
    title: work/1.cpp
  - icon: ':warning:'
    path: work/cp/segtree_dual.hpp
    title: work/cp/segtree_dual.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250614_2_1.test.cpp
    title: work/lib/segtree_dual_20250614_2_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250614_2_2.test.cpp
    title: work/lib/segtree_dual_20250614_2_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_dual_20250614_2_3.test.cpp
    title: work/lib/segtree_dual_20250614_2_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"work/lib/segtree_dual_20250614_2.hpp\"\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n=0,w=0;\n\tvector<T>d;\n\
    \tbool hung=0;\n\tsegtree_dual(){}\n\tsegtree_dual(int n){init(n);}\n\ttemplate<class\
    \ F>segtree_dual(int n,F f){init(n,f);}\n\ttemplate<class U>segtree_dual(const\
    \ vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\tw=1;while(w<n)w<<=1;\n\
    \t\td.assign(w+w,e());\n\t\thung=0;\n\t}\n\ttemplate<class F>void init(int n,F\
    \ f){\n\t\tinit(n);for(int i=0;i<n;i++)d[w+i]=f(i);\n\t}\n\ttemplate<class U>void\
    \ init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\
    \tvoid _apply(int i,T x){d[i]=op(d[i],x);}\n\tvoid push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}\n\
    \tvoid pull(int i){if(hung&&i)for(int j=(32-__builtin_clz(i));--j;)push(i>>j);}\n\
    \tvoid pull_all(){if(hung)for(int i=1;i<w;i++)push(i);hung=0;}\n\tvector<T>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}\n\
    \tT&get(int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}\n\tT&operator[](int\
    \ i){return get(i);}\n\tvoid set(int i,T x){get(i)=x;}\n\tvoid apply(int i,T x){T&y=get(i);y=op(y,x);}\n\
    \tvoid apply(int l,int r,T x){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\
    \t\tif(l+1==r)return apply(l,x);\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\thung=1;\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,x);\n\t\t\tif(r&1)_apply(--r,x);\n\
    \t\t\tl>>=1,r>>=1;\n\t\t}\n\t}\n};\n"
  code: "//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n\
    template<class T,T(*op)(T,T),T(*e)()>\nstruct segtree_dual{\n\tint n=0,w=0;\n\t\
    vector<T>d;\n\tbool hung=0;\n\tsegtree_dual(){}\n\tsegtree_dual(int n){init(n);}\n\
    \ttemplate<class F>segtree_dual(int n,F f){init(n,f);}\n\ttemplate<class U>segtree_dual(const\
    \ vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\tw=1;while(w<n)w<<=1;\n\
    \t\td.assign(w+w,e());\n\t\thung=0;\n\t}\n\ttemplate<class F>void init(int n,F\
    \ f){\n\t\tinit(n);for(int i=0;i<n;i++)d[w+i]=f(i);\n\t}\n\ttemplate<class U>void\
    \ init(const vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\
    \tvoid _apply(int i,T x){d[i]=op(d[i],x);}\n\tvoid push(int i){_apply(i<<1,d[i]),_apply(i<<1|1,d[i]),d[i]=e();}\n\
    \tvoid pull(int i){if(hung&&i)for(int j=(32-__builtin_clz(i));--j;)push(i>>j);}\n\
    \tvoid pull_all(){if(hung)for(int i=1;i<w;i++)push(i);hung=0;}\n\tvector<T>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}\n\
    \tT&get(int i){assert(0<=i&&i<n);pull(i+=w);return d[i];}\n\tT&operator[](int\
    \ i){return get(i);}\n\tvoid set(int i,T x){get(i)=x;}\n\tvoid apply(int i,T x){T&y=get(i);y=op(y,x);}\n\
    \tvoid apply(int l,int r,T x){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\
    \t\tif(l+1==r)return apply(l,x);\n\t\tl+=w,r+=w;\n\t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\
    \t\thung=1;\n\t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,x);\n\t\t\tif(r&1)_apply(--r,x);\n\
    \t\t\tl>>=1,r>>=1;\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_dual_20250614_2.hpp
  requiredBy:
  - work/1.cpp
  - work/cp/segtree_dual.hpp
  timestamp: '2025-06-14 18:00:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_dual_20250614_2_1.test.cpp
  - work/lib/segtree_dual_20250614_2_3.test.cpp
  - work/lib/segtree_dual_20250614_2_2.test.cpp
documentation_of: work/lib/segtree_dual_20250614_2.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_dual_20250614_2.hpp
- /library/work/lib/segtree_dual_20250614_2.hpp.html
title: work/lib/segtree_dual_20250614_2.hpp
---
