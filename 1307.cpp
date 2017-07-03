#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	pc(i,o) 	cout << "Pair #" << (i+1) << ": " << o << enl
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)

using namespace std;
typedef 	string 				st;
typedef 	long long 			ll;

ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }

ll bin2dec(st bin){
	ll dec = std::stoi(bin, nullptr, 2);
	return dec;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	st s1,s2;
	int t;
	ll a,b;
	cin >> t;
	rep(i,0,t){
		cin >> s1 >> s2;
		a = bin2dec(s1);
		b = bin2dec(s2);
		ll d = gcd(a,b);
		if(d != 1) pc(i,"All you need is love!");
		else pc(i,"Love is not all you need!");
	}
	return 0;
}
