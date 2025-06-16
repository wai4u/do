---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/sqrt_bucket_dual_20250616_2_1.test.cpp
    title: work/lib/sqrt_bucket_dual_20250616_2_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: work/lib/sqrt_bucket_dual_20250616_2_2.test.cpp
    title: work/lib/sqrt_bucket_dual_20250616_2_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"work/lib/sqrt_bucket_dual_20250616_2.hpp\"\n//non commutative\
    \ monoid\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    template<class T,T(*op)(T,T),T(*e)()>\nstruct sqrt_bucket_dual{\n\tint n,m=0;\n\
    \tvector<T>a,s;\n\tsqrt_bucket_dual(int n):n(n),a(n,e()){while(m*m<n)m++;s.assign(m,e());}\n\
    \tvoid push(int j){\n\t\tfor(int i=j*m;i<(j+1)*m;i++)a[i]=op(a[i],s[j]);\n\t\t\
    s[j]=e();\n\t}\n\tvoid apply(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\tpush(i/m);\n\
    \t\ta[i]=op(a[i],x);\n\t}\n\tvoid set(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\t\
    push(i/m);\n\t\ta[i]=x;\n\t}\n\tT&operator[](int i){\n\t\tassert(0<=i&&i<n);\n\
    \t\tpush(i/m);\n\t\treturn a[i];\n\t}\n\tvoid apply(int l,int r,T x){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return;\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tpush(j);\n\
    \t\t\tfor(int i=l;i<(j+1)*m;i++)a[i]=op(a[i],x);\n\t\t\tj++;\n\t\t}\n\t\tfor(int\
    \ i=j;i<k;i++)s[i]=op(s[i],x);\n\t\tif(r==k*m)return;\n\t\tpush(k);\n\t\tfor(int\
    \ i=max(k*m,l);i<r;i++)a[i]=op(a[i],x);\n\t}\n};\n"
  code: "//non commutative monoid\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\n\
    template<class T,T(*op)(T,T),T(*e)()>\nstruct sqrt_bucket_dual{\n\tint n,m=0;\n\
    \tvector<T>a,s;\n\tsqrt_bucket_dual(int n):n(n),a(n,e()){while(m*m<n)m++;s.assign(m,e());}\n\
    \tvoid push(int j){\n\t\tfor(int i=j*m;i<(j+1)*m;i++)a[i]=op(a[i],s[j]);\n\t\t\
    s[j]=e();\n\t}\n\tvoid apply(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\tpush(i/m);\n\
    \t\ta[i]=op(a[i],x);\n\t}\n\tvoid set(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\t\
    push(i/m);\n\t\ta[i]=x;\n\t}\n\tT&operator[](int i){\n\t\tassert(0<=i&&i<n);\n\
    \t\tpush(i/m);\n\t\treturn a[i];\n\t}\n\tvoid apply(int l,int r,T x){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return;\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tpush(j);\n\
    \t\t\tfor(int i=l;i<(j+1)*m;i++)a[i]=op(a[i],x);\n\t\t\tj++;\n\t\t}\n\t\tfor(int\
    \ i=j;i<k;i++)s[i]=op(s[i],x);\n\t\tif(r==k*m)return;\n\t\tpush(k);\n\t\tfor(int\
    \ i=max(k*m,l);i<r;i++)a[i]=op(a[i],x);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/sqrt_bucket_dual_20250616_2.hpp
  requiredBy: []
  timestamp: '2025-06-16 21:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/sqrt_bucket_dual_20250616_2_2.test.cpp
  - work/lib/sqrt_bucket_dual_20250616_2_1.test.cpp
documentation_of: work/lib/sqrt_bucket_dual_20250616_2.hpp
layout: document
redirect_from:
- /library/work/lib/sqrt_bucket_dual_20250616_2.hpp
- /library/work/lib/sqrt_bucket_dual_20250616_2.hpp.html
title: work/lib/sqrt_bucket_dual_20250616_2.hpp
---
