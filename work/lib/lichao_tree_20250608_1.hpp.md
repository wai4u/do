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
    - https://github.com/yosupo06/library-checker-problems/blob/master/data_structure/line_add_get_min/sol/correct.cpp
    - https://smijake3.hatenablog.com/entry/2018/06/16/144548
  bundledCode: "#line 1 \"work/lib/lichao_tree_20250608_1.hpp\"\n//https://github.com/yosupo06/library-checker-problems/blob/master/data_structure/line_add_get_min/sol/correct.cpp\n\
    //|x|<=10^9,|a|<=10^9,|b|<=10^18\n//https://smijake3.hatenablog.com/entry/2018/06/16/144548\n\
    struct line{\n\tlong a,b;\n\tlong operator()(long x){return a*x+b;}\n};\nstruct\
    \ lichao_tree{\n\tint n,w;\n\tvector<int>xs;\n\tvector<line>f;\n\tbool built=0;\n\
    \tvoid add_point(int x){\n\t\tassert(!built);\n\t\txs.push_back(x);\n\t}\n\tvoid\
    \ build(){\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\tsort(xs.begin(),xs.end());\n\
    \t\txs.erase(unique(xs.begin(),xs.end()),xs.end());\n\t\tn=xs.size(),w=1;\n\t\t\
    while(w<n)w<<=1;\n\t\t//if(n)xs.resize(w,max_element(xs.begin(),xs.end()));\n\t\
    \txs.resize(w,1<<30);\n\t\tf.assign(w+w,{0,2l<<60});\n\t}\n\tvoid add_line(line\
    \ g){\n\t\tbuild();\n\t\tadd_line(g,0,w,1);\n\t}\n\tvoid add_line(line g,int l,int\
    \ r,int i){\n\t\tint c=l+r>>1;\n\t\tlong x=xs[c];\n\t\tif(g(x)<f[i](x))swap(g,f[i]);\n\
    \t\tif(r-l==1)return;\n\t\tif(g.a>f[i].a)add_line(g,l,c,i<<1);\n\t\tif(g.a<f[i].a)add_line(g,c,r,i<<1|1);\n\
    \t}\n\tlong calc(long x){\n\t\tint i=lower_bound(xs.begin(),xs.end(),x)-xs.begin();\n\
    \t\tassert(0<=i&&i<n&&xs[i]==x);\n\t\tlong y=2l<<60;\n\t\ti+=w;\n\t\twhile(i>=1){\n\
    \t\t\ty=min(y,f[i](x));\n\t\t\ti>>=1;\n\t\t}\n\t\treturn y;\n\t}\n};\n"
  code: "//https://github.com/yosupo06/library-checker-problems/blob/master/data_structure/line_add_get_min/sol/correct.cpp\n\
    //|x|<=10^9,|a|<=10^9,|b|<=10^18\n//https://smijake3.hatenablog.com/entry/2018/06/16/144548\n\
    struct line{\n\tlong a,b;\n\tlong operator()(long x){return a*x+b;}\n};\nstruct\
    \ lichao_tree{\n\tint n,w;\n\tvector<int>xs;\n\tvector<line>f;\n\tbool built=0;\n\
    \tvoid add_point(int x){\n\t\tassert(!built);\n\t\txs.push_back(x);\n\t}\n\tvoid\
    \ build(){\n\t\tif(built)return;\n\t\tbuilt=1;\n\t\tsort(xs.begin(),xs.end());\n\
    \t\txs.erase(unique(xs.begin(),xs.end()),xs.end());\n\t\tn=xs.size(),w=1;\n\t\t\
    while(w<n)w<<=1;\n\t\t//if(n)xs.resize(w,max_element(xs.begin(),xs.end()));\n\t\
    \txs.resize(w,1<<30);\n\t\tf.assign(w+w,{0,2l<<60});\n\t}\n\tvoid add_line(line\
    \ g){\n\t\tbuild();\n\t\tadd_line(g,0,w,1);\n\t}\n\tvoid add_line(line g,int l,int\
    \ r,int i){\n\t\tint c=l+r>>1;\n\t\tlong x=xs[c];\n\t\tif(g(x)<f[i](x))swap(g,f[i]);\n\
    \t\tif(r-l==1)return;\n\t\tif(g.a>f[i].a)add_line(g,l,c,i<<1);\n\t\tif(g.a<f[i].a)add_line(g,c,r,i<<1|1);\n\
    \t}\n\tlong calc(long x){\n\t\tint i=lower_bound(xs.begin(),xs.end(),x)-xs.begin();\n\
    \t\tassert(0<=i&&i<n&&xs[i]==x);\n\t\tlong y=2l<<60;\n\t\ti+=w;\n\t\twhile(i>=1){\n\
    \t\t\ty=min(y,f[i](x));\n\t\t\ti>>=1;\n\t\t}\n\t\treturn y;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: work/lib/lichao_tree_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: work/lib/lichao_tree_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/lichao_tree_20250608_1.hpp
- /library/work/lib/lichao_tree_20250608_1.hpp.html
title: work/lib/lichao_tree_20250608_1.hpp
---
