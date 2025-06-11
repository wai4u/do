---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/lib/baseconv_20250611_2.hpp
    title: work/lib/baseconv_20250611_2.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc105/submissions/66654933
  bundledCode: "#line 2 \"work/lib/divrem_floor_20250611_1.hpp\"\n//https://atcoder.jp/contests/abc105/submissions/66654933\n\
    template<class T,class U>\nauto divrem_floor(T a,U b){\n\tusing X=common_type_t<T,U>;\n\
    \tX q=a/b,r=a-q*b;\n\tif(r&&(a^b)<0)r+=b,q--;\n\treturn make_pair(q,r);\n}\ntemplate<class\
    \ T,class U>\nauto divmod(T a,U b){return divrem_floor(a,b);}\n"
  code: "#pragma once\n//https://atcoder.jp/contests/abc105/submissions/66654933\n\
    template<class T,class U>\nauto divrem_floor(T a,U b){\n\tusing X=common_type_t<T,U>;\n\
    \tX q=a/b,r=a-q*b;\n\tif(r&&(a^b)<0)r+=b,q--;\n\treturn make_pair(q,r);\n}\ntemplate<class\
    \ T,class U>\nauto divmod(T a,U b){return divrem_floor(a,b);}\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/divrem_floor_20250611_1.hpp
  requiredBy:
  - work/lib/baseconv_20250611_2.hpp
  timestamp: '2025-06-11 10:33:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/divrem_floor_20250611_1.hpp
layout: document
redirect_from:
- /library/work/lib/divrem_floor_20250611_1.hpp
- /library/work/lib/divrem_floor_20250611_1.hpp.html
title: work/lib/divrem_floor_20250611_1.hpp
---
