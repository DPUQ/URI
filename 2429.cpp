#include <bits/stdc++.h>
#define MAX 100001
#define UNVISITED -1
#define VISITED 1

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vii AdjList[MAX];
int dfsNumberCounter,numSCC,V;


vi dfs_num, dfs_low, S, visited;

void tarjanSCC(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
            tarjanSCC(v.first);
        if (visited[v.first])
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    }
    if (dfs_low[u] == dfs_num[u])
    {
        numSCC++;

        while (1)
        {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;

            if (u == v) break;
        }

    }
}

int main()
{

    scanf("%d",&V);
    int A = V,s,t;

    while(A--){
        scanf("%d %d",&s,&t);
        AdjList[s].push_back(ii(t,0));
    }

    dfs_num.assign((V+1), UNVISITED);
    dfs_low.assign((V+1), 0);
    visited.assign((V+1), 0);
    dfsNumberCounter = numSCC = 0;
    for (int i = 1; i <= V; i++)
        if (dfs_num[i] == UNVISITED)
            tarjanSCC(i);

    printf("%c\n",numSCC==1?'S' : 'N');

    return 0;
}
