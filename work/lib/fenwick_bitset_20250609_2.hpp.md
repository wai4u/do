---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: work/lib/fenwick_20250609_2.hpp
    title: work/lib/fenwick_20250609_2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc197/submissions/66625913
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ work/lib/fenwick_20250609_2.hpp: line 2: #pragma once found in a non-first line\n"
  code: "//https://atcoder.jp/contests/arc197/submissions/66625913\n#include\"fenwick_20250609_2.hpp\"\
    \nstruct fenwick_bitset{\n\tconstexpr static int M=63;\n\tint n=0,m;\n\tvector<unsigned\
    \ long long>s;\n\tfenwick<int>d;\n\tfenwick_bitset(){}\n\tfenwick_bitset(int n){init(n);}\n\
    \tvoid init(int n){\n\t\tthis->n=n;\n\t\t//m=(n+63)/64;\n\t\tm=n+M>>6;\n\t\ts.assign(m,0);\n\
    \t\td.init(m);\n\t}\n\tbool get(int i){\n\t\tassert(0<=i&&i<n);\n\t\treturn s[i>>6]>>(i&M)&1;\n\
    \t}\n\tbool operator[](int i){return get(i);}\n\tvoid set(int i){\n\t\tif(get(i))return;\n\
    \t\ts[i>>6]|=1ull<<(i&M);\n\t\td.add(i>>6,1);\n\t}\n\tvoid unset(int i){\n\t\t\
    if(!get(i))return;\n\t\ts[i>>6]^=1ull<<(i&M);\n\t\t//s[i>>6]&=~(1ull<<(i&M));\n\
    \t\td.add(i>>6,-1);\n\t}\n\tvoid flip(int i){if(get(i))unset(i);else set(i);}\n\
    \tint count(){return d[m-1];}\n\tint count(int i){\n\t\tassert(0<=i&&i<=n);\n\t\
    \tif(i==n)return count();\n\t\treturn d[(i>>6)-1]+__builtin_popcountll(s[i>>6]&(1ull<<(i&M))-1);\n\
    \t}\n\tint count(int l,int r){\n\t\tassert(l<=r);\n\t\treturn l==r?0:count(r)-count(l);\n\
    \t}\n\tint kth(int i){\n\t\tif(i>=count())return -1;\n\t\tint l=0;\n\t\tint j=d.max_right([&](int\
    \ c){\n\t\t\tif(i<c)return 0;\n\t\t\tl=c;\n\t\t\treturn 1;\n\t\t})+1;\n\t\ti-=l;\n\
    \t\tassert(0<=i&&i<64);\n\t\tint ok=0,ng=64;\n\t\twhile(ng-ok>1){\n\t\t\tint k=ng+ok>>1;\n\
    \t\t\tif(__builtin_popcountll((1ull<<k)-1&s[j])<=i)ok=k;\n\t\t\telse ng=k;\n\t\
    \t}\n\t\treturn(j<<6)+ok;\n\t}\n};\n"
  dependsOn:
  - work/lib/fenwick_20250609_2.hpp
  isVerificationFile: false
  path: work/lib/fenwick_bitset_20250609_2.hpp
  requiredBy: []
  timestamp: '2025-06-14 20:16:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/fenwick_bitset_20250609_2.hpp
layout: document
redirect_from:
- /library/work/lib/fenwick_bitset_20250609_2.hpp
- /library/work/lib/fenwick_bitset_20250609_2.hpp.html
title: work/lib/fenwick_bitset_20250609_2.hpp
---
