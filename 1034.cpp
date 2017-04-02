#include <bits/stdc++.h>
#define MAX 26
#define MAXW 1000001
#define rep(i,n) for(int i = 0; i<n; i++)
#define prep(i,a,n) for(int i = a; i<=n; i++)

using namespace std;
typedef vector<int> vi;

vi coins(MAX);
int dp[MAXW];

int solve(int n, int m)
{
    dp[0] = 0;
    prep(i,1,m)
        dp[i] = INT_MAX;

    prep(i,1,m)
    {
        rep(j,n){
          if (coins[j] <= i)
          {
              int sub_res = dp[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                  dp[i] = sub_res + 1;
          }
        }
    }
    return dp[m];
}

int main()
{
    int t,n,m,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        rep(i,n){
            scanf("%d",&c);
            coins[i] = c;
        }

        printf("%d\n",solve(n,m));
    }

    return 0;
}
