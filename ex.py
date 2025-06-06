import re
from pathlib import Path
import argparse
def clean(s):
	b=l=0
	n,i,t=len(s),-1,""
	while 1:
		i+=1
		if i>=n:break
		assert b+l<=1
		if b and s[i:i+2]=='*/':b=0;i+=1;continue
		if l and s[i]=='\n':l=0;t+='\n';continue
		if b or l:continue
		if s[i:i+2]=='/*':b=1;i+=1;continue
		if s[i:i+2]=='//':l=1;i+=1;continue
		t+=s[i]
	return re.sub(r'\s*\n','\n',t).strip()
p=argparse.ArgumentParser()
p.add_argument("-I",action="append",dest="ipaths")
p.add_argument("src")
a=p.parse_args()
ipaths=[Path(p) for p in a.ipaths] if a.ipaths else []
vis,ls=set(),[]
def dfs(p):
	if p in vis:return
	vis.add(p)
	pp=p.parent
	def get_dep(l):
		m=re.match(r'#include\s*"(.+)"',l)
		angle=False
		if m is None:
			m=re.match(r'#include\s*<(.+)>',l)
			if m is not None:angle=True
		if m is None:return None
		h=m.groups()[0]
		if not angle:
			c=(pp/h).resolve()
			if c.exists():return c
		for d in ipaths:
			c=(d/h).resolve()
			if c.exists():return c
		return None
	for l in clean(p.open().read()).split('\n'):
		if re.match(r"#pragma\s+once",l):continue
		c=get_dep(l)
		if c is None:ls.append(l)
		else:dfs(c)
dfs(Path(a.src).resolve())
print('\n'.join(ls))
