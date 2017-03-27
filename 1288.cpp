#include <bits/stdc++.h>
#define MAX 101
#define REP(i,n) for(int i = 0; i<n; i++)
#define f first
#define s second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<pl> vpl;

int n;
vpl bull(MAX);
ll dp[MAX][MAX];

ll solve(int i, int k){

    if(i==n || k==0) return 0;
    if(dp[i][k]!=-1) return dp[i][k];

    ll res = solve(i+1,k);

    if(k>=bull[i].s)
        res = max(res,solve(i+1,k-bull[i].s)+bull[i].f);

    return dp[i][k] = res;

}

int main()
{
    ll p,w,r;
    int casos,k;
    scanf("%d",&casos);
    while(casos--){
        scanf("%d",&n);
        REP(i,n){
            scanf("%lld %lld",&p,&w);
            bull[i] = pl(p,w);
        }
        scanf("%d %lld",&k,&r);
        memset(dp,-1,sizeof dp);
        ll res = solve(0,k);
        res>=r? printf("Missao completada com sucesso\n") : printf("Falha na missao\n");
    }

    return 0;
}
