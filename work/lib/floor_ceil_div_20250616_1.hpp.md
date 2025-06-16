---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"work/lib/floor_ceil_div_20250616_1.hpp\"\ntemplate<class\
    \ T>\nT floor_div(T a,T b){return a/b-((a^b)<0&&a%b);}\ntemplate<class T>\nT ceil_div(T\
    \ a,T b){return a/b+((a^b)>0&&a%b);}\n/*\nint main(){\n\tfor(int a:vector{3,-3})for(int\
    \ b:vector{10,-10}){\n\t\tcout<<a<<' '<<b<<' '<<floor_div(b,a)<<' '<<ceil_div(b,a)<<'\\\
    n';\n\t}\n}\n*/\n"
  code: "template<class T>\nT floor_div(T a,T b){return a/b-((a^b)<0&&a%b);}\ntemplate<class\
    \ T>\nT ceil_div(T a,T b){return a/b+((a^b)>0&&a%b);}\n/*\nint main(){\n\tfor(int\
    \ a:vector{3,-3})for(int b:vector{10,-10}){\n\t\tcout<<a<<' '<<b<<' '<<floor_div(b,a)<<'\
    \ '<<ceil_div(b,a)<<'\\n';\n\t}\n}\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/floor_ceil_div_20250616_1.hpp
  requiredBy: []
  timestamp: '2025-06-16 15:00:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/floor_ceil_div_20250616_1.hpp
layout: document
redirect_from:
- /library/work/lib/floor_ceil_div_20250616_1.hpp
- /library/work/lib/floor_ceil_div_20250616_1.hpp.html
title: work/lib/floor_ceil_div_20250616_1.hpp
---
