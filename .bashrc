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
	#g++ -O2 -o a -std=c++17 -g -w $I -I$ROOT $@
	g++ -O2 -o a $I -I$ROOT $@
	python3 $ROOT/ex.py $I $@|tee .generated>$ROOT/generated.cpp
}
t(){
	cd $ROOT
	oj-verify run -j 4
	cd -
}
p(){
	find . -type f -regex "./[0-9]+.*" -exec bash -ic 'a {}' \;-exec rm {} \;
	echo {1..9}.cpp|xargs -n 1 cp lib/main_20250608_1.cpp
}
