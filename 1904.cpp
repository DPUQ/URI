#include <bits/stdc++.h>
#define 	mod 		2
#define 	enl 		"\n"
#define 	debug(x) 	cout << #x " = " << (x) << enl
#define 	here 		cout << "Here" << enl;
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sp 			swap
#define		sz 			size()

using namespace std;
typedef		string 				st;
typedef 	long long 			ll;
typedef 	unsigned long long ull;

template<class T> st to_str(T t){stringstream ss; ss<<t; return ss.str();}

bitset<10000010> bs;
vector<int> primes;

void sieve(long bound){
 	bs.set();
 	 bs[0] = bs[1] = 0;
	for(int i = 2; i <= (bound + 1); i++){
		if(bs[i]){
			for(int j = 2*i; j <= (bound + 1) ; j+=i) bs[j] = 0;
			primes.push_back(i);
    	}
    }
}

long upper(ll x){  
    long l=0,r=primes.sz;  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);
        if( x < primes[mid])r=mid;
        else l=mid+1;
    }
    return r;  
}  

long lower(ll x){  
    long l=0,r=primes.sz;  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);  
        if(x <= primes[mid])r=mid;  
        else l=mid+1;
    }  
    return r;  
}

st toBin(long n){
	bitset<32> bin(n);
	return to_str(bin);
}

bool solve(long n, long k){
	st bn = toBin(n);
	st bk = toBin(k);
	rep(i,0,32)	if(bk[i] > bn[i]) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long a,b;
	ull n,k;
	cin >> a >> b;
	if(a == b) cout << "?" << enl;
	else{
		if(a>b) sp(a,b);
		sieve(b);
		long pa = lower(a) , pb = upper(b);
		k = b - a;
		n = (pb - pa) + k - 1;
		cout << (solve(n,k) ? "Bob" : "Alice") << enl;
	}
	return 0;
}
