from pathlib import Path
from datetime import timezone,timedelta
import datetime
import shutil
import sys
ROOT=Path(__file__).parent
now=datetime.datetime.now(timezone(timedelta(hours=9))).strftime("%y%m%d%H%M%S")
def dfs(p):
	if p.is_dir():
		for ch in p.iterdir():dfs(ch)
		return
	src=p.resolve().relative_to(ROOT)
	out=ROOT/'.archive'/f"{src}.{now}"
	out.parent.mkdir(parents=True,exist_ok=True)
	shutil.copy2(p,out)
	#shutil.move(p,out)
	print(f"{p} -> {out}")
for t in sys.argv[1:]:
	t=Path(t)
	if not t.exists():print(f"{t} does not exist.")
	else:dfs(t)
