#include <bits/stdc++.h>
#define 	enl 		"\n"

using namespace std;
typedef 	long long 			ll;

ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }


ll _pow( ll b, ll e)
{
    ll r = 1;
    ll pow = b;
    while( e )
    {
        if( e&1 ) r = ( r*pow );
        pow = ( pow*pow );
        e >>= 1;
    }
    return r;
}


ll solve(ll n){

	ll ans = 1;
	long i = 2, e;
	while(i*i <= n){
		e = 0;
		while(n % i == 0){ n /= i; e++;}
		if(e!=0) ans *= _pow(i,(e + e%2)/2);
		i++;
	}
	if(n != 1) ans *= n;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b,d;
	cin >> a >> b;
	d = gcd(a,b);
	cout << solve(d) << enl;
	return 0;
}
