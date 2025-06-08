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
  bundledCode: "#line 1 \"work/lib/cartesian_tree_20250608_1.hpp\"\ntemplate<class\
    \ T,bool MAX=0>\nstruct cartesian_tree{\n\tint n;\n\tvector<int>p,l,r,L,R;\n\t\
    vector<T>a,st;\n\tcartesian_tree():n(0){}\n\ttemplate<class F>\n\tcartesian_tree(int\
    \ n,F f){init(n,f);}\n\tcartesian_tree(const vector<T>&a){init(a);}\n\tvoid init(){\n\
    \t\tn=0;\n\t\ta.clear();\n\t\tst.clear();\n\t\tl.clear();\n\t\tr.clear();\n\t\t\
    p.clear();\n\t\tL.clear();\n\t\tR.clear();\n\t}\n\tvoid init(const vector<T>&a){\n\
    \t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\ttemplate<class F>\n\tvoid\
    \ init(int n,F f){\n\t\tinit();\n\t\ta.reserve(n);\n\t\tl.reserve(n);\n\t\tr.reserve(n);\n\
    \t\tp.reserve(n);\n\t\tL.reserve(n);\n\t\tR.reserve(n);\n\t\tfor(int i=0;i<n;i++)push(f(i));\n\
    \t}\n\tvoid push(T x){\n\t\ta.push_back(x);\n\t\tl.push_back(-1);\n\t\tr.push_back(-1);\n\
    \t\tp.push_back(-1);\n\t\tL.push_back(0);\n\t\tR.push_back(-1);\n\t\tint i=-1;\n\
    \t\twhile(st.size()&&(MAX?a[st.back()]<x:a[st.back()]>x)){\n\t\t\ti=st.back();st.pop_back();\n\
    \t\t\tR[i]=n;\n\t\t}\n\t\tif(i>-1)p[i]=n,l[n]=i;\n\t\tif(st.size())r[st.back()]=n,p[n]=st.back(),L[n]=st.back()+1;\n\
    \t\tst.push_back(n++);\n\t}\n\tint root(){assert(n);return st[0];}\n\tpair<int,int>range(int\
    \ i){return{L[i],R[i]<0?n:R[i]};}\n};\n"
  code: "template<class T,bool MAX=0>\nstruct cartesian_tree{\n\tint n;\n\tvector<int>p,l,r,L,R;\n\
    \tvector<T>a,st;\n\tcartesian_tree():n(0){}\n\ttemplate<class F>\n\tcartesian_tree(int\
    \ n,F f){init(n,f);}\n\tcartesian_tree(const vector<T>&a){init(a);}\n\tvoid init(){\n\
    \t\tn=0;\n\t\ta.clear();\n\t\tst.clear();\n\t\tl.clear();\n\t\tr.clear();\n\t\t\
    p.clear();\n\t\tL.clear();\n\t\tR.clear();\n\t}\n\tvoid init(const vector<T>&a){\n\
    \t\tinit(a.size(),[&](int i){return a[i];});\n\t}\n\ttemplate<class F>\n\tvoid\
    \ init(int n,F f){\n\t\tinit();\n\t\ta.reserve(n);\n\t\tl.reserve(n);\n\t\tr.reserve(n);\n\
    \t\tp.reserve(n);\n\t\tL.reserve(n);\n\t\tR.reserve(n);\n\t\tfor(int i=0;i<n;i++)push(f(i));\n\
    \t}\n\tvoid push(T x){\n\t\ta.push_back(x);\n\t\tl.push_back(-1);\n\t\tr.push_back(-1);\n\
    \t\tp.push_back(-1);\n\t\tL.push_back(0);\n\t\tR.push_back(-1);\n\t\tint i=-1;\n\
    \t\twhile(st.size()&&(MAX?a[st.back()]<x:a[st.back()]>x)){\n\t\t\ti=st.back();st.pop_back();\n\
    \t\t\tR[i]=n;\n\t\t}\n\t\tif(i>-1)p[i]=n,l[n]=i;\n\t\tif(st.size())r[st.back()]=n,p[n]=st.back(),L[n]=st.back()+1;\n\
    \t\tst.push_back(n++);\n\t}\n\tint root(){assert(n);return st[0];}\n\tpair<int,int>range(int\
    \ i){return{L[i],R[i]<0?n:R[i]};}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/cartesian_tree_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/cartesian_tree_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/cartesian_tree_20250608_1.hpp
- /library/work/lib/cartesian_tree_20250608_1.hpp.html
title: work/lib/cartesian_tree_20250608_1.hpp
---
