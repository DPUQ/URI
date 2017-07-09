#include <bits/stdc++.h>
#define 	MAX 		1000001
#define 	enl 		"\n"

using namespace std;

int phi[MAX + 3];
vector<int> primes;

void phiSieve(){
	for(int i = 0; i<MAX; i++) phi[i] = i;
	for(int i = 2; i<MAX; i++)
		if(phi[i] == i){
			for(int j = 2*i; j <= MAX - 1; j+=i)
				phi[j] = (phi[j] / i) * (i - 1);
            phi[i]--;
            primes.push_back(i);
		}
}

long eulerPhi(long n){
	int index = 0;
	long factor = (long) primes[index], ans = n;
	while(factor*factor <= n && index < primes.size() - 1){
		if (n % factor == 0) ans -= ans / factor;
		while(n % factor == 0) n /= factor;
		factor = primes[++index];
	}

	if(n != 1) ans -= ans / n;

	return ans;
}

long solve(long n){
    long cop;
    if(n<MAX) cop = phi[n];
    else cop = eulerPhi(n);
    return (cop / 2);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	phiSieve();
	long n; 
	while(cin >> n)
		cout << solve(n) << enl;
	return 0;
}
