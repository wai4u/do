---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/sqrt_bucket_20250616_3.test.cpp
    title: work/lib/sqrt_bucket_20250616_3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"work/lib/sqrt_bucket_20250616_3.hpp\"\n//additive\n//abelian\
    \ group\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\
    template<class T>\nstruct sqrt_bucket{\n\tint n,m=0;\n\tvector<T>a,s;\n\tsqrt_bucket(int\
    \ n):n(n),a(n){while(m*m<n)m++;s.resize(m);}\n\tvoid add(int i,T x){\n\t\tassert(0<=i&&i<n);\n\
    \t\ta[i]+=x;\n\t\ts[i/m]+=x;\n\t}\n\tvoid set(int i,T x){\n\t\tassert(0<=i&&i<n);\n\
    \t\tadd(i,x-a[i]);\n\t}\n\tT sum(int r){\n\t\tassert(0<=r&&r<=n);\n\t\tint j=r/m;\n\
    \t\tT y{};\n\t\tfor(int i=0;i<j;i++)y+=s[i];\n\t\tfor(int i=j*m;i<r;i++)y+=a[i];\n\
    \t\treturn y;\n\t}\n\tT sum(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\t\
    T y{};\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tfor(int i=l;i<(j+1)*m;i++)y+=a[i];\n\
    \t\t\tj++;\n\t\t}\n\t\tfor(int i=j;i<k;i++)y+=s[i];\n\t\tfor(int i=max(k*m,l);i<r;i++)y+=a[i];\n\
    \t\treturn y;\n\t}\n};\n"
  code: "//additive\n//abelian group\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\n\
    template<class T>\nstruct sqrt_bucket{\n\tint n,m=0;\n\tvector<T>a,s;\n\tsqrt_bucket(int\
    \ n):n(n),a(n){while(m*m<n)m++;s.resize(m);}\n\tvoid add(int i,T x){\n\t\tassert(0<=i&&i<n);\n\
    \t\ta[i]+=x;\n\t\ts[i/m]+=x;\n\t}\n\tvoid set(int i,T x){\n\t\tassert(0<=i&&i<n);\n\
    \t\tadd(i,x-a[i]);\n\t}\n\tT sum(int r){\n\t\tassert(0<=r&&r<=n);\n\t\tint j=r/m;\n\
    \t\tT y{};\n\t\tfor(int i=0;i<j;i++)y+=s[i];\n\t\tfor(int i=j*m;i<r;i++)y+=a[i];\n\
    \t\treturn y;\n\t}\n\tT sum(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\t\
    T y{};\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tfor(int i=l;i<(j+1)*m;i++)y+=a[i];\n\
    \t\t\tj++;\n\t\t}\n\t\tfor(int i=j;i<k;i++)y+=s[i];\n\t\tfor(int i=max(k*m,l);i<r;i++)y+=a[i];\n\
    \t\treturn y;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/sqrt_bucket_20250616_3.hpp
  requiredBy: []
  timestamp: '2025-06-16 21:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/sqrt_bucket_20250616_3.test.cpp
documentation_of: work/lib/sqrt_bucket_20250616_3.hpp
layout: document
redirect_from:
- /library/work/lib/sqrt_bucket_20250616_3.hpp
- /library/work/lib/sqrt_bucket_20250616_3.hpp.html
title: work/lib/sqrt_bucket_20250616_3.hpp
---
