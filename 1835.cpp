#include <bits/stdc++.h>
#define UNVISITED -1
#define VISITED 1
#define MAX 100000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi dfs_num;
vii AdjList[MAX];

void dfs(int u)
{
    dfs_num[u] = VISITED;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
            dfs(v.first);
    }
}

void limpiarLista(int v){

    for(int i = 0; i<=v; i++){
        AdjList[i].clear();
    }
}

int main()
{

    int casos,v,a,s,t,caso=1,numcc;

    scanf("%d",&casos);

    while(casos--)
    {
        scanf("%d",&v);
        scanf("%d",&a);

        while(a--)
        {
            scanf("%d %d",&s,&t);
            AdjList[s].push_back(ii(t,0));
            AdjList[t].push_back(ii(s,0));
        }

        dfs_num.assign(++v, UNVISITED);
        numcc = 0;

        for(int i = 1; i<=v; i++)
        {
            if(dfs_num[i]==UNVISITED)
            {
                numcc++;
                dfs(i);
            }
        }

        if(numcc == 1)
            printf("Caso #%d: a promessa foi cumprida\n",caso);
        else
            printf("Caso #%d: ainda falta(m) %d estrada(s)\n",caso,(numcc-1));

        caso++;
         limpiarLista(v);
    }

    return 0;
}
