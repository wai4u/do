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
    path: work/segtree_lazy_20250613_2.hpp
    title: work/segtree_lazy_20250613_2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
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
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n#include\"io_20250608_1.hpp\"\n#include\"segtree_lazy_20250613_2.hpp\"\nstruct\
    \ X{long s=0,c=0;};\nX op(X x,X y){return X{x.s+y.s,x.c+y.c};}\nX e(){return X{};}\n\
    int id(){return 1e9;}\nX mapping(int f,X x){return f==id()?x:X{f*x.c,x.c};}\n\
    int composition(int f,int g){return f==id()?g:f;}\nint main(){\n\tint n,q;\n\t\
    cin>>n>>q;\n\tsegtree_lazy<X,op,e,int,mapping,composition,id>seg(n+1);\n\tfor(int\
    \ i=0;i<=n;i++)seg.set(i,X{0,1});\n\twhile(q--){\n\t\tint t,l,r;\n\t\tcin>>t>>l>>r;\n\
    \t\tif(t==0){\n\t\t\tint x;\n\t\t\tcin>>x;\n\t\t\tseg.apply(l,r+1,x);\n\t\t}else{\n\
    \t\t\tcout<<seg.prod(l,r+1).s<<'\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - work/lib/io_20250608_1.hpp
  - work/lib/optimize_20250608_1.hpp
  - work/segtree_lazy_20250613_2.hpp
  isVerificationFile: true
  path: work/segtree_lazy_20250613_2_4.test.cpp
  requiredBy: []
  timestamp: '2025-06-13 18:58:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: work/segtree_lazy_20250613_2_4.test.cpp
layout: document
redirect_from:
- /verify/work/segtree_lazy_20250613_2_4.test.cpp
- /verify/work/segtree_lazy_20250613_2_4.test.cpp.html
title: work/segtree_lazy_20250613_2_4.test.cpp
---
