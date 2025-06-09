---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: work/lib/fenwick_20250609_1.hpp
    title: work/lib/fenwick_20250609_1.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: work/1.cpp
    title: work/1.cpp
  - icon: ':warning:'
    path: work/cp/fenwick_bitset.hpp
    title: work/cp/fenwick_bitset.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc197/submissions/66625528
    - https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_01.hpp
  bundledCode: "#line 2 \"work/lib/fenwick_20250609_1.hpp\"\n//https://atcoder.jp/contests/arc197/submissions/66622201\n\
    template<class T>\nstruct fenwick{\n\tint n=0;\n\tvector<T>d;\n\tbool built=0;\n\
    \tfenwick(){}\n\tfenwick(int n){init(n);}\n\tvoid init(int n){\n\t\tthis->n=n;\n\
    \t\td.assign(n,T{});\n\t\tbuilt=0;\n\t}\n\tvoid build(){\n\t\tif(built)return;\n\
    \t\tbuilt=1;\n\t\tfor(int i=0;i<n;i++){\n\t\t\tint j=i|i+1;\n\t\t\tif(j<n)d[j]+=d[i];\n\
    \t\t}\n\t}\n\tvoid add(int i,T x){\n\t\tassert(0<=i);\n\t\tif(!built){d[i]+=x;return;}\n\
    \t\twhile(i<n)d[i]+=x,i|=i+1;\n\t}\n\tT operator[](int i){\n\t\tassert(i<n);\n\
    \t\tbuild();\n\t\tT y{};\n\t\twhile(i>=0)y+=d[i],i&=i+1,i--;\n\t\treturn y;\n\t\
    }\n\tint lower_bound(T x){//first [i]>=x\n\t\tint i=0,w=1;while(w<=n)w<<=1;\n\t\
    \tbuild();\n\t\twhile(w>>=1)if(i+w<=n&&d[i+w-1]<x)x-=d[i+w-1],i+=w;\n\t\treturn\
    \ i;\n\t}\n};\n#line 2 \"work/lib/fenwick_bitset_20250609_1.hpp\"\n//set,unset\u304C\
    log(N/64)\u306B\u306A\u308B\u4EE3\u308F\u308A\u306B\u3001\u533A\u9593\u5185\u30AB\
    \u30A6\u30F3\u30C8\u3084kth bit\u3082log(N/64)\n//https://atcoder.jp/contests/arc197/submissions/66625528\n\
    //https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_01.hpp\n\
    struct fenwick_bitset{\n\tconstexpr static int M=63;\n\tint n=0,m;\n\tvector<unsigned\
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
    \t}\n\tint kth(int i){\n\t\tif(i>=count())return -1;\n\t\tint j=d.lower_bound(i+1);\n\
    \t\ti-=d[j-1];\n\t\tassert(0<=i&&i<64);\n\t\tint ok=0,ng=64;\n\t\twhile(ng-ok>1){\n\
    \t\t\tint k=ng+ok>>1;\n\t\t\tif(__builtin_popcountll((1ull<<k)-1&s[j])<=i)ok=k;\n\
    \t\t\telse ng=k;\n\t\t}\n\t\treturn(j<<6)+ok;\n\t}\n};\n"
  code: "#include\"fenwick_20250609_1.hpp\"\n//set,unset\u304Clog(N/64)\u306B\u306A\
    \u308B\u4EE3\u308F\u308A\u306B\u3001\u533A\u9593\u5185\u30AB\u30A6\u30F3\u30C8\
    \u3084kth bit\u3082log(N/64)\n//https://atcoder.jp/contests/arc197/submissions/66625528\n\
    //https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_01.hpp\n\
    struct fenwick_bitset{\n\tconstexpr static int M=63;\n\tint n=0,m;\n\tvector<unsigned\
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
    \t}\n\tint kth(int i){\n\t\tif(i>=count())return -1;\n\t\tint j=d.lower_bound(i+1);\n\
    \t\ti-=d[j-1];\n\t\tassert(0<=i&&i<64);\n\t\tint ok=0,ng=64;\n\t\twhile(ng-ok>1){\n\
    \t\t\tint k=ng+ok>>1;\n\t\t\tif(__builtin_popcountll((1ull<<k)-1&s[j])<=i)ok=k;\n\
    \t\t\telse ng=k;\n\t\t}\n\t\treturn(j<<6)+ok;\n\t}\n};\n"
  dependsOn:
  - work/lib/fenwick_20250609_1.hpp
  isVerificationFile: false
  path: work/lib/fenwick_bitset_20250609_1.hpp
  requiredBy:
  - work/cp/fenwick_bitset.hpp
  - work/1.cpp
  timestamp: '2025-06-09 19:07:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/fenwick_bitset_20250609_1.hpp
layout: document
redirect_from:
- /library/work/lib/fenwick_bitset_20250609_1.hpp
- /library/work/lib/fenwick_bitset_20250609_1.hpp.html
title: work/lib/fenwick_bitset_20250609_1.hpp
---
