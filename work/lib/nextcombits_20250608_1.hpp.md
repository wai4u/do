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
  bundledCode: "#line 1 \"work/lib/nextcombits_20250608_1.hpp\"\nlong nextcombits(long\
    \ s){\n\tlong lo=s&-s,r=s+lo;\n\treturn(s&~r)/lo>>1|r;\n\t//s+lo:lo\u304B\u3089\
    1\u304C\u7D9A\u304F\u7B87\u6240\u3092\u5168\u6D88\u3057\u3001\u6700\u521D\u306B\
    0\u306B\u306A\u3063\u305F\u3068\u3053\u308D\u3092\u7ACB\u3066\u308B\n\t//(s&-r)/lo>>1\u3067\
    s\u306E\u4E2D\u3067(\u6700\u521D\u306B\u9023\u7D9A1\u3060\u3063\u305F\u90E8\u5206\
    \u306E\u500B\u6570-1)\u500B\u306E1\u30920-offset\u3067\u4E26\u3079\u3066r\u3068\
    \u7D50\u5408\n}\n"
  code: "long nextcombits(long s){\n\tlong lo=s&-s,r=s+lo;\n\treturn(s&~r)/lo>>1|r;\n\
    \t//s+lo:lo\u304B\u30891\u304C\u7D9A\u304F\u7B87\u6240\u3092\u5168\u6D88\u3057\
    \u3001\u6700\u521D\u306B0\u306B\u306A\u3063\u305F\u3068\u3053\u308D\u3092\u7ACB\
    \u3066\u308B\n\t//(s&-r)/lo>>1\u3067s\u306E\u4E2D\u3067(\u6700\u521D\u306B\u9023\
    \u7D9A1\u3060\u3063\u305F\u90E8\u5206\u306E\u500B\u6570-1)\u500B\u306E1\u3092\
    0-offset\u3067\u4E26\u3079\u3066r\u3068\u7D50\u5408\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/nextcombits_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/nextcombits_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/nextcombits_20250608_1.hpp
- /library/work/lib/nextcombits_20250608_1.hpp.html
title: work/lib/nextcombits_20250608_1.hpp
---
