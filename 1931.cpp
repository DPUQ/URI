#include <bits/stdc++.h>
#define Node pair<int,long long>
using namespace std;

int v,e;
const int MAX = 100001;
vector<Node> graph[MAX];
vector<Node> ady[MAX];
int marked[MAX];
long long dist[MAX];

const long long infinito = 500000001;

class cmp
{
public:
    bool operator()(Node n1,Node n2)
    {
        if(n1.second>n2.second)
            return true;
        else
            return false;
    }
};


void init()
{

    for(int j = 0; j <= v; j++)
    {
        graph[j].clear();
        ady[j].clear();
        dist[j] = infinito;
    }
}


void transformar()
{

    Node aux,newadj;

    for(int i = 0; i<=v; i++)
    {

            for(int j = 0; j<graph[i].size(); j++)
            {
                aux = graph[i][j];
                for(int k = 0; k<graph[aux.first].size(); k++)
                {
                    newadj = graph[aux.first][k];

                    if(newadj.first != i)
                    {
                        ady[i].push_back(Node(newadj.first,aux.second + newadj.second));
                        ady[newadj.first].push_back(Node(i,aux.second + newadj.second));

                    }

                }
            }

    }
}


void dijkstra(int s)
{
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));
    dist[s] = 0;
    int actual, j, adjacent;
    long long weight;

    while( !pq.empty() )
    {

        actual = pq.top().first;
        pq.pop();
        if( marked[actual] == 0 )
        {
            marked[actual] = 1;
            for( j = 0; j < ady[actual].size(); j++ )
            {
                adjacent = ady[actual][j].first;
                weight = ady[actual][j].second;
                if( marked[adjacent] == 0 )
                {
                    if( dist[adjacent] > dist[actual] + weight )
                    {
                        dist[adjacent] = dist[actual] + weight;
                        pq.push(Node( adjacent, dist[adjacent] ));
                    }
                }
            }
        }
    }
}

int main()
{

    int origen,destino,peso;

    while(scanf("\n%d %d",&v,&e)==2)
    {
        init();
        while(e--)
        {
            scanf("%d %d %d",&origen,&destino,&peso);
            graph[origen].push_back(Node(destino,peso));
            graph[destino].push_back(Node(origen,peso));
        }

        memset(marked,0,sizeof (int)*(v+1));

        transformar();
        dijkstra(1);

        if(dist[v]!=infinito)
            printf("%lli\n",dist[v]);
        else
            printf("%d\n",-1);

    }

    return 0;
}

