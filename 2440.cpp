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


int main()
{

    int casos,v,a,s,t,numcc;
        scanf("%d",&v);
        scanf("%d",&a);

        while(a--)
        {
            scanf("%d %d",&s,&t);
            AdjList[s].push_back(ii(t,0));
            AdjList[t].push_back(ii(s,0));
        }

        dfs_num.assign((v+1), UNVISITED);
        numcc = 0;

        for(int i = 1; i<=v; i++)
        {
            if(dfs_num[i]==UNVISITED)
            {
                numcc++;
                dfs(i);
            }
        }

        printf("%d\n",numcc);

    return 0;
}
