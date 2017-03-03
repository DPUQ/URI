#include <bits/stdc++.h>
#define MAX 50
#define VISITED 1
#define UNVISITED -1
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector <int> vi;

vii AdjList[MAX];
vi dfs_num;
int pasos,inicio;

void dfs(int u)
{

    dfs_num[u]=VISITED;

    for(int i = 0; i<(int)AdjList[u].size(); i++)
    {
        ii aux = AdjList[u][i];
        int v = aux.first;
        if(dfs_num[v] == UNVISITED)
        {
            pasos++;
            dfs(v);
        }

    }
    if(u!=inicio)
        pasos++;

}

void limpiarLista(int v)
{

    for(int i = 0; i<v; i++)
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
        pasos = 0;
        scanf("%d",&inicio);
        scanf("%d %d",&v,&a);
        while(a--)
        {
            scanf("%d %d",&s,&t);
            AdjList[s].push_back(ii(t,0));
            AdjList[t].push_back(ii(s,0));
        }

        dfs_num.assign(v,UNVISITED);
        dfs(inicio);

        printf("%d\n",pasos);
        limpiarLista(v);
    }

    return 0;
}
