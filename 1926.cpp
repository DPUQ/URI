#include <bits/stdc++.h>
#define 	MAX 		1000001
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sz 			size()
#define 	pb 			push_back
#define 	bg 			begin()
#define 	ed 			end()
#define 	all(v) 		(v.begin(),v.end())
#define 	sp 			swap

using namespace std;
typedef 	long long 			ll;
typedef 	vector<int> 		vi;

bitset<1000010> bs;
vi primes;
vi twins;

void sieve(){
  bs.set();
  bs[0] = bs[1] = 0;
	for(int i = 2; i <= MAX; i++){
		if(bs[i]){
			for(int j = 2*i; j <= MAX ; j+=i) bs[j] = 0;
			primes.pb(i);
    	}
    }
}

void prec(){
	sieve();
	long j,c;
	rep(i,0,primes.sz - 1){
		j = i + 1;
		if(primes[j] - primes[i] == 2){
			twins.pb(primes[i]);
			twins.pb(primes[j]);
		} 
	}
	twins.resize(unique all(twins) - twins.bg);

}

long upper(ll x){  
    long l=0,r=twins.size();  
    long mid;  
    while(l<r){ 
        mid=((l+r)>>1);
        if( x < twins[mid])r=mid;
        else l=mid+1;
    }
    return r;  
}

long lower(ll x){  
    long l=0,r=twins.size();  
    long mid;  
    while(l<r){  
        mid=((l+r)>>1);  
        if(x <= twins[mid])r=mid;  
        else l=mid+1;
    }  
    return r;  
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,a,b;
	prec();
	cin >> t;
	while(t--){
		cin >> a >> b;
		if(a>b) sp(a,b);
		cout << upper(b) - lower(a) << enl;
	}
	return 0;
}
