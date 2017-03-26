#include <bits/stdc++.h>
#define MAX 31
#define REP(i,n) for(int i = 0; i<n; i++)
#define cl clear()
#define f first
#define s second

using namespace std;
typedef pair<long long,long long> ii;
typedef vector<ii> vii;

int n;
long long dp[MAX][MAX];

vii orders(MAX);

long long solve(int i, int p){

    if(i == n || p == 0)return 0;
    if(dp[i][p]!=-1) return dp[i][p];

    long long res = 0;

    if(orders[i].s > p)
        res = solve(i+1,p);

    else
        res = max(solve(i+1,p),orders[i].f + solve(i+1,p-orders[i].s));

    return dp[i][p] = res;

}

int main()
{

    long long t,q;
    int p;

    while(true)
    {
        scanf("%d",&n);

        if(n==0) break;

        scanf("%d",&p);
        orders.cl;
        memset(dp,-1,sizeof dp);

        REP(i,n){
            scanf("%lld %lld",&t,&q);
            orders[i] = ii(t,q);
        }

        printf("%lld min.\n",solve(0,p));
    }

    return 0;
}
