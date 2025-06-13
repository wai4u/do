---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: work/lib/io_20250608_1.hpp
    title: work/lib/io_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/optimize_20250608_1.hpp
    title: work/lib/optimize_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/segtree_dual_20250613_1.hpp
    title: work/segtree_dual_20250613_1.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: io_20250608_1.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n#include\"io_20250608_1.hpp\"\n#include\"segtree_dual_20250613_1.hpp\"\nint\
    \ op(int x,int y){return x+y;}\nint e(){return 0;}\nint main(){\n\tint n,q;\n\t\
    cin>>n>>q;\n\tsegtree_dual<int,op,e>seg(n+1);\n\tint id=0;\n\twhile(q--){\n\t\t\
    int t;\n\t\tcin>>t;\n\t\tif(t==0){\n\t\t\tint l,r,x;\n\t\t\tcin>>l>>r>>x;\n\t\t\
    \tseg.apply(l,r+1,x);\n\t\t}else{\n\t\t\tint i;\n\t\t\tcin>>i;\n\t\t\tcout<<seg[i]<<'\\\
    n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - work/lib/io_20250608_1.hpp
  - work/lib/optimize_20250608_1.hpp
  - work/segtree_dual_20250613_1.hpp
  isVerificationFile: true
  path: work/segtree_dual_20250613_1_2.test.cpp
  requiredBy: []
  timestamp: '2025-06-13 18:37:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: work/segtree_dual_20250613_1_2.test.cpp
layout: document
redirect_from:
- /verify/work/segtree_dual_20250613_1_2.test.cpp
- /verify/work/segtree_dual_20250613_1_2.test.cpp.html
title: work/segtree_dual_20250613_1_2.test.cpp
---
