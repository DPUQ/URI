#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
#define INF 10000000

const int MAX = 10001;

vector<ii>AdjList[MAX];

int V,A;
bool isBipartite;
vi color;

void limpiarLista()
{
    for(int i = 0; i<=V; i++)
    {
        AdjList[i].clear();
    }

}


void bipartiteCheck(int s)
{

    queue<int> q;
    q.push(s);
    color[s] = 0;
    while (!q.empty() && isBipartite)
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ii v = AdjList[u][j];
            if (color[v.first] == INF)
            {
                color[v.first] = 1 - color[u];
                q.push(v.first);
            }
            else if (color[v.first] == color[u])
            {
                isBipartite = false;
                break;
            }
        }
    }

}

int main()
{
    int aux;

    while(scanf("\n%d",&V)==1)
    {
        for(int i = 0; i<V; i++)
        {
            for(int j = 0; j<V; j++)
            {
                scanf("%d",&aux);
                if(aux==0)
                {
                    AdjList[i].push_back(make_pair(j,0));
                }
            }
        }

        color.assign(V, INF);
        isBipartite = true;

        for(int i = 0; i<V; i++){
            if(color[i]==INF)
                bipartiteCheck(i);
            if(!isBipartite)
                break;
        }

        if(isBipartite)
        {
            printf("Bazinga!\n");
        }
        else
            printf("Fail!\n");

        limpiarLista();
    }

    return 0;

}

