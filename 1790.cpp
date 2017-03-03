#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int V,A,bridges;
const int MAX = 201;
int dfs_num[MAX],dfs_low[MAX],dfs_parent[MAX];
int dfsNumberCounter,dfsRoot,rootChildren;
vector<ii>AdjList[MAX];
const int UNVISITED = -1,VISITED = 1,EXPLORED = 2;


void articulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
        {
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v.first);

            if (dfs_low[v.first] > dfs_num[u])
                bridges++;

            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        else if (v.first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}

void init()
{
    dfsNumberCounter = 0;
    bridges = 0;
    memset(dfs_num,UNVISITED,sizeof(int)*(V+1));
    memset(dfs_low,0,sizeof(int)*(V+1));
    memset(dfs_parent,0,sizeof(int)*(V+1));
    memset(dfs_num,UNVISITED,sizeof(int)*(V+1));

    for(int i = 0; i<=V; i++)
    {
        AdjList[i].clear();
    }
}

int main()
{
    int u1,u2;

    while(scanf("\n%d %d",&V,&A)==2)
    {

        init();

        while(A--)
        {
            scanf("%d %d",&u1,&u2);
            AdjList[u1].push_back(make_pair(u2,0));
            AdjList[u2].push_back(make_pair(u1,0));
        }

        for (int i = 0; i <=V; i++)
        {

            if (dfs_num[i] == UNVISITED)
            {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
            }
        }

        printf("%d\n",bridges);

    }

    return 0;
}

