#include <bits/stdc++.h>
#define MAX 101
#define MAXW 50
#define f first
#define s second
#define REP(i,n) for(int i = 0; i<n ; i++)

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct state{
    long valor;
    int paquetes;
    int peso;

    state(long long v,int p,int w){
        valor = v;
        paquetes = p;
        peso = w;
    }

    state(){
        valor = 0;
        paquetes = 0;
        peso = 0;
    }
};

int n,wei,pac;
state dp[MAX][MAX];
vii packs(MAX);

state solve(int i, int w)
{
    if(i==n || w==0) return state(0,0,0);
    if(dp[i][w].valor!=-1) return dp[i][w];

    state res = solve(i+1,w),rest = state(0,0,0);

    if(packs[i].s<=w){
        rest = solve(i+1,w-packs[i].s);
        rest.valor = rest.valor + packs[i].f;
        rest.paquetes++;
        rest.peso += packs[i].s;
    }

    if(rest.valor > res.valor) res = rest;

    return dp[i][w] = res;

}

void fillDP(int n){
    REP(i,n)
        REP(j,MAXW+1)
            dp[i][j].valor=-1;
}


int main()
{

    int casos;
    long q,w;

    scanf("%d",&casos);

    while(casos--)
    {
        scanf("%d",&n);
        REP(i,n)
        {
            scanf("%ld %ld",&q,&w);
            packs[i] = ii(q,w);
        }
        fillDP(n);
        state res = solve(0,MAXW);
        pac=0; wei=0;
        printf("%ld brinquedos\nPeso: %d kg\nsobra(m) %d pacote(s)\n\n",res.valor,res.peso,n-res.paquetes);

    }

    return 0;
}
