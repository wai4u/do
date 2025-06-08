---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/cp/boyer_moore_majority_vote.hpp
    title: work/cp/boyer_moore_majority_vote.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc272/tasks/abc272_g
    - https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    - https://judge.yosupo.jp/problem/majority_voting
  bundledCode: "#line 1 \"work/lib/boyer_moore_majority_vote_20250608_1.hpp\"\n//boyer\
    \ moore\n//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm\n\
    //https://atcoder.jp/contests/abc272/tasks/abc272_g\n//\n//\u904E\u534A\u6570\u304C\
    \u3042\u308C\u3070\u305F\u3060\u4E00\u3064\u898B\u3064\u304B\u308B\u3002\u306A\
    \u3051\u308C\u3070y\u306F\u6700\u5F8C\u306E\u66F4\u65B0\u5F8C\u534A\u6570\u4EE5\
    \u4E0A\u3060\u3063\u305F\u3082\u306E\u3068\u3044\u3046\u3060\u3051\u3067\u610F\
    \u7FA9\u306F\u306A\u3044\u3002\n//https://judge.yosupo.jp/problem/majority_voting\
    \ (\u3053\u308C\u306F\u52D5\u7684\u306A\u306E\u3067\u3053\u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\u3067\u306F\u7121\u7406)\ntemplate<class T>\npair<bool,T>majority_vote(const\
    \ vector<T>&a){\n\tT y;\n\tint c=0;\n\tfor(T x:a){\n\t\tif(!c)y=x,c=1;\n\t\telse\
    \ if(x==y)c++;\n\t\telse c--;\n\t}\n\tc=0;\n\tfor(T x:a)c+=x==y;\n\treturn{c+c>(int)a.size(),y};\n\
    }\n"
  code: "//boyer moore\n//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm\n\
    //https://atcoder.jp/contests/abc272/tasks/abc272_g\n//\n//\u904E\u534A\u6570\u304C\
    \u3042\u308C\u3070\u305F\u3060\u4E00\u3064\u898B\u3064\u304B\u308B\u3002\u306A\
    \u3051\u308C\u3070y\u306F\u6700\u5F8C\u306E\u66F4\u65B0\u5F8C\u534A\u6570\u4EE5\
    \u4E0A\u3060\u3063\u305F\u3082\u306E\u3068\u3044\u3046\u3060\u3051\u3067\u610F\
    \u7FA9\u306F\u306A\u3044\u3002\n//https://judge.yosupo.jp/problem/majority_voting\
    \ (\u3053\u308C\u306F\u52D5\u7684\u306A\u306E\u3067\u3053\u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\u3067\u306F\u7121\u7406)\ntemplate<class T>\npair<bool,T>majority_vote(const\
    \ vector<T>&a){\n\tT y;\n\tint c=0;\n\tfor(T x:a){\n\t\tif(!c)y=x,c=1;\n\t\telse\
    \ if(x==y)c++;\n\t\telse c--;\n\t}\n\tc=0;\n\tfor(T x:a)c+=x==y;\n\treturn{c+c>(int)a.size(),y};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/boyer_moore_majority_vote_20250608_1.hpp
  requiredBy:
  - work/cp/boyer_moore_majority_vote.hpp
  timestamp: '2025-06-08 15:21:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/boyer_moore_majority_vote_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/boyer_moore_majority_vote_20250608_1.hpp
- /library/work/lib/boyer_moore_majority_vote_20250608_1.hpp.html
title: work/lib/boyer_moore_majority_vote_20250608_1.hpp
---
