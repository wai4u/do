---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_10_1.test.cpp
    title: work/lib/segtree_lazy_20250614_10_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_10_2.test.cpp
    title: work/lib/segtree_lazy_20250614_10_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_10_3.test.cpp
    title: work/lib/segtree_lazy_20250614_10_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/segtree_lazy_20250614_10_4.test.cpp
    title: work/lib/segtree_lazy_20250614_10_4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/practice2/submissions/66709750
    - https://atcoder.jp/contests/practice2/submissions/66709756
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"work/lib/segtree_lazy_20250614_10.hpp\"\n//lazy build/apply-hanging\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n\
    //https://atcoder.jp/contests/practice2/submissions/66709756\n//https://atcoder.jp/contests/practice2/submissions/66709750\n\
    template<\nclass X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,\nF(*composition)(F,F)=op,F(*id)()=e\n\
    >\nstruct segtree_lazy{\n\tint n=0,w=0,h=0;\n\tvector<X>d;\n\tvector<F>lz;\n\t\
    bool built=0,hung=0;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\t\
    template<class G>\n\tsegtree_lazy(int n,G f){init(n,f);}\n\ttemplate<class U>\n\
    \tsegtree_lazy(const vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\
    \t\tw=h=1;while(w<n)w<<=1,++h;\n\t\td.assign(w+w,e());\n\t\tlz.assign(w,id());\n\
    \t\thung=built=0;\n\t}\n\ttemplate<class G>\n\tvoid init(int n,G f){\n\t\tinit(n);\n\
    \t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\t}\n\ttemplate<class U>\n\tvoid init(const\
    \ vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\tvoid merge(int\
    \ i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){if(built)while(i>>=1)merge(i);}\n\
    \tvoid _apply(int i,F f){\n\t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){\n\t\t//if(lz[i]==id())return;//operator==\u304C\u306A\
    \u3044\u3068\u3060\u3081\n\t\tif(!hung)return;\n\t\t_apply(i<<1,lz[i]);\n\t\t\
    _apply(i<<1|1,lz[i]);\n\t\tlz[i]=id();\n\t}\n\tvoid pull(int i,int j=-1){\n\t\t\
    if(!hung||!i)return;\n\t\tif(j==-1)j=32-__builtin_clz(i);\n\t\twhile(--j>0)push(i>>j);\n\
    \t}\n\tvoid pull_all(){if(hung){for(int i=1;i<w;i++)push(i);hung=0;}}\n\tvector<X>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tpull_all();\n\t\tfor(int i=w;--i;)merge(i);\n\
    \t\tbuilt=1;\n\t}\n\tvoid pull_leaf(int i){assert(0<=i&&i<n);pull(i+w,h);}\n\t\
    const X&get(int i){pull_leaf(i);return d[i+w];}\n\tconst X&operator[](int i){return\
    \ get(i);}\n\tvoid set(int i,X x){pull_leaf(i),d[i+=w]=x,upd(i);}\n\tvoid apply(int\
    \ i,F f){pull_leaf(i),_apply(i+=w,f),upd(i);}\n\tvoid apply(int l,int r,F f){\n\
    \t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\t\tif(l+1==r)return apply(l,f);\n\
    \t\tl+=w,r+=w;\n\t\tint L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\t\thung=1;\n\
    \t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);\n\t\t\tif(r&1)_apply(--r,f);\n\t\t\
    \tl>>=1,r>>=1;\n\t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return e();\n\t\tif(l+1==r)return get(l);\n\t\tl+=w,r+=w;\n\t\tbuild();\n\
    \t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\
    \t\tif(l&1)vl=op(vl,d[l++]);\n\t\t\tif(r&1)vr=op(d[--r],vr);\n\t\t\tl>>=1,r>>=1;\n\
    \t\t}\n\t\treturn op(vl,vr);\n\t}\n\ttemplate<class G>\n\tint max_right(int i,G\
    \ f){\n\t\tassert(0<=i&&i<=n);\n\t\tif(i==n)return n;\n\t\tbuild();\n\t\tX x=e();\n\
    \t\ti+=w,pull(i/=i&-i);\n\t\twhile(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return\
    \ n;}\n\t\twhile(i<w){push(i);if(f(op(x,d[i<<=1])))x=op(x,d[i++]);}\n\t\tassert(i<w+n);\n\
    \t\treturn i-w;\n\t}\n\ttemplate<class G>\n\tint min_left(int i,G f){\n\t\tassert(0<=i&&i<=n);\n\
    \t\tif(i==0)return 0;\n\t\tbuild();\n\t\tX x=e();\n\t\ti+=w,pull(i/=i&-i);\n\t\
    \tif(i==1)i=2;\n\t\twhile(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return\
    \ 0;}\n\t\twhile(i<=w){push(i-1);if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);}\n\t\
    \tassert(w<i&&i<=w+n);\n\t\treturn i-w;\n\t}\n};\n"
  code: "//lazy build/apply-hanging\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\n//https://atcoder.jp/contests/practice2/submissions/66709756\n\
    //https://atcoder.jp/contests/practice2/submissions/66709750\ntemplate<\nclass\
    \ X,X(*op)(X,X),X(*e)(),\nclass F=X,X(*mapping)(F,X)=op,\nF(*composition)(F,F)=op,F(*id)()=e\n\
    >\nstruct segtree_lazy{\n\tint n=0,w=0,h=0;\n\tvector<X>d;\n\tvector<F>lz;\n\t\
    bool built=0,hung=0;\n\tsegtree_lazy(){}\n\tsegtree_lazy(int n){init(n);}\n\t\
    template<class G>\n\tsegtree_lazy(int n,G f){init(n,f);}\n\ttemplate<class U>\n\
    \tsegtree_lazy(const vector<U>&a){init(a);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\
    \t\tw=h=1;while(w<n)w<<=1,++h;\n\t\td.assign(w+w,e());\n\t\tlz.assign(w,id());\n\
    \t\thung=built=0;\n\t}\n\ttemplate<class G>\n\tvoid init(int n,G f){\n\t\tinit(n);\n\
    \t\tfor(int i=0;i<n;i++)d[w+i]=f(i);\n\t}\n\ttemplate<class U>\n\tvoid init(const\
    \ vector<U>&a){\n\t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\tvoid merge(int\
    \ i){d[i]=op(d[i<<1],d[i<<1|1]);}\n\tvoid upd(int i){if(built)while(i>>=1)merge(i);}\n\
    \tvoid _apply(int i,F f){\n\t\tif(built||i>=w)d[i]=mapping(f,d[i]);\n\t\tif(i<w)lz[i]=composition(f,lz[i]);\n\
    \t}\n\tvoid push(int i){\n\t\t//if(lz[i]==id())return;//operator==\u304C\u306A\
    \u3044\u3068\u3060\u3081\n\t\tif(!hung)return;\n\t\t_apply(i<<1,lz[i]);\n\t\t\
    _apply(i<<1|1,lz[i]);\n\t\tlz[i]=id();\n\t}\n\tvoid pull(int i,int j=-1){\n\t\t\
    if(!hung||!i)return;\n\t\tif(j==-1)j=32-__builtin_clz(i);\n\t\twhile(--j>0)push(i>>j);\n\
    \t}\n\tvoid pull_all(){if(hung){for(int i=1;i<w;i++)push(i);hung=0;}}\n\tvector<X>get_all(){pull_all();return{d.begin()+w,d.begin()+w+n};}\n\
    \tvoid build(){\n\t\tif(built)return;\n\t\tpull_all();\n\t\tfor(int i=w;--i;)merge(i);\n\
    \t\tbuilt=1;\n\t}\n\tvoid pull_leaf(int i){assert(0<=i&&i<n);pull(i+w,h);}\n\t\
    const X&get(int i){pull_leaf(i);return d[i+w];}\n\tconst X&operator[](int i){return\
    \ get(i);}\n\tvoid set(int i,X x){pull_leaf(i),d[i+=w]=x,upd(i);}\n\tvoid apply(int\
    \ i,F f){pull_leaf(i),_apply(i+=w,f),upd(i);}\n\tvoid apply(int l,int r,F f){\n\
    \t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\t\tif(l+1==r)return apply(l,f);\n\
    \t\tl+=w,r+=w;\n\t\tint L=l/(l&-l),R=r/(r&-r)-1;\n\t\tpull(L),pull(R);\n\t\thung=1;\n\
    \t\twhile(l<r){\n\t\t\tif(l&1)_apply(l++,f);\n\t\t\tif(r&1)_apply(--r,f);\n\t\t\
    \tl>>=1,r>>=1;\n\t\t}\n\t\tupd(L),upd(R);\n\t}\n\tX prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return e();\n\t\tif(l+1==r)return get(l);\n\t\tl+=w,r+=w;\n\t\tbuild();\n\
    \t\tpull(l/(l&-l)),pull(r/(r&-r)-1);\n\t\tX vl=e(),vr=e();\n\t\twhile(l<r){\n\t\
    \t\tif(l&1)vl=op(vl,d[l++]);\n\t\t\tif(r&1)vr=op(d[--r],vr);\n\t\t\tl>>=1,r>>=1;\n\
    \t\t}\n\t\treturn op(vl,vr);\n\t}\n\ttemplate<class G>\n\tint max_right(int i,G\
    \ f){\n\t\tassert(0<=i&&i<=n);\n\t\tif(i==n)return n;\n\t\tbuild();\n\t\tX x=e();\n\
    \t\ti+=w,pull(i/=i&-i);\n\t\twhile(f(op(x,d[i]))){x=op(x,d[i++]);if((i/=i&-i)==1)return\
    \ n;}\n\t\twhile(i<w){push(i);if(f(op(x,d[i<<=1])))x=op(x,d[i++]);}\n\t\tassert(i<w+n);\n\
    \t\treturn i-w;\n\t}\n\ttemplate<class G>\n\tint min_left(int i,G f){\n\t\tassert(0<=i&&i<=n);\n\
    \t\tif(i==0)return 0;\n\t\tbuild();\n\t\tX x=e();\n\t\ti+=w,pull(i/=i&-i);\n\t\
    \tif(i==1)i=2;\n\t\twhile(f(op(d[i-1],x))){x=op(d[--i],x);if((i/=i&-i)==1)return\
    \ 0;}\n\t\twhile(i<=w){push(i-1);if(f(op(d[(i<<=1)-1],x)))x=op(d[--i],x);}\n\t\
    \tassert(w<i&&i<=w+n);\n\t\treturn i-w;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/segtree_lazy_20250614_10.hpp
  requiredBy: []
  timestamp: '2025-06-14 14:40:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/segtree_lazy_20250614_10_1.test.cpp
  - work/lib/segtree_lazy_20250614_10_4.test.cpp
  - work/lib/segtree_lazy_20250614_10_2.test.cpp
  - work/lib/segtree_lazy_20250614_10_3.test.cpp
documentation_of: work/lib/segtree_lazy_20250614_10.hpp
layout: document
redirect_from:
- /library/work/lib/segtree_lazy_20250614_10.hpp
- /library/work/lib/segtree_lazy_20250614_10.hpp.html
title: work/lib/segtree_lazy_20250614_10.hpp
---
