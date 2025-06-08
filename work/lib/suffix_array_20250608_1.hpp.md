---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: work/lib/arrops_20250608_1.hpp
    title: work/lib/arrops_20250608_1.hpp
  - icon: ':heavy_check_mark:'
    path: work/lib/pdqsort_20250608_1.hpp
    title: work/lib/pdqsort_20250608_1.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: work/lib/suffix_array_20250608_1.test.cpp
    title: work/lib/suffix_array_20250608_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"work/lib/suffix_array_20250608_1.hpp\"\ntemplate<class A>\n\
    vector<int>sa_naive(A a){\n\tint n=a.size();\n\tvector<int>p(n);\n\tfor(int i=0;i<n;i++)p[i]=i;\n\
    \tsort(p.begin(),p.end(),[&](int i,int j){\n\t\twhile(i<n&&j<n){\n\t\t\tif(a[i]!=a[j])return\
    \ a[i]<a[j];\n\t\t\ti++,j++;\n\t\t}\n\t\treturn i==n;\n\t});\n\treturn p;\n}\n\
    #line 1 \"work/lib/pdqsort_20250608_1.hpp\"\n//https://github.com/orlp/pdqsort/blob/master/pdqsort.h\n\
    #ifndef PDQSORT_H\n#define PDQSORT_H\n#include <algorithm>\n#include <cstddef>\n\
    #include <functional>\n#include <utility>\n#include <iterator>\n#if __cplusplus\
    \ >= 201103L\n    #include <cstdint>\n    #include <type_traits>\n    #define\
    \ PDQSORT_PREFER_MOVE(x) std::move(x)\n#else\n    #define PDQSORT_PREFER_MOVE(x)\
    \ (x)\n#endif\nnamespace pdqsort_detail {\n    enum {\n        insertion_sort_threshold\
    \ = 24,\n        ninther_threshold = 128,\n        partial_insertion_sort_limit\
    \ = 8,\n        block_size = 64,\n        cacheline_size = 64\n    };\n#if __cplusplus\
    \ >= 201103L\n    template<class T> struct is_default_compare : std::false_type\
    \ { };\n    template<class T> struct is_default_compare<std::less<T>> : std::true_type\
    \ { };\n    template<class T> struct is_default_compare<std::greater<T>> : std::true_type\
    \ { };\n#endif\n    template<class T>\n    inline int log2(T n) {\n        int\
    \ log = 0;\n        while (n >>= 1) ++log;\n        return log;\n    }\n    template<class\
    \ Iter, class Compare>\n    inline void insertion_sort(Iter begin, Iter end, Compare\
    \ comp) {\n        typedef typename std::iterator_traits<Iter>::value_type T;\n\
    \        if (begin == end) return;\n        for (Iter cur = begin + 1; cur !=\
    \ end; ++cur) {\n            Iter sift = cur;\n            Iter sift_1 = cur -\
    \ 1;\n            if (comp(*sift, *sift_1)) {\n                T tmp = PDQSORT_PREFER_MOVE(*sift);\n\
    \                do { *sift-- = PDQSORT_PREFER_MOVE(*sift_1); }\n            \
    \    while (sift != begin && comp(tmp, *--sift_1));\n                *sift = PDQSORT_PREFER_MOVE(tmp);\n\
    \            }\n        }\n    }\n    template<class Iter, class Compare>\n  \
    \  inline void unguarded_insertion_sort(Iter begin, Iter end, Compare comp) {\n\
    \        typedef typename std::iterator_traits<Iter>::value_type T;\n        if\
    \ (begin == end) return;\n        for (Iter cur = begin + 1; cur != end; ++cur)\
    \ {\n            Iter sift = cur;\n            Iter sift_1 = cur - 1;\n      \
    \      if (comp(*sift, *sift_1)) {\n                T tmp = PDQSORT_PREFER_MOVE(*sift);\n\
    \                do { *sift-- = PDQSORT_PREFER_MOVE(*sift_1); }\n            \
    \    while (comp(tmp, *--sift_1));\n                *sift = PDQSORT_PREFER_MOVE(tmp);\n\
    \            }\n        }\n    }\n    template<class Iter, class Compare>\n  \
    \  inline bool partial_insertion_sort(Iter begin, Iter end, Compare comp) {\n\
    \        typedef typename std::iterator_traits<Iter>::value_type T;\n        if\
    \ (begin == end) return true;\n        std::size_t limit = 0;\n        for (Iter\
    \ cur = begin + 1; cur != end; ++cur) {\n            Iter sift = cur;\n      \
    \      Iter sift_1 = cur - 1;\n            if (comp(*sift, *sift_1)) {\n     \
    \           T tmp = PDQSORT_PREFER_MOVE(*sift);\n                do { *sift--\
    \ = PDQSORT_PREFER_MOVE(*sift_1); }\n                while (sift != begin && comp(tmp,\
    \ *--sift_1));\n                *sift = PDQSORT_PREFER_MOVE(tmp);\n          \
    \      limit += cur - sift;\n            }\n            if (limit > partial_insertion_sort_limit)\
    \ return false;\n        }\n        return true;\n    }\n    template<class Iter,\
    \ class Compare>\n    inline void sort2(Iter a, Iter b, Compare comp) {\n    \
    \    if (comp(*b, *a)) std::iter_swap(a, b);\n    }\n    template<class Iter,\
    \ class Compare>\n    inline void sort3(Iter a, Iter b, Iter c, Compare comp)\
    \ {\n        sort2(a, b, comp);\n        sort2(b, c, comp);\n        sort2(a,\
    \ b, comp);\n    }\n    template<class T>\n    inline T* align_cacheline(T* p)\
    \ {\n#if defined(UINTPTR_MAX) && __cplusplus >= 201103L\n        std::uintptr_t\
    \ ip = reinterpret_cast<std::uintptr_t>(p);\n#else\n        std::size_t ip = reinterpret_cast<std::size_t>(p);\n\
    #endif\n        ip = (ip + cacheline_size - 1) & -cacheline_size;\n        return\
    \ reinterpret_cast<T*>(ip);\n    }\n    template<class Iter>\n    inline void\
    \ swap_offsets(Iter first, Iter last,\n                             unsigned char*\
    \ offsets_l, unsigned char* offsets_r,\n                             size_t num,\
    \ bool use_swaps) {\n        typedef typename std::iterator_traits<Iter>::value_type\
    \ T;\n        if (use_swaps) {\n            for (size_t i = 0; i < num; ++i) {\n\
    \                std::iter_swap(first + offsets_l[i], last - offsets_r[i]);\n\
    \            }\n        } else if (num > 0) {\n            Iter l = first + offsets_l[0];\
    \ Iter r = last - offsets_r[0];\n            T tmp(PDQSORT_PREFER_MOVE(*l)); *l\
    \ = PDQSORT_PREFER_MOVE(*r);\n            for (size_t i = 1; i < num; ++i) {\n\
    \                l = first + offsets_l[i]; *r = PDQSORT_PREFER_MOVE(*l);\n   \
    \             r = last - offsets_r[i]; *l = PDQSORT_PREFER_MOVE(*r);\n       \
    \     }\n            *r = PDQSORT_PREFER_MOVE(tmp);\n        }\n    }\n    template<class\
    \ Iter, class Compare>\n    inline std::pair<Iter, bool> partition_right_branchless(Iter\
    \ begin, Iter end, Compare comp) {\n        typedef typename std::iterator_traits<Iter>::value_type\
    \ T;\n        T pivot(PDQSORT_PREFER_MOVE(*begin));\n        Iter first = begin;\n\
    \        Iter last = end;\n        while (comp(*++first, pivot));\n        if\
    \ (first - 1 == begin) while (first < last && !comp(*--last, pivot));\n      \
    \  else                    while (                !comp(*--last, pivot));\n  \
    \      bool already_partitioned = first >= last;\n        if (!already_partitioned)\
    \ {\n            std::iter_swap(first, last);\n            ++first;\n        \
    \    unsigned char offsets_l_storage[block_size + cacheline_size];\n         \
    \   unsigned char offsets_r_storage[block_size + cacheline_size];\n          \
    \  unsigned char* offsets_l = align_cacheline(offsets_l_storage);\n          \
    \  unsigned char* offsets_r = align_cacheline(offsets_r_storage);\n          \
    \  Iter offsets_l_base = first;\n            Iter offsets_r_base = last;\n   \
    \         size_t num_l, num_r, start_l, start_r;\n            num_l = num_r =\
    \ start_l = start_r = 0;\n            while (first < last) {\n               \
    \ size_t num_unknown = last - first;\n                size_t left_split = num_l\
    \ == 0 ? (num_r == 0 ? num_unknown / 2 : num_unknown) : 0;\n                size_t\
    \ right_split = num_r == 0 ? (num_unknown - left_split) : 0;\n               \
    \ if (left_split >= block_size) {\n                    for (size_t i = 0; i <\
    \ block_size;) {\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                        offsets_l[num_l] = i++; num_l += !comp(*first,\
    \ pivot); ++first;\n                    }\n                } else {\n        \
    \            for (size_t i = 0; i < left_split;) {\n                        offsets_l[num_l]\
    \ = i++; num_l += !comp(*first, pivot); ++first;\n                    }\n    \
    \            }\n                if (right_split >= block_size) {\n           \
    \         for (size_t i = 0; i < block_size;) {\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                        offsets_r[num_r]\
    \ = ++i; num_r += comp(*--last, pivot);\n                    }\n             \
    \   } else {\n                    for (size_t i = 0; i < right_split;) {\n   \
    \                     offsets_r[num_r] = ++i; num_r += comp(*--last, pivot);\n\
    \                    }\n                }\n                size_t num = std::min(num_l,\
    \ num_r);\n                swap_offsets(offsets_l_base, offsets_r_base,\n    \
    \                         offsets_l + start_l, offsets_r + start_r,\n        \
    \                     num, num_l == num_r);\n                num_l -= num; num_r\
    \ -= num;\n                start_l += num; start_r += num;\n                if\
    \ (num_l == 0) {\n                    start_l = 0;\n                    offsets_l_base\
    \ = first;\n                }\n                if (num_r == 0) {\n           \
    \         start_r = 0;\n                    offsets_r_base = last;\n         \
    \       }\n            }\n            if (num_l) {\n                offsets_l\
    \ += start_l;\n                while (num_l--) std::iter_swap(offsets_l_base +\
    \ offsets_l[num_l], --last);\n                first = last;\n            }\n \
    \           if (num_r) {\n                offsets_r += start_r;\n            \
    \    while (num_r--) std::iter_swap(offsets_r_base - offsets_r[num_r], first),\
    \ ++first;\n                last = first;\n            }\n        }\n        Iter\
    \ pivot_pos = first - 1;\n        *begin = PDQSORT_PREFER_MOVE(*pivot_pos);\n\
    \        *pivot_pos = PDQSORT_PREFER_MOVE(pivot);\n        return std::make_pair(pivot_pos,\
    \ already_partitioned);\n    }\n    template<class Iter, class Compare>\n    inline\
    \ std::pair<Iter, bool> partition_right(Iter begin, Iter end, Compare comp) {\n\
    \        typedef typename std::iterator_traits<Iter>::value_type T;\n        T\
    \ pivot(PDQSORT_PREFER_MOVE(*begin));\n        Iter first = begin;\n        Iter\
    \ last = end;\n        while (comp(*++first, pivot));\n        if (first - 1 ==\
    \ begin) while (first < last && !comp(*--last, pivot));\n        else        \
    \            while (                !comp(*--last, pivot));\n        bool already_partitioned\
    \ = first >= last;\n        while (first < last) {\n            std::iter_swap(first,\
    \ last);\n            while (comp(*++first, pivot));\n            while (!comp(*--last,\
    \ pivot));\n        }\n        Iter pivot_pos = first - 1;\n        *begin = PDQSORT_PREFER_MOVE(*pivot_pos);\n\
    \        *pivot_pos = PDQSORT_PREFER_MOVE(pivot);\n        return std::make_pair(pivot_pos,\
    \ already_partitioned);\n    }\n    template<class Iter, class Compare>\n    inline\
    \ Iter partition_left(Iter begin, Iter end, Compare comp) {\n        typedef typename\
    \ std::iterator_traits<Iter>::value_type T;\n        T pivot(PDQSORT_PREFER_MOVE(*begin));\n\
    \        Iter first = begin;\n        Iter last = end;\n        while (comp(pivot,\
    \ *--last));\n        if (last + 1 == end) while (first < last && !comp(pivot,\
    \ *++first));\n        else                 while (                !comp(pivot,\
    \ *++first));\n        while (first < last) {\n            std::iter_swap(first,\
    \ last);\n            while (comp(pivot, *--last));\n            while (!comp(pivot,\
    \ *++first));\n        }\n        Iter pivot_pos = last;\n        *begin = PDQSORT_PREFER_MOVE(*pivot_pos);\n\
    \        *pivot_pos = PDQSORT_PREFER_MOVE(pivot);\n        return pivot_pos;\n\
    \    }\n    template<class Iter, class Compare, bool Branchless>\n    inline void\
    \ pdqsort_loop(Iter begin, Iter end, Compare comp, int bad_allowed, bool leftmost\
    \ = true) {\n        typedef typename std::iterator_traits<Iter>::difference_type\
    \ diff_t;\n        while (true) {\n            diff_t size = end - begin;\n  \
    \          if (size < insertion_sort_threshold) {\n                if (leftmost)\
    \ insertion_sort(begin, end, comp);\n                else unguarded_insertion_sort(begin,\
    \ end, comp);\n                return;\n            }\n            diff_t s2 =\
    \ size / 2;\n            if (size > ninther_threshold) {\n                sort3(begin,\
    \ begin + s2, end - 1, comp);\n                sort3(begin + 1, begin + (s2 -\
    \ 1), end - 2, comp);\n                sort3(begin + 2, begin + (s2 + 1), end\
    \ - 3, comp);\n                sort3(begin + (s2 - 1), begin + s2, begin + (s2\
    \ + 1), comp);\n                std::iter_swap(begin, begin + s2);\n         \
    \   } else sort3(begin + s2, begin, end - 1, comp);\n            if (!leftmost\
    \ && !comp(*(begin - 1), *begin)) {\n                begin = partition_left(begin,\
    \ end, comp) + 1;\n                continue;\n            }\n            std::pair<Iter,\
    \ bool> part_result =\n                Branchless ? partition_right_branchless(begin,\
    \ end, comp)\n                           : partition_right(begin, end, comp);\n\
    \            Iter pivot_pos = part_result.first;\n            bool already_partitioned\
    \ = part_result.second;\n            diff_t l_size = pivot_pos - begin;\n    \
    \        diff_t r_size = end - (pivot_pos + 1);\n            bool highly_unbalanced\
    \ = l_size < size / 8 || r_size < size / 8;\n            if (highly_unbalanced)\
    \ {\n                if (--bad_allowed == 0) {\n                    std::make_heap(begin,\
    \ end, comp);\n                    std::sort_heap(begin, end, comp);\n       \
    \             return;\n                }\n                if (l_size >= insertion_sort_threshold)\
    \ {\n                    std::iter_swap(begin,             begin + l_size / 4);\n\
    \                    std::iter_swap(pivot_pos - 1, pivot_pos - l_size / 4);\n\
    \                    if (l_size > ninther_threshold) {\n                     \
    \   std::iter_swap(begin + 1,         begin + (l_size / 4 + 1));\n           \
    \             std::iter_swap(begin + 2,         begin + (l_size / 4 + 2));\n \
    \                       std::iter_swap(pivot_pos - 2, pivot_pos - (l_size / 4\
    \ + 1));\n                        std::iter_swap(pivot_pos - 3, pivot_pos - (l_size\
    \ / 4 + 2));\n                    }\n                }\n                if (r_size\
    \ >= insertion_sort_threshold) {\n                    std::iter_swap(pivot_pos\
    \ + 1, pivot_pos + (1 + r_size / 4));\n                    std::iter_swap(end\
    \ - 1,                   end - r_size / 4);\n                    if (r_size >\
    \ ninther_threshold) {\n                        std::iter_swap(pivot_pos + 2,\
    \ pivot_pos + (2 + r_size / 4));\n                        std::iter_swap(pivot_pos\
    \ + 3, pivot_pos + (3 + r_size / 4));\n                        std::iter_swap(end\
    \ - 2,             end - (1 + r_size / 4));\n                        std::iter_swap(end\
    \ - 3,             end - (2 + r_size / 4));\n                    }\n         \
    \       }\n            } else {\n                if (already_partitioned && partial_insertion_sort(begin,\
    \ pivot_pos, comp)\n                                        && partial_insertion_sort(pivot_pos\
    \ + 1, end, comp)) return;\n            }\n            pdqsort_loop<Iter, Compare,\
    \ Branchless>(begin, pivot_pos, comp, bad_allowed, leftmost);\n            begin\
    \ = pivot_pos + 1;\n            leftmost = false;\n        }\n    }\n}\ntemplate<class\
    \ Iter, class Compare>\ninline void pdqsort(Iter begin, Iter end, Compare comp)\
    \ {\n    if (begin == end) return;\n#if __cplusplus >= 201103L\n    pdqsort_detail::pdqsort_loop<Iter,\
    \ Compare,\n        pdqsort_detail::is_default_compare<typename std::decay<Compare>::type>::value\
    \ &&\n        std::is_arithmetic<typename std::iterator_traits<Iter>::value_type>::value>(\n\
    \        begin, end, comp, pdqsort_detail::log2(end - begin));\n#else\n    pdqsort_detail::pdqsort_loop<Iter,\
    \ Compare, false>(\n        begin, end, comp, pdqsort_detail::log2(end - begin));\n\
    #endif\n}\ntemplate<class Iter>\ninline void pdqsort(Iter begin, Iter end) {\n\
    \    typedef typename std::iterator_traits<Iter>::value_type T;\n    pdqsort(begin,\
    \ end, std::less<T>());\n}\ntemplate<class Iter, class Compare>\ninline void pdqsort_branchless(Iter\
    \ begin, Iter end, Compare comp) {\n    if (begin == end) return;\n    pdqsort_detail::pdqsort_loop<Iter,\
    \ Compare, true>(\n        begin, end, comp, pdqsort_detail::log2(end - begin));\n\
    }\ntemplate<class Iter>\ninline void pdqsort_branchless(Iter begin, Iter end)\
    \ {\n    typedef typename std::iterator_traits<Iter>::value_type T;\n    pdqsort_branchless(begin,\
    \ end, std::less<T>());\n}\n#undef PDQSORT_PREFER_MOVE\n#endif\n#line 16 \"work/lib/suffix_array_20250608_1.hpp\"\
    \n//doubling+argsort(pdqsort)\ntemplate<class A>\nvector<int>sa_doubling(A a){\n\
    \tint n=a.size();\n\tauto mn=*min_element(a.begin(),a.end());\n\tvector<int>rank(n),sa(n);\n\
    \tfor(int i=0;i<n;i++)rank[i]=a[i]-mn+1,sa[i]=i;\n\tvector<pair<int,int>>key(n);\n\
    \tint d=1;\n\twhile(1){\n\t\tfor(int i=0;i<n;i++)key[i]={rank[i],i+d<n?rank[i+d]:0};\n\
    \t\tpdqsort(sa.begin(),sa.end(),[&](int i,int j){\n\t\t\treturn key[i]<key[j];\n\
    \t\t});\n\t\tif(d>=n)return sa;\n\t\td<<=1;\n\t\tint r=1;\n\t\trank[sa[0]]=r;\n\
    \t\tfor(int i=1;i<n;i++){\n\t\t\tr+=key[sa[i]]>key[sa[i-1]];\n\t\t\trank[sa[i]]=r;\n\
    \t\t}\n\t}\n}\n#line 1 \"work/lib/arrops_20250608_1.hpp\"\ntemplate<class A>\n\
    vector<int>argsort(A a,bool desc=0,bool rev=0){\n\tint n=a.size();\n\tvector<int>p(n);\n\
    \tfor(int i=0;i<n;i++)p[i]=i;\n\tsort(p.begin(),p.end(),[&](int i,int j){\n\t\t\
    if(a[i]!=a[j])return desc?a[i]>a[j]:a[i]<a[j];\n\t\treturn rev?i>j:i<j;\n\t});\n\
    \treturn p;\n}\ntemplate<class A>\nvector<int>rankify(A a){\n\tint n=a.size();\n\
    \tif(!n)return{};\n\tauto p=argsort(a);\n\tvector<int>r(n);\n\tr[p[0]]=0;\n\t\
    for(int i=1;i<n;i++)r[p[i]]=r[p[i-1]]+(a[p[i]]>a[p[i-1]]);\n\treturn r;\n}\n#line\
    \ 41 \"work/lib/suffix_array_20250608_1.hpp\"\n//doubling+argsort(counting)\n\
    template<class A>\nvector<int>sa_doublecounting(A a){\n\tint n=a.size();\n\tvector<int>rank=rankify(a),L(n),R(n),sa(n),sa_R(n),key(n),c;\n\
    \tint d=1;\n\twhile(1){\n\t\tc.assign(n+2,0);\n\t\tfor(int i=0;i<n;i++){\n\t\t\
    \tL[i]=rank[i];\n\t\t\tR[i]=i+d<n?rank[i+d]+1:0;\n\t\t\tc[R[i]+1]++;\n\t\t}\n\t\
    \tfor(int i=1;i<n+1;i++)c[i+1]+=c[i];\n\t\tfor(int i=0;i<n;i++)sa_R[c[R[i]]++]=i;\n\
    \t\tc.assign(n+2,0);\n\t\tfor(int i=0;i<n;i++){\n\t\t\tkey[i]=rank[sa_R[i]];\n\
    \t\t\tc[key[i]+1]++;\n\t\t}\n\t\tfor(int i=1;i<n;i++)c[i+1]+=c[i];\n\t\tfor(int\
    \ i=0;i<n;i++)sa[c[key[i]]++]=sa_R[i];\n\t\tif(d>=n)return sa;\n\t\td<<=1;\n\t\
    \tint r=0;\n\t\trank[sa[0]]=r;\n\t\tfor(int i=1;i<n;i++){\n\t\t\tr+=L[sa[i]]>L[sa[i-1]]||R[sa[i]]>R[sa[i-1]];\n\
    \t\t\trank[sa[i]]=r;\n\t\t}\n\t}\n}\nvector<int>sa_is(vector<int>a){\n\tint n=a.size();\n\
    \tint m=*min_element(a.begin(),a.end());\n\tfor(int&x:a)x=x-m+1;\n\tm=*max_element(a.begin(),a.end())+1;\n\
    \ta.push_back(0);\n\tn++;\n\tvector<bool>is_s(n),is_lms(n);\n\tvector<int>lms,L(m),R(m);\n\
    \tis_s[n-1]=1;\n\tfor(int i=n;--i;){\n\t\tis_s[i-1]=a[i-1]==a[i]?is_s[i]:a[i-1]<a[i];\n\
    \t\tif(is_lms[i]=!is_s[i-1]&&is_s[i])lms.push_back(i);\n\t}\n\treverse(lms.begin(),lms.end());\n\
    \tint k=lms.size();\n\tfor(int x:a)R[x]++;\n\tfor(int i=0;i<m-1;i++)R[i+1]+=L[i+1]=R[i];\n\
    \tauto induce=[&](){\n\t\tvector<int>sa(n,-1);\n\t\tauto b=R;\n\t\tfor(int i=k;i--;)sa[--b[a[lms[i]]]]=lms[i];\n\
    \t\tb=L;\n\t\tfor(int i=0;i<n-1;i++)if(sa[i]>0){\n\t\t\tint j=sa[i]-1;\n\t\t\t\
    if(!is_s[j])sa[b[a[j]]++]=j;\n\t\t}\n\t\tb=R;\n\t\tfor(int i=n;--i;)if(sa[i]>0){\n\
    \t\t\tint j=sa[i]-1;\n\t\t\tif(is_s[j])sa[--b[a[j]]]=j;\n\t\t}\n\t\treturn sa;\n\
    \t};\n\tauto sa=induce();\n\tvector<int>rank(n,-1);\n\tint r=0;\n\trank[n-1]=0;\n\
    \tfor(int i=1,j=n-1;i<n;i++)if(is_lms[sa[i]]){\n\t\tint k=sa[i];\n\t\tfor(int\
    \ d=0;d<n;d++){\n\t\t\tif(a[j+d]<a[k+d]){r++;break;}\n\t\t\tif(d&&is_lms[j+d]){r+=!is_lms[k+d];break;}\n\
    \t\t}\n\t\trank[j=k]=r;\n\t}\n\tif(r==k-1){\n\t\tvector<int>tmp(k);\n\t\tfor(int\
    \ i:lms)tmp[rank[i]]=i;\n\t\tswap(tmp,lms);\n\t}else{\n\t\trank.erase(remove_if(rank.begin(),rank.end(),[&](int\
    \ r){return r<0;}),rank.end());\n\t\tauto ord=sa_is(rank);\n\t\tfor(int&i:ord)i=lms[i];\n\
    \t\tswap(ord,lms);\n\t}\n\tsa=induce();\n\treturn{sa.begin()+1,sa.end()};\n}\n\
    template<class A>\nvector<int>sa_is(A a){\n\treturn sa_is(vector<int>(a.begin(),a.end()));\n\
    }\ntemplate<class A>\nvector<int>suffix_array(A a){\n\tint n=a.size();\n\tif(!n)return{};\n\
    \tif(n==1)return{0};\n\tif(n==2){\n\t\tif(a[0]<a[1])return{0,1};\n\t\telse return{1,0};\n\
    \t}\n\tif(n<10)return sa_naive(a);\n\tif(n<40)return sa_doubling(a);\n\tif(n<100)return\
    \ sa_doublecounting(a);\n\tif(*max_element(a.begin(),a.end())\n\t\t-*min_element(a.begin(),a.end())>n*20)return\
    \ sa_is(rankify(a));\n\treturn sa_is(a);\n}\n"
  code: "template<class A>\nvector<int>sa_naive(A a){\n\tint n=a.size();\n\tvector<int>p(n);\n\
    \tfor(int i=0;i<n;i++)p[i]=i;\n\tsort(p.begin(),p.end(),[&](int i,int j){\n\t\t\
    while(i<n&&j<n){\n\t\t\tif(a[i]!=a[j])return a[i]<a[j];\n\t\t\ti++,j++;\n\t\t\
    }\n\t\treturn i==n;\n\t});\n\treturn p;\n}\n#include\"pdqsort_20250608_1.hpp\"\
    \n//doubling+argsort(pdqsort)\ntemplate<class A>\nvector<int>sa_doubling(A a){\n\
    \tint n=a.size();\n\tauto mn=*min_element(a.begin(),a.end());\n\tvector<int>rank(n),sa(n);\n\
    \tfor(int i=0;i<n;i++)rank[i]=a[i]-mn+1,sa[i]=i;\n\tvector<pair<int,int>>key(n);\n\
    \tint d=1;\n\twhile(1){\n\t\tfor(int i=0;i<n;i++)key[i]={rank[i],i+d<n?rank[i+d]:0};\n\
    \t\tpdqsort(sa.begin(),sa.end(),[&](int i,int j){\n\t\t\treturn key[i]<key[j];\n\
    \t\t});\n\t\tif(d>=n)return sa;\n\t\td<<=1;\n\t\tint r=1;\n\t\trank[sa[0]]=r;\n\
    \t\tfor(int i=1;i<n;i++){\n\t\t\tr+=key[sa[i]]>key[sa[i-1]];\n\t\t\trank[sa[i]]=r;\n\
    \t\t}\n\t}\n}\n#include\"arrops_20250608_1.hpp\"\n//doubling+argsort(counting)\n\
    template<class A>\nvector<int>sa_doublecounting(A a){\n\tint n=a.size();\n\tvector<int>rank=rankify(a),L(n),R(n),sa(n),sa_R(n),key(n),c;\n\
    \tint d=1;\n\twhile(1){\n\t\tc.assign(n+2,0);\n\t\tfor(int i=0;i<n;i++){\n\t\t\
    \tL[i]=rank[i];\n\t\t\tR[i]=i+d<n?rank[i+d]+1:0;\n\t\t\tc[R[i]+1]++;\n\t\t}\n\t\
    \tfor(int i=1;i<n+1;i++)c[i+1]+=c[i];\n\t\tfor(int i=0;i<n;i++)sa_R[c[R[i]]++]=i;\n\
    \t\tc.assign(n+2,0);\n\t\tfor(int i=0;i<n;i++){\n\t\t\tkey[i]=rank[sa_R[i]];\n\
    \t\t\tc[key[i]+1]++;\n\t\t}\n\t\tfor(int i=1;i<n;i++)c[i+1]+=c[i];\n\t\tfor(int\
    \ i=0;i<n;i++)sa[c[key[i]]++]=sa_R[i];\n\t\tif(d>=n)return sa;\n\t\td<<=1;\n\t\
    \tint r=0;\n\t\trank[sa[0]]=r;\n\t\tfor(int i=1;i<n;i++){\n\t\t\tr+=L[sa[i]]>L[sa[i-1]]||R[sa[i]]>R[sa[i-1]];\n\
    \t\t\trank[sa[i]]=r;\n\t\t}\n\t}\n}\nvector<int>sa_is(vector<int>a){\n\tint n=a.size();\n\
    \tint m=*min_element(a.begin(),a.end());\n\tfor(int&x:a)x=x-m+1;\n\tm=*max_element(a.begin(),a.end())+1;\n\
    \ta.push_back(0);\n\tn++;\n\tvector<bool>is_s(n),is_lms(n);\n\tvector<int>lms,L(m),R(m);\n\
    \tis_s[n-1]=1;\n\tfor(int i=n;--i;){\n\t\tis_s[i-1]=a[i-1]==a[i]?is_s[i]:a[i-1]<a[i];\n\
    \t\tif(is_lms[i]=!is_s[i-1]&&is_s[i])lms.push_back(i);\n\t}\n\treverse(lms.begin(),lms.end());\n\
    \tint k=lms.size();\n\tfor(int x:a)R[x]++;\n\tfor(int i=0;i<m-1;i++)R[i+1]+=L[i+1]=R[i];\n\
    \tauto induce=[&](){\n\t\tvector<int>sa(n,-1);\n\t\tauto b=R;\n\t\tfor(int i=k;i--;)sa[--b[a[lms[i]]]]=lms[i];\n\
    \t\tb=L;\n\t\tfor(int i=0;i<n-1;i++)if(sa[i]>0){\n\t\t\tint j=sa[i]-1;\n\t\t\t\
    if(!is_s[j])sa[b[a[j]]++]=j;\n\t\t}\n\t\tb=R;\n\t\tfor(int i=n;--i;)if(sa[i]>0){\n\
    \t\t\tint j=sa[i]-1;\n\t\t\tif(is_s[j])sa[--b[a[j]]]=j;\n\t\t}\n\t\treturn sa;\n\
    \t};\n\tauto sa=induce();\n\tvector<int>rank(n,-1);\n\tint r=0;\n\trank[n-1]=0;\n\
    \tfor(int i=1,j=n-1;i<n;i++)if(is_lms[sa[i]]){\n\t\tint k=sa[i];\n\t\tfor(int\
    \ d=0;d<n;d++){\n\t\t\tif(a[j+d]<a[k+d]){r++;break;}\n\t\t\tif(d&&is_lms[j+d]){r+=!is_lms[k+d];break;}\n\
    \t\t}\n\t\trank[j=k]=r;\n\t}\n\tif(r==k-1){\n\t\tvector<int>tmp(k);\n\t\tfor(int\
    \ i:lms)tmp[rank[i]]=i;\n\t\tswap(tmp,lms);\n\t}else{\n\t\trank.erase(remove_if(rank.begin(),rank.end(),[&](int\
    \ r){return r<0;}),rank.end());\n\t\tauto ord=sa_is(rank);\n\t\tfor(int&i:ord)i=lms[i];\n\
    \t\tswap(ord,lms);\n\t}\n\tsa=induce();\n\treturn{sa.begin()+1,sa.end()};\n}\n\
    template<class A>\nvector<int>sa_is(A a){\n\treturn sa_is(vector<int>(a.begin(),a.end()));\n\
    }\ntemplate<class A>\nvector<int>suffix_array(A a){\n\tint n=a.size();\n\tif(!n)return{};\n\
    \tif(n==1)return{0};\n\tif(n==2){\n\t\tif(a[0]<a[1])return{0,1};\n\t\telse return{1,0};\n\
    \t}\n\tif(n<10)return sa_naive(a);\n\tif(n<40)return sa_doubling(a);\n\tif(n<100)return\
    \ sa_doublecounting(a);\n\tif(*max_element(a.begin(),a.end())\n\t\t-*min_element(a.begin(),a.end())>n*20)return\
    \ sa_is(rankify(a));\n\treturn sa_is(a);\n}\n"
  dependsOn:
  - work/lib/pdqsort_20250608_1.hpp
  - work/lib/arrops_20250608_1.hpp
  isVerificationFile: false
  path: work/lib/suffix_array_20250608_1.hpp
  requiredBy: []
  timestamp: '2025-06-08 16:23:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - work/lib/suffix_array_20250608_1.test.cpp
documentation_of: work/lib/suffix_array_20250608_1.hpp
layout: document
redirect_from:
- /library/work/lib/suffix_array_20250608_1.hpp
- /library/work/lib/suffix_array_20250608_1.hpp.html
title: work/lib/suffix_array_20250608_1.hpp
---
