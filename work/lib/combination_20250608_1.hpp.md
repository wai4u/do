---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/cp/combination.hpp
    title: work/cp/combination.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"work/lib/combination_20250608_1.hpp\"\ntemplate<class T>\n\
    struct combination{\n\tvector<T>fact{1},ifact{1};\n\tvoid build(int n){\n\t\t\
    int m=fact.size();\n\t\tif(m>n)return;\n\t\tn=max(n,m+m);\n\t\tfact.resize(n+1);\n\
    \t\tifact.resize(n+1);\n\t\tfor(int i=m;i<=n;i++)fact[i]=fact[i-1]*i;\n\t\tifact[n]=1/fact[n];\n\
    \t\tfor(int i=n;i-->m;)ifact[i]=ifact[i+1]*(i+1);\n\t}\n\tT C(int n,int k){\n\t\
    \tif(k==0)return 1;\n\t\tif(k>n)return 0;\n\t\tbuild(n);\n\t\treturn fact[n]*ifact[n-k]*ifact[k];\n\
    \t}\n};\n"
  code: "template<class T>\nstruct combination{\n\tvector<T>fact{1},ifact{1};\n\t\
    void build(int n){\n\t\tint m=fact.size();\n\t\tif(m>n)return;\n\t\tn=max(n,m+m);\n\
    \t\tfact.resize(n+1);\n\t\tifact.resize(n+1);\n\t\tfor(int i=m;i<=n;i++)fact[i]=fact[i-1]*i;\n\
    \t\tifact[n]=1/fact[n];\n\t\tfor(int i=n;i-->m;)ifact[i]=ifact[i+1]*(i+1);\n\t\
    }\n\tT C(int n,int k){\n\t\tif(k==0)return 1;\n\t\tif(k>n)return 0;\n\t\tbuild(n);\n\
    \t\treturn fact[n]*ifact[n-k]*ifact[k];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/combination_20250608_1.hpp
  requiredBy:
  - work/cp/combination.hpp
  timestamp: '2025-06-08 09:29:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/combination_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/combination_20250608_1.hpp
- /library/work/lib/combination_20250608_1.hpp.html
title: work/lib/combination_20250608_1.hpp
---
