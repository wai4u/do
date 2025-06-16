---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/sqrt_bucket_dual_20250616_1.test.cpp
    title: work/lib/sqrt_bucket_dual_20250616_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"work/lib/sqrt_bucket_dual_20250616_1.hpp\"\n//additive\n\
    //dual\n//abelian group\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\n\
    template<class T>\nstruct sqrt_bucket_dual{\n\tint n,m=0;\n\tvector<T>a,s;\n\t\
    sqrt_bucket_dual(int n):n(n),a(n){while(m*m<n)m++;s.resize(m);}\n\tvoid add(int\
    \ i,T x){\n\t\tassert(0<=i&&i<n);\n\t\ta[i]+=x;\n\t}\n\tvoid set(int i,T x){\n\
    \t\tassert(0<=i&&i<n);\n\t\ta[i]=x-s[i/m];\n\t}\n\tT operator[](int i){\n\t\t\
    assert(0<=i&&i<n);\n\t\treturn a[i]+s[i/m];\n\t}\n\tvoid add(int l,int r,T x){\n\
    \t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\t\tint j=l/m,k=r/m;\n\t\t\
    if(j<k&&j*m<l){\n\t\t\tfor(int i=l;i<(j+1)*m;i++)a[i]+=x;\n\t\t\tj++;\n\t\t}\n\
    \t\tfor(int i=j;i<k;i++)s[i]+=x;\n\t\tfor(int i=max(k*m,l);i<r;i++)a[i]+=x;\n\t\
    }\n};\n"
  code: "//additive\n//dual\n//abelian group\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\ntemplate<class\
    \ T>\nstruct sqrt_bucket_dual{\n\tint n,m=0;\n\tvector<T>a,s;\n\tsqrt_bucket_dual(int\
    \ n):n(n),a(n){while(m*m<n)m++;s.resize(m);}\n\tvoid add(int i,T x){\n\t\tassert(0<=i&&i<n);\n\
    \t\ta[i]+=x;\n\t}\n\tvoid set(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\ta[i]=x-s[i/m];\n\
    \t}\n\tT operator[](int i){\n\t\tassert(0<=i&&i<n);\n\t\treturn a[i]+s[i/m];\n\
    \t}\n\tvoid add(int l,int r,T x){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return;\n\
    \t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tfor(int i=l;i<(j+1)*m;i++)a[i]+=x;\n\
    \t\t\tj++;\n\t\t}\n\t\tfor(int i=j;i<k;i++)s[i]+=x;\n\t\tfor(int i=max(k*m,l);i<r;i++)a[i]+=x;\n\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/sqrt_bucket_dual_20250616_1.hpp
  requiredBy: []
  timestamp: '2025-06-16 21:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/sqrt_bucket_dual_20250616_1.test.cpp
documentation_of: work/lib/sqrt_bucket_dual_20250616_1.hpp
layout: document
redirect_from:
- /library/work/lib/sqrt_bucket_dual_20250616_1.hpp
- /library/work/lib/sqrt_bucket_dual_20250616_1.hpp.html
title: work/lib/sqrt_bucket_dual_20250616_1.hpp
---
