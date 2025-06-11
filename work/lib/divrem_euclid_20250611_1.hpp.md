---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/lib/baseconv_20250611_1.hpp
    title: work/lib/baseconv_20250611_1.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc105/submissions/66654640
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ work/lib/divrem_euclid_20250611_1.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "//https://atcoder.jp/contests/abc105/submissions/66654640\n#pragma once\n\
    template<class T,class U>\nauto divrem_euclid(T a,U b){\n\tusing X=common_type_t<T,U>;\n\
    \tX q=a/b,r=a-q*b;\n\tif(r<0){\n\t\tif(b<0)r-=b,q++;\n\t\telse r+=b,q--;\n\t}\n\
    \treturn make_pair(q,r);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/divrem_euclid_20250611_1.hpp
  requiredBy:
  - work/lib/baseconv_20250611_1.hpp
  timestamp: '2025-06-11 10:33:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/divrem_euclid_20250611_1.hpp
layout: document
redirect_from:
- /library/work/lib/divrem_euclid_20250611_1.hpp
- /library/work/lib/divrem_euclid_20250611_1.hpp.html
title: work/lib/divrem_euclid_20250611_1.hpp
---
