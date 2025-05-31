export PS1='$ '
clip() {
  xclip -se c ${1:-".generated"}
}
ROOT=/do
a(){
  python3 $ROOT/ar.py $@
}
g(){
  #g++ -O2 -std=c++17 -g -w -o a -I$ROOT -I$ROOT/lib $@
  g++ -O2 -o a -I$ROOT -I$ROOT/lib $@
  python3 $ROOT/ex.py -I$ROOT/lib $@|tee .generated>$ROOT/generated.cpp
}
