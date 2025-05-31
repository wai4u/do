template<class A>
vector<int>sa_naive(A a){
	int n=a.size();
	vector<int>p(n);
	for(int i=0;i<n;i++)p[i]=i;
	sort(p.begin(),p.end(),[&](int i,int j){
		while(i<n&&j<n){
			if(a[i]!=a[j])return a[i]<a[j];
			i++,j++;
		}
		return i==n;
	});
	return p;
}
#include"pdqsort.hpp"
//doubling+argsort(pdqsort)
template<class A>
vector<int>sa_doubling(A a){
	int n=a.size();
	auto mn=*min_element(a.begin(),a.end());
	vector<int>rank(n),sa(n);
	for(int i=0;i<n;i++)rank[i]=a[i]-mn+1,sa[i]=i;
	vector<pair<int,int>>key(n);
	int d=1;
	while(1){
		for(int i=0;i<n;i++)key[i]={rank[i],i+d<n?rank[i+d]:0};
		pdqsort(sa.begin(),sa.end(),[&](int i,int j){
			return key[i]<key[j];
		});
		if(d>=n)return sa;
		d<<=1;
		int r=1;
		rank[sa[0]]=r;
		for(int i=1;i<n;i++){
			r+=key[sa[i]]>key[sa[i-1]];
			rank[sa[i]]=r;
		}
	}
}
#include"arrops.hpp"
//doubling+argsort(counting)
template<class A>
vector<int>sa_doublecounting(A a){
	int n=a.size();
	vector<int>rank=rankify(a),L(n),R(n),sa(n),sa_R(n),key(n),c;
	int d=1;
	while(1){
		c.assign(n+2,0);
		for(int i=0;i<n;i++){
			L[i]=rank[i];
			R[i]=i+d<n?rank[i+d]+1:0;
			c[R[i]+1]++;
		}
		for(int i=1;i<n+1;i++)c[i+1]+=c[i];
		for(int i=0;i<n;i++)sa_R[c[R[i]]++]=i;
		c.assign(n+2,0);
		for(int i=0;i<n;i++){
			key[i]=rank[sa_R[i]];
			c[key[i]+1]++;
		}
		for(int i=1;i<n;i++)c[i+1]+=c[i];
		for(int i=0;i<n;i++)sa[c[key[i]]++]=sa_R[i];
		if(d>=n)return sa;
		d<<=1;
		int r=0;
		rank[sa[0]]=r;
		for(int i=1;i<n;i++){
			r+=L[sa[i]]>L[sa[i-1]]||R[sa[i]]>R[sa[i-1]];
			rank[sa[i]]=r;
		}
	}
}
vector<int>sa_is(vector<int>a){
	int n=a.size();
	int m=*min_element(a.begin(),a.end());
	for(int&x:a)x=x-m+1;
	m=*max_element(a.begin(),a.end())+1;
	a.push_back(0);
	n++;
	vector<bool>is_s(n),is_lms(n);
	vector<int>lms,L(m),R(m);
	is_s[n-1]=1;
	for(int i=n;--i;){
		is_s[i-1]=a[i-1]==a[i]?is_s[i]:a[i-1]<a[i];
		if(is_lms[i]=!is_s[i-1]&&is_s[i])lms.push_back(i);
	}
	reverse(lms.begin(),lms.end());
	int k=lms.size();
	for(int x:a)R[x]++;
	for(int i=0;i<m-1;i++)R[i+1]+=L[i+1]=R[i];
	auto induce=[&](){
		vector<int>sa(n,-1);
		auto b=R;
		for(int i=k;i--;)sa[--b[a[lms[i]]]]=lms[i];
		b=L;
		for(int i=0;i<n-1;i++)if(sa[i]>0){
			int j=sa[i]-1;
			if(!is_s[j])sa[b[a[j]]++]=j;
		}
		b=R;
		for(int i=n;--i;)if(sa[i]>0){
			int j=sa[i]-1;
			if(is_s[j])sa[--b[a[j]]]=j;
		}
		return sa;
	};
	auto sa=induce();
	vector<int>rank(n,-1);
	int r=0;
	rank[n-1]=0;
	for(int i=1,j=n-1;i<n;i++)if(is_lms[sa[i]]){
		int k=sa[i];
		for(int d=0;d<n;d++){
			if(a[j+d]<a[k+d]){r++;break;}
			if(d&&is_lms[j+d]){r+=!is_lms[k+d];break;}
		}
		rank[j=k]=r;
	}
	if(r==k-1){
		vector<int>tmp(k);
		for(int i:lms)tmp[rank[i]]=i;
		swap(tmp,lms);
	}else{
		rank.erase(remove_if(rank.begin(),rank.end(),[&](int r){return r<0;}),rank.end());
		auto ord=sa_is(rank);
		for(int&i:ord)i=lms[i];
		swap(ord,lms);
	}
	sa=induce();
	return{sa.begin()+1,sa.end()};
}
template<class A>
vector<int>sa_is(A a){
	return sa_is(vector<int>(a.begin(),a.end()));
}
template<class A>
vector<int>suffix_array(A a){
	int n=a.size();
	if(!n)return{};
	if(n==1)return{0};
	if(n==2){
		if(a[0]<a[1])return{0,1};
		else return{1,0};
	}
	if(n<10)return sa_naive(a);
	if(n<40)return sa_doubling(a);
	if(n<100)return sa_doublecounting(a);
	if(*max_element(a.begin(),a.end())
		-*min_element(a.begin(),a.end())>n*20)return sa_is(rankify(a));
	return sa_is(a);
}
