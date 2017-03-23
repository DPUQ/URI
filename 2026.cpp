#include <bits/stdc++.h>
#define REP(i,a,n) for(int i = a; i<n; i++)
#define MAXP 102
#define MAXW 1002
#define pb push_back

using namespace std;
typedef vector<int> vi;

int dp[MAXP][MAXW];
vi pes(MAXP);
vi es(MAXP);
int peso,p;

int solve(int i,int w)
{
    if(i==p || w==0)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int res = -1;
    if(pes[i]>w)
        res = solve(i+1,w);
    else
        res = max(solve(i+1,w),es[i]+solve(i+1,w-pes[i]));
    return dp[i][w] = res;
}

void llenar(int p,int w){
    REP(i,0,p+1){
        REP(j,0,w+1){
            dp[i][j]=-1;
        }
    }
}

int main()
{
    int casos,ramas,e,w;
    scanf("%d",&casos);

    REP(i,0,casos)
    {
        scanf("%d %d",&p,&peso);
        llenar(p,peso);
        REP(j,0,p)
        {
            scanf("%d %d",&e,&w);
            pes[j]=w;
            es[j]=e;
        }

        printf("Galho %d:\nNumero total de enfeites: %d\n",(i+1),solve(0,peso));
    }

    return 0;
}
