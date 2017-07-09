#include <bits/stdc++.h>
#define 	MAX 		10000001
#define 	mod 		1000000007
#define 	enl 		"\n"

using namespace std;
typedef 	long long 			ll;
typedef     vector<int>         vi;

vi numDivs(MAX+10,1);
long c = 0;

int findQ(int n, int f){
    int q = 0;
    while(n % f == 0){
        n /= f;
        q++;
    }

    return ++q;
}

void fill(long a,long b,long n){
	for (long i = 2; i <= b; i++)
        if(numDivs[i] == 1)
            for (long j = i; j <= b; j += i) 
                numDivs[j] *= findQ(j,i);

    for(long i = a; i <= b; i++)
    	if( (long)numDivs[i] == n) c++;
}

ll mod_pow( long b, long e)
{
    ll r = 1LL;
    ll pow = (b*1LL) % mod;
    while( e )
    {
        if( e&1 ) r = ( r % mod * pow % mod )%mod;
        pow = ( pow % mod * pow % mod )%mod;
        e >>= 1;
    }

    return r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long a,b,n;
	cin >> a >> b >> n;
	fill(a,b,n);
	cout << mod_pow(c,(long)((b - a + 1L) - c)) << enl;
	return 0;
}
