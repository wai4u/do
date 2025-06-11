---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.4/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import re\nfrom pathlib import Path\nimport argparse\ndef clean(s):\n\tb=l=0\n\
    \tn,i,t=len(s),-1,\"\"\n\twhile 1:\n\t\ti+=1\n\t\tif i>=n:break\n\t\tassert b+l<=1\n\
    \t\tif b and s[i:i+2]=='*/':b=0;i+=1;continue\n\t\tif l and s[i]=='\\n':l=0;t+='\\\
    n';continue\n\t\tif b or l:continue\n\t\tif s[i:i+2]=='/*':b=1;i+=1;continue\n\
    \t\tif s[i:i+2]=='//':l=1;i+=1;continue\n\t\tt+=s[i]\n\treturn re.sub(r'\\s*\\\
    n','\\n',t).strip()\np=argparse.ArgumentParser()\np.add_argument(\"-I\",action=\"\
    append\",dest=\"ipaths\")\np.add_argument(\"src\")\na=p.parse_args()\nipaths=[Path(p)\
    \ for p in a.ipaths] if a.ipaths else []\nvis,ls=set(),[]\ndef dfs(p):\n\tif p\
    \ in vis:return\n\tvis.add(p)\n\tpp=p.parent\n\tdef get_dep(l):\n\t\tm=re.match(r'#include\\\
    s*\"(.+)\"',l)\n\t\tangle=False\n\t\tif m is None:\n\t\t\tm=re.match(r'#include\\\
    s*<(.+)>',l)\n\t\t\tif m is not None:angle=True\n\t\tif m is None:return None\n\
    \t\th=m.groups()[0]\n\t\tif not angle:\n\t\t\tc=(pp/h).resolve()\n\t\t\tif c.exists():return\
    \ c\n\t\tfor d in ipaths:\n\t\t\tc=(d/h).resolve()\n\t\t\tif c.exists():return\
    \ c\n\t\treturn None\n\tfor l in clean(p.open().read()).split('\\n'):\n\t\tif\
    \ re.match(r\"#pragma once\",l) or re.match(r\"#define PROBLEM.*\",l):continue\n\
    \t\tc=get_dep(l)\n\t\tif c is None:ls.append(l)\n\t\telse:dfs(c)\ndfs(Path(a.src).resolve())\n\
    print('\\n'.join(ls))\n"
  dependsOn: []
  isVerificationFile: false
  path: ex.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ex.py
layout: document
redirect_from:
- /library/ex.py
- /library/ex.py.html
title: ex.py
---
