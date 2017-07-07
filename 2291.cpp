#include <bits/stdc++.h>
#define 	MAX 		1000001
#define 	enl 		"\n"

using namespace std;
typedef 	long long 			ll;

ll divisorSum[MAX+10];

void fill(){
	for (long i = 1; i <= MAX; i++) {
        for (long j = i; j <= MAX; j += i) {
            divisorSum[j] += ll(i);
        }
    }
    for(long i = 2; i<= MAX; i++)
    	divisorSum[i] += divisorSum[i-1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	fill();
	while(cin >> n && n)
		cout << divisorSum[n] << enl;
	return 0;
}
