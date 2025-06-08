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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "from pathlib import Path\nfrom datetime import datetime,timezone,timedelta\n\
    import shutil\nimport sys\nROOT=Path(__file__).parent\nnow=datetime.now(timezone(timedelta(hours=9))).strftime(\"\
    %Y%m%d%H%M%S\")\ndef dfs(p):\n\tif p.is_dir():\n\t\tfor ch in p.iterdir():dfs(ch)\n\
    \t\treturn\n\tsrc=p.resolve().relative_to(ROOT)\n\tout=ROOT/'.ar'/f\"{src}.{now}\"\
    \n\tout.parent.mkdir(parents=True,exist_ok=True)\n\tshutil.copy2(p,out)\n\t#shutil.move(p,out)\n\
    \tprint(f\"{p} -> {out}\")\nfor t in sys.argv[1:]:\n\tt=Path(t)\n\tif not t.exists():print(f\"\
    {t} does not exist.\")\n\telse:dfs(t)\n"
  dependsOn: []
  isVerificationFile: false
  path: ar.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ar.py
layout: document
redirect_from:
- /library/ar.py
- /library/ar.py.html
title: ar.py
---
