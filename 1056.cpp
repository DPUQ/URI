#include <bits/stdc++.h>
#define pb push_back
#define s size()
#define MAX 201
#define cl clear()
#define f find
#define e end()
#define a assign
#define REP(i,a,b) for (int i = a; i < b; i++)

using namespace std;
typedef vector<long> vi;
typedef pair <int,int> ii;
typedef pair<long,ii> li;
typedef map<li,int> mli;
typedef vector<bool> vb;

bool graph[MAX][MAX];
mli id;
int n,m;

bool bpm( int u, bool seen[], int matchR[])
{

    for (int v = 0; v < m; v++)
    {
        if (graph[u][v] && !seen[v])
        {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}


int maxBPM()
{
    int matchR[m];
    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < n; u++)
    {

        bool seen[m];
        memset(seen, 0, sizeof(seen));

        if (bpm(u, seen, matchR))
            result++;
    }
    return result;
}

void limpiar(){
    REP(i,0,n)
        REP(j,0,m)
            graph[i][j]=0;
}

int main()
{

    int c=1,casos,ni,mi,ide;
    long aux;
    vi nn,nm;
    vb enm,enn;

    scanf("%d",&casos);

    while(c<=casos)
    {
        id.cl;
        nm.cl;
        nn.cl;

        scanf("%d",&ni);
        while(ni--)
        {
            scanf("%ld",&aux);
            nn.pb(aux);
        }

        scanf("%d",&mi);
        while(mi--)
        {
            scanf("%ld",&aux);
            nm.pb(aux);
        }

        ide = 0;
        enn.a(nn.s,0);
        enm.a(nm.s,0);

        REP(i,0,nn.s)
        {
            if(id.f(li(nn[i],ii(1,i)))==id.e && !enn[i])
            {
                id[li(nn[i],ii(1,i))] = ide;
                enn[i]=true;
                ide++;
            }

            REP(j,0,nm.s)
            {
                if(id.f(li(nm[j],ii(2,j)))==id.e && !enm[j])
                {
                    id[li(nm[j],ii(2,j))] = ide;
                    enm[j]=true;
                    ide++;
                }

                if(nn[i]!= 0 && nm[j]%nn[i]==0)
                {
                    graph[id[li(nn[i],ii(1,i))]][id[li(nm[j],ii(2,j))]]=1;
                }
                else if(nm[j]==nn[i] && nn[i]==0){
                    graph[id[li(nn[i],ii(1,i))]][id[li(nm[j],ii(2,j))]]=1;
                }
            }
        }

        n=m=ide;

        printf("Case %d: %d\n",c,maxBPM());
        limpiar();
        c++;
    }

    return 0;
}
