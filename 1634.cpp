#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	sz 			size()

using namespace std;
typedef 	string 				st;
typedef 	long long 			ll;
typedef 	vector<ll> 		vi;

template<class T> st to_str(T t){stringstream ss; ss<<t; return ss.str();}

struct fraction
{
	ll num, den;
	fraction(ll n, ll d){
		num = n;
		den = d;
	}

	ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }

	st simplify(){
		ll d = gcd(num,den);
		num /= d;
		den /= d;
		return to_str(num) + " / " + to_str(den);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	ll ac;
	while(cin >> n >> m && (n + m)){
		vi tickets(n);
		ac = 0;
		rep(i,0,n){
			rep(j,0,m) cin >> k;
			tickets[i] = k;
			ac += k;
		}
		rep(i,0,n){
			fraction f(tickets[i],ac);
			cout << f.simplify() << enl;
		}
	}
	return 0;
}
