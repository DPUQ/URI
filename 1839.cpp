#include <bits/stdc++.h>
#define 	MAX 		51
#define 	mod 		1000000007
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	string 				st;
typedef 	long long 			ll;

st grid[MAX];
ll fact[MAX * MAX];

void fill(){
	fact[0] = fact[1] = 1;
	rep(i,2,MAX * MAX) fact[i] = (i*fact[i-1]) % mod;
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

ll solveQuerie(int is, int js, int ie, int je){
	int ws = 0, tc = 0;
	for(int i = is; i < ie; i++)
		for(int j = js; j < je; j++){
			if(grid[i][j] == '#') ws++;
			tc++;
		}
	ll ans = fact[tc];
	ans = ( ans * inv( (fact[ws] * fact[tc-ws]) % mod ) ) % mod;
	return --ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,is,ie,js,je;
	fill();
	cin >> n >> m;
	rep(i,0,n) cin >> grid[i];
	while(cin >> is >> js >> ie >> je)
		cout << solveQuerie(--is, --js, ie, je) << enl;
	return 0;
}
