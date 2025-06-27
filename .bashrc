export PS1='$ '
clip() {
	xclip -se c ${1:-".generated"}
}
ROOT=/do
a(){
	python3 $ROOT/ar.py $@
}
g(){
	I="-I$ROOT/work/cp -I$ROOT/cp -I$ROOT/work/lib -I$ROOT/lib"
	g++ -O2 -o a $I -I$ROOT $@
	python3 $ROOT/ex.py $I $@|tee .generated>$ROOT/generated.cpp
}
