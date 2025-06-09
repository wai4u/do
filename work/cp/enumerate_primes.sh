#https://atcoder.jp/contests/arc197/tasks/arc197_c
# |wc -lをつけるとカウントになる
seq ${1:-10000000}|factor|awk 'NF==2{print$2}'|nl -w2 -s':'
