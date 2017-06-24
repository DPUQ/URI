#include <bits/stdc++.h>
#define 	MAX 		100001
#define 	mod 		1000000009
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	long long 			ll;

ll fact[MAX];

void fill(){
	fact[0] = fact[1] = 1;
	rep(i,2,MAX) fact[i] = (i*fact[i-1]) % mod;
}

ll mod_pow( ll b, ll e)
{
    ll r = 1;
    ll pow = b % mod;
    while( e > 0 )
    {
        if( e&1 ) r = ( r*pow )%mod;
        pow = ( pow*pow )%mod;
        e >>= 1;
    }
    return r;
}

ll inv( ll x )
{
    return mod_pow( x, mod-2 );
}

ll solve(int n){
	return (fact[n] % mod * inv(fact[3]) % mod ) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	fill();
	while(cin >> n && n)
		cout << solve(n) << enl; 
	return 0;
}
