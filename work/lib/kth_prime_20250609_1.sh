#https://atcoder.jp/contests/arc197/tasks/arc197_c
seq $((10**18))|factor|awk 'NF==2{print$2}'|head -n $1|tail -n 1
