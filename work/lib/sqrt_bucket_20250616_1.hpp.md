---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/sqrt_bucket_20250616_1.test.cpp
    title: work/lib/sqrt_bucket_20250616_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"work/lib/sqrt_bucket_20250616_1.hpp\"\n//minimum\n//commutative\
    \ monoid\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    template<class T,T e>\nstruct sqrt_bucket{\n\tint n,m=0;\n\tvector<T>a,s;\n\t\
    sqrt_bucket(int n):n(n){while(m*m<n)m++;a.assign(n,e),s.assign(m,e);}\n\tvoid\
    \ apply(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\ta[i]=min(a[i],x);\n\t\ti/=m;\n\
    \t\ts[i]=min(s[i],x);\n\t}\n\tvoid set(int i,T x){\n\t\t//O(sqrt(N))\u3060\u304C\
    \u3001\u5834\u5408\u306B\u3088\u3063\u3066\u306FO(1)\u3082\u3042\u308B\n\t\tassert(0<=i&&i<n);\n\
    \t\tint j=i/m;\n\t\tassert(s[j]<=a[i]);\n\t\tif(x<=a[i])s[j]=min(s[j],x);\n\t\t\
    else if(s[j]==a[i]){\n\t\t\ts[j]=e;\n\t\t\ta[i]=x;\n\t\t\tfor(int i=j*m;i<(j+1)*m;i++)s[j]=min(s[j],a[i]);\n\
    \t\t}\n\t\ta[i]=x;\n\t}\n\tT prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return e;\n\t\tint ans=e;\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\
    \t\t\tfor(int i=l;i<(j+1)*m;i++)ans=min(ans,a[i]);\n\t\t\tj++;\n\t\t}\n\t\tfor(int\
    \ i=j;i<k;i++)ans=min(ans,s[i]);\n\t\tfor(int i=max(k*m,l);i<r;i++)ans=min(ans,a[i]);\n\
    \t\treturn ans;\n\t}\n};\n"
  code: "//minimum\n//commutative monoid\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    template<class T,T e>\nstruct sqrt_bucket{\n\tint n,m=0;\n\tvector<T>a,s;\n\t\
    sqrt_bucket(int n):n(n){while(m*m<n)m++;a.assign(n,e),s.assign(m,e);}\n\tvoid\
    \ apply(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\ta[i]=min(a[i],x);\n\t\ti/=m;\n\
    \t\ts[i]=min(s[i],x);\n\t}\n\tvoid set(int i,T x){\n\t\t//O(sqrt(N))\u3060\u304C\
    \u3001\u5834\u5408\u306B\u3088\u3063\u3066\u306FO(1)\u3082\u3042\u308B\n\t\tassert(0<=i&&i<n);\n\
    \t\tint j=i/m;\n\t\tassert(s[j]<=a[i]);\n\t\tif(x<=a[i])s[j]=min(s[j],x);\n\t\t\
    else if(s[j]==a[i]){\n\t\t\ts[j]=e;\n\t\t\ta[i]=x;\n\t\t\tfor(int i=j*m;i<(j+1)*m;i++)s[j]=min(s[j],a[i]);\n\
    \t\t}\n\t\ta[i]=x;\n\t}\n\tT prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\
    \t\tif(l==r)return e;\n\t\tint ans=e;\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\
    \t\t\tfor(int i=l;i<(j+1)*m;i++)ans=min(ans,a[i]);\n\t\t\tj++;\n\t\t}\n\t\tfor(int\
    \ i=j;i<k;i++)ans=min(ans,s[i]);\n\t\tfor(int i=max(k*m,l);i<r;i++)ans=min(ans,a[i]);\n\
    \t\treturn ans;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/sqrt_bucket_20250616_1.hpp
  requiredBy: []
  timestamp: '2025-06-16 21:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/sqrt_bucket_20250616_1.test.cpp
documentation_of: work/lib/sqrt_bucket_20250616_1.hpp
layout: document
redirect_from:
- /library/work/lib/sqrt_bucket_20250616_1.hpp
- /library/work/lib/sqrt_bucket_20250616_1.hpp.html
title: work/lib/sqrt_bucket_20250616_1.hpp
---
