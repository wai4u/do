---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_f
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E
  bundledCode: "#line 1 \"work/lib/fenwick_multideg_20250608_1.hpp\"\ntemplate<class\
    \ T>\nstruct fenwick{\n\tint n;\n\tvector<T>d;\n\tfenwick(int n):n(n),d(n){}\n\
    \tvoid add(int i,T x){while(i<n)d[i]+=x,i|=i+1;}\n\tT operator[](int i){T y{};while(i>=0)y+=d[i],i&=i+1,i--;return\
    \ y;}\n};\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\ntemplate<class\
    \ T>\nstruct fenwick_1deg{\n\tfenwick<T>d0,d1;\n\tfenwick_1deg(int n):d0(n),d1(n){}\n\
    \t//primal:[i]+=x\n\t//dual:(i<=j)+=(j-i+1)x\n\tvoid add(int i,T x){d0.add(i,(1-i)*x),d1.add(i,x);}\n\
    \t//primal:sum_j<=i (i-j+1)*[j]\n\t//dual:[i]\n\tT operator[](int i){return d0[i]+d1[i]*i;}\n\
    };\n//https://atcoder.jp/contests/abc256/tasks/abc256_f\ntemplate<class T>\nstruct\
    \ fenwick_2deg{\n\tfenwick<T>d0,d1,d2;\n\tfenwick_2deg(int n):d0(n),d1(n),d2(n){}\n\
    \t//primal:[i]+=x\n\t//dual:(i<=j)+=(sum_i<=k<=j (k-i+1)x)=x/2*(j-i+1)(j-i+2)=x/2*(j^2+(-2i+3)j+(-i+1)(-i+2))\n\
    \tvoid add(int i,T x){\n\t\td0.add(i,x*(-i+1)*(-i+2));\n\t\td1.add(i,x*(-2*i+3));\n\
    \t\td2.add(i,x);\n\t}\n\t//primal:sum_j<=i (sum_k<=j (j-k+1)*[k])\n\t//dual:[i]\n\
    \tT operator[](int i){return (d0[i]+d1[i]*i+d2[i]*i*i)/2;}\n};\n"
  code: "template<class T>\nstruct fenwick{\n\tint n;\n\tvector<T>d;\n\tfenwick(int\
    \ n):n(n),d(n){}\n\tvoid add(int i,T x){while(i<n)d[i]+=x,i|=i+1;}\n\tT operator[](int\
    \ i){T y{};while(i>=0)y+=d[i],i&=i+1,i--;return y;}\n};\n//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\n\
    //https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E\ntemplate<class\
    \ T>\nstruct fenwick_1deg{\n\tfenwick<T>d0,d1;\n\tfenwick_1deg(int n):d0(n),d1(n){}\n\
    \t//primal:[i]+=x\n\t//dual:(i<=j)+=(j-i+1)x\n\tvoid add(int i,T x){d0.add(i,(1-i)*x),d1.add(i,x);}\n\
    \t//primal:sum_j<=i (i-j+1)*[j]\n\t//dual:[i]\n\tT operator[](int i){return d0[i]+d1[i]*i;}\n\
    };\n//https://atcoder.jp/contests/abc256/tasks/abc256_f\ntemplate<class T>\nstruct\
    \ fenwick_2deg{\n\tfenwick<T>d0,d1,d2;\n\tfenwick_2deg(int n):d0(n),d1(n),d2(n){}\n\
    \t//primal:[i]+=x\n\t//dual:(i<=j)+=(sum_i<=k<=j (k-i+1)x)=x/2*(j-i+1)(j-i+2)=x/2*(j^2+(-2i+3)j+(-i+1)(-i+2))\n\
    \tvoid add(int i,T x){\n\t\td0.add(i,x*(-i+1)*(-i+2));\n\t\td1.add(i,x*(-2*i+3));\n\
    \t\td2.add(i,x);\n\t}\n\t//primal:sum_j<=i (sum_k<=j (j-k+1)*[k])\n\t//dual:[i]\n\
    \tT operator[](int i){return (d0[i]+d1[i]*i+d2[i]*i*i)/2;}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/fenwick_multideg_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/fenwick_multideg_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/fenwick_multideg_20250608_1.hpp
- /library/work/lib/fenwick_multideg_20250608_1.hpp.html
title: work/lib/fenwick_multideg_20250608_1.hpp
---
