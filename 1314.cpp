#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
int V,A;
const int MAX = 100001;
vi dfs_num,dfs_low,dfs_parent;
vector<bool> articulation_vertex;
int dfsNumberCounter,dfsRoot,rootChildren;
vector<ii>AdjList[MAX];
int parent[MAX];
int ran[MAX];
const int UNVISITED = -1,VISITED = 1,EXPLORED = 2;

int find(int i){
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
    return parent[i];
}


void unionFind(int x, int y){
    int xroot = find(x);
    int yroot = find(y);

    if (ran[xroot] < ran[yroot]){
        parent[xroot] = yroot;
    }

    else if (ran[xroot] > ran[yroot]){
         parent[yroot] = xroot;
    }

    else{
        parent[yroot] = xroot;
        ran[xroot]++;
    }
}


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
            if (dfs_low[v.first] >= dfs_num[u])
                articulation_vertex[u] = true;
            if (dfs_low[v.first] > dfs_num[u])
            {
               unionFind(u,v.first);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        else if (v.first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}


void init()
{
    for(int i = 0; i<=V; i++)
    {
        parent[i]=i;
        ran[i]=0;
        AdjList[i].clear();
    }
}

int main()
{
    int u1,u2,Q;

    while(true)
    {

        scanf("%d %d %d",&V,&A,&Q);

        if(V==A && A==Q && Q==0)
            break;

        init();

        while(A--)
        {
            scanf("%d %d",&u1,&u2);
            AdjList[u1].push_back(make_pair(u2,0));
            AdjList[u2].push_back(make_pair(u1,0));
        }

        dfs_num.assign((V+1),UNVISITED);
        dfs_low.assign((V+1),0);
        dfs_parent.assign((V+1),0);
        articulation_vertex.assign((V+1),0);
        dfsNumberCounter = 0;

        for (int i = 1; i <= V; i++)
        {
            if (dfs_num[i] == UNVISITED)
            {
                dfsRoot = i;
                rootChildren = 0;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }

        while(Q--)
        {
            dfs_num.assign((V+1),UNVISITED);
            scanf("%d %d",&u1,&u2);
            if(find(u1)==find(u2))
            {
                printf("Y\n");
            }
            else
                printf("N\n");
        }

        printf("-\n");
        init();

    }

    return 0;
}
