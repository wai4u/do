---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/sqrt_bucket_20250616_2.test.cpp
    title: work/lib/sqrt_bucket_20250616_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"work/lib/sqrt_bucket_20250616_2.hpp\"\n//minimum\n//commutative\
    \ monoid\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    template<class T,T e>\nstruct sqrt_bucket{\n\tint n,m=0;\n\tvector<T>a,s;\n\t\
    vector<int>c;\n\tsqrt_bucket(int n):n(n){while(m*m<n)m++;a.assign(n,e),s.assign(m,e),c.resize(m);}\n\
    \tvoid apply(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\ta[i]=min(a[i],x);\n\t\t\
    i/=m;\n\t\ts[i]=min(s[i],x);\n\t}\n\tvoid set(int i,T x){\n\t\t//count\u3092\u6301\
    \u3064\u3053\u3068\u3067\u57FA\u672CO(1)\u66F4\u65B0\u53EF\u80FD\u306B\n\t\t//\u6700\
    \u5C0F\u5024\u304C0\u500B\u306B\u30EA\u30BB\u30C3\u30C8\u3055\u308C\u305F\u30BF\
    \u30A4\u30DF\u30F3\u30B0\u3067\u3084\u308A\u76F4\u3057O(sqrt(N))\n\t\tassert(0<=i&&i<n);\n\
    \t\tint j=i/m;\n\t\tif(a[i]==x)return;\n\t\tif(x<s[j])c[j]=1,s[j]=a[i]=x;\n\t\t\
    else if(x==s[j])c[j]++,a[i]=x;\n\t\telse{\n\t\t\tc[j]-=a[i]==s[j];\n\t\t\ta[i]=x;\n\
    \t\t\tif(c[j])return;\n\t\t\ts[j]=e;\n\t\t\tfor(int i=j*m;i<(j+1)*m;i++){\n\t\t\
    \t\tif(s[j]==a[i])c[j]++;\n\t\t\t\telse if(a[i]<s[j])s[j]=a[i],c[j]=1;\n\t\t\t\
    }\n\t\t}\n\t}\n\tT prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return\
    \ e;\n\t\tint ans=e;\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tfor(int\
    \ i=l;i<(j+1)*m;i++)ans=min(ans,a[i]);\n\t\t\tj++;\n\t\t}\n\t\tfor(int i=j;i<k;i++)ans=min(ans,s[i]);\n\
    \t\tfor(int i=max(k*m,l);i<r;i++)ans=min(ans,a[i]);\n\t\treturn ans;\n\t}\n};\n"
  code: "//minimum\n//commutative monoid\u306E\u7279\u6B8A\u30B1\u30FC\u30B9\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\n\
    template<class T,T e>\nstruct sqrt_bucket{\n\tint n,m=0;\n\tvector<T>a,s;\n\t\
    vector<int>c;\n\tsqrt_bucket(int n):n(n){while(m*m<n)m++;a.assign(n,e),s.assign(m,e),c.resize(m);}\n\
    \tvoid apply(int i,T x){\n\t\tassert(0<=i&&i<n);\n\t\ta[i]=min(a[i],x);\n\t\t\
    i/=m;\n\t\ts[i]=min(s[i],x);\n\t}\n\tvoid set(int i,T x){\n\t\t//count\u3092\u6301\
    \u3064\u3053\u3068\u3067\u57FA\u672CO(1)\u66F4\u65B0\u53EF\u80FD\u306B\n\t\t//\u6700\
    \u5C0F\u5024\u304C0\u500B\u306B\u30EA\u30BB\u30C3\u30C8\u3055\u308C\u305F\u30BF\
    \u30A4\u30DF\u30F3\u30B0\u3067\u3084\u308A\u76F4\u3057O(sqrt(N))\n\t\tassert(0<=i&&i<n);\n\
    \t\tint j=i/m;\n\t\tif(a[i]==x)return;\n\t\tif(x<s[j])c[j]=1,s[j]=a[i]=x;\n\t\t\
    else if(x==s[j])c[j]++,a[i]=x;\n\t\telse{\n\t\t\tc[j]-=a[i]==s[j];\n\t\t\ta[i]=x;\n\
    \t\t\tif(c[j])return;\n\t\t\ts[j]=e;\n\t\t\tfor(int i=j*m;i<(j+1)*m;i++){\n\t\t\
    \t\tif(s[j]==a[i])c[j]++;\n\t\t\t\telse if(a[i]<s[j])s[j]=a[i],c[j]=1;\n\t\t\t\
    }\n\t\t}\n\t}\n\tT prod(int l,int r){\n\t\tassert(0<=l&&l<=r&&r<=n);\n\t\tif(l==r)return\
    \ e;\n\t\tint ans=e;\n\t\tint j=l/m,k=r/m;\n\t\tif(j<k&&j*m<l){\n\t\t\tfor(int\
    \ i=l;i<(j+1)*m;i++)ans=min(ans,a[i]);\n\t\t\tj++;\n\t\t}\n\t\tfor(int i=j;i<k;i++)ans=min(ans,s[i]);\n\
    \t\tfor(int i=max(k*m,l);i<r;i++)ans=min(ans,a[i]);\n\t\treturn ans;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/sqrt_bucket_20250616_2.hpp
  requiredBy: []
  timestamp: '2025-06-16 21:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/sqrt_bucket_20250616_2.test.cpp
documentation_of: work/lib/sqrt_bucket_20250616_2.hpp
layout: document
redirect_from:
- /library/work/lib/sqrt_bucket_20250616_2.hpp
- /library/work/lib/sqrt_bucket_20250616_2.hpp.html
title: work/lib/sqrt_bucket_20250616_2.hpp
---
