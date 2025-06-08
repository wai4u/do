---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: work/cp/io.hpp
    title: work/cp/io.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/fenwick_primal_20250608_1.hpp
    title: work/lib/fenwick_primal_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/io_20250608_1.hpp
    title: work/lib/io_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/optimize_20250608_1.hpp
    title: work/lib/optimize_20250608_1.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: io.hpp: line -1:\
    \ no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"io.hpp\"\n#include\"fenwick_primal_20250608_1.hpp\"\nint main(){\n\t\
    int n,q;\n\tcin>>n>>q;\n\tvector<int>a(n);\n\tfor(int i=0;i<n;i++)cin>>a[i];\n\
    \tfenwick<long>s(a);\n\twhile(q--){\n\t\tint t,i,j;\n\t\tcin>>t>>i>>j;\n\t\tif(t==0)s.add(i,j);\n\
    \t\telse cout<<s.sum(i,j)<<'\\n';\n\t}\n}\n"
  dependsOn:
  - work/cp/io.hpp
  - work/lib/io_20250608_1.hpp
  - work/lib/optimize_20250608_1.hpp
  - work/lib/fenwick_primal_20250608_1.hpp
  isVerificationFile: true
  path: work/lib/fenwick_primal_20250608_1_4.test.cpp
  requiredBy: []
  timestamp: '2025-06-08 19:23:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: work/lib/fenwick_primal_20250608_1_4.test.cpp
layout: document
redirect_from:
- /verify/work/lib/fenwick_primal_20250608_1_4.test.cpp
- /verify/work/lib/fenwick_primal_20250608_1_4.test.cpp.html
title: work/lib/fenwick_primal_20250608_1_4.test.cpp
---
