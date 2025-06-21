---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc054/submissions/66908452
  bundledCode: "#line 1 \"work/lib/combination_20250621_1.hpp\"\n//https://atcoder.jp/contests/agc054/submissions/66908452\n\
    template<class T>\nstruct combination{\n\tvector<T>fact{1},ifact{1};\n\tvoid build(int\
    \ n){\n\t\tint m=fact.size();\n\t\tif(m>n)return;\n\t\tn=max(n,m+m);\n\t\tfact.resize(n+1);\n\
    \t\tifact.resize(n+1);\n\t\tfor(int i=m;i<=n;i++)fact[i]=fact[i-1]*i;\n\t\tifact[n]=1/fact[n];\n\
    \t\tfor(int i=n;i-->m;)ifact[i]=ifact[i+1]*(i+1);\n\t}\n\tT P(int n,int k){\n\t\
    \tif(k==0)return 1;\n\t\tassert(n>=0&&k>=0);//n<0\u306B\u306F\u975E\u5BFE\u5FDC\
    \n\t\tif(k>n)return 0;\n\t\tbuild(n);\n\t\treturn fact[n]*ifact[n-k];\n\t}\n\t\
    T C(int n,int k){return P(n,k)*ifact[k];}\n};\n"
  code: "//https://atcoder.jp/contests/agc054/submissions/66908452\ntemplate<class\
    \ T>\nstruct combination{\n\tvector<T>fact{1},ifact{1};\n\tvoid build(int n){\n\
    \t\tint m=fact.size();\n\t\tif(m>n)return;\n\t\tn=max(n,m+m);\n\t\tfact.resize(n+1);\n\
    \t\tifact.resize(n+1);\n\t\tfor(int i=m;i<=n;i++)fact[i]=fact[i-1]*i;\n\t\tifact[n]=1/fact[n];\n\
    \t\tfor(int i=n;i-->m;)ifact[i]=ifact[i+1]*(i+1);\n\t}\n\tT P(int n,int k){\n\t\
    \tif(k==0)return 1;\n\t\tassert(n>=0&&k>=0);//n<0\u306B\u306F\u975E\u5BFE\u5FDC\
    \n\t\tif(k>n)return 0;\n\t\tbuild(n);\n\t\treturn fact[n]*ifact[n-k];\n\t}\n\t\
    T C(int n,int k){return P(n,k)*ifact[k];}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/combination_20250621_1.hpp
  requiredBy: []
  timestamp: '2025-06-21 09:19:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/combination_20250621_1.hpp
layout: document
redirect_from:
- /library/work/lib/combination_20250621_1.hpp
- /library/work/lib/combination_20250621_1.hpp.html
title: work/lib/combination_20250621_1.hpp
---
