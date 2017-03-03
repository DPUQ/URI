#include <bits/stdc++.h>
#define UNVISITED -1
#define VISITED 1
#define EXPLORED 2
#define MAX 100000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi dfs_num;
vi dfs_parent;
vii AdjList[MAX];
bool cycle;

void dfs(int u)
{
    dfs_num[u] = EXPLORED;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
        {
            dfs_parent[v.first] = u;
            dfs(v.first);
        }
        else if (dfs_num[v.first] == EXPLORED)
        {
            cycle=true;
        }
        else if (dfs_num[v.first] == VISITED){}
    }
    dfs_num[u] = VISITED;
}

void limpiarLista(int v)
{

    for(int i = 0; i<=v; i++)
    {
        AdjList[i].clear();
    }
}

int main()
{

    int casos,v,a,s,t;

    scanf("%d",&casos);

    while(casos--)
    {
        scanf("%d",&v);
        scanf("%d",&a);

        while(a--)
        {
            scanf("%d %d",&s,&t);
            AdjList[s].push_back(ii(t,0));
        }

        dfs_num.assign(++v, UNVISITED);
        dfs_parent.assign(++v, 0);
        cycle=false;

        for(int i = 1; i<=v; i++)
        {
            if(dfs_num[i]==UNVISITED)
            {
                dfs(i);
            }
        }

        if(cycle)
            printf("SIM\n");
        else
            printf("NAO\n");

        limpiarLista(v);
    }

    return 0;
}
