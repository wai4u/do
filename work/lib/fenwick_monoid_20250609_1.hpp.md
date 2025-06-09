---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/cp/fenwick_monoid.hpp
    title: work/cp/fenwick_monoid.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/dp/submissions/66630023
  bundledCode: "#line 1 \"work/lib/fenwick_monoid_20250609_1.hpp\"\n//fenwick tree\
    \ monoid\n//https://atcoder.jp/contests/dp/submissions/66630023\n//template\u3067\
    op,e\u3092\u6307\u5B9A\u3059\u308B\u5B9F\u88C5\ntemplate<class T,T(*op)(T,T),T(*e)()>\n\
    struct fenwick{\n\tint n=0;bool built=0;\n\tvector<T>d;\n\tfenwick(){}\n\tfenwick(int\
    \ n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\t\td.assign(n,e());\n\t\t\
    built=0;\n\t}\n\tvoid apply(int i,T x){\n\t\tassert(0<=i);\n\t\twhile(i<n)d[i]=op(d[i],x),i|=i+1;\n\
    \t}\n\tT operator[](int i){\n\t\tassert(i<n);\n\t\tbuild();\n\t\tT y=e();\n\t\t\
    while(i>=0)y=op(y,d[i]),i&=i+1,i--;\n\t\treturn y;\n\t}\n};\n"
  code: "//fenwick tree monoid\n//https://atcoder.jp/contests/dp/submissions/66630023\n\
    //template\u3067op,e\u3092\u6307\u5B9A\u3059\u308B\u5B9F\u88C5\ntemplate<class\
    \ T,T(*op)(T,T),T(*e)()>\nstruct fenwick{\n\tint n=0;bool built=0;\n\tvector<T>d;\n\
    \tfenwick(){}\n\tfenwick(int n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\
    \t\td.assign(n,e());\n\t\tbuilt=0;\n\t}\n\tvoid apply(int i,T x){\n\t\tassert(0<=i);\n\
    \t\twhile(i<n)d[i]=op(d[i],x),i|=i+1;\n\t}\n\tT operator[](int i){\n\t\tassert(i<n);\n\
    \t\tbuild();\n\t\tT y=e();\n\t\twhile(i>=0)y=op(y,d[i]),i&=i+1,i--;\n\t\treturn\
    \ y;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/fenwick_monoid_20250609_1.hpp
  requiredBy:
  - work/cp/fenwick_monoid.hpp
  timestamp: '2025-06-09 22:24:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/fenwick_monoid_20250609_1.hpp
layout: document
redirect_from:
- /library/work/lib/fenwick_monoid_20250609_1.hpp
- /library/work/lib/fenwick_monoid_20250609_1.hpp.html
title: work/lib/fenwick_monoid_20250609_1.hpp
---
