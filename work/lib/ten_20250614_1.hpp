template<class T=long>
constexpr T ten(int k){return k?ten<T>(k-1)*10:1;}
