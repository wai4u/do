//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
template<class T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
