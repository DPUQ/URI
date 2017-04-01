#include <bits/stdc++.h>
#define MAX 1001
#define INF 300000001
#define REP(i,n) for(int i = 0; i<n; i++)
#define s size()
#define cl clear()
#define et empty()
#define f first
#define d second
#define VISITED 1
#define UNVISITED -1
#define pb push_back

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef deque<iii> dii;
typedef vector<ii> vii;
typedef vector<vii> vvi;

class cmp
{
public:
    bool operator()(iii n1,iii n2)
    {
        if(n1.second>n2.second)
            return true;
        else
            return false;
    }
};

long long dist[MAX];

vvi adj(MAX);
int k;


void dijkstra(int so)
{

    priority_queue< iii, dii, cmp > pq;
    pq.push(iii(ii(so, 0),1));
    int actual, j, adjacent,cost;
    long long weight,wei;
    while( !pq.et )
    {
        actual = pq.top().f.f;
        cost = pq.top().d;
        weight = pq.top().f.d;
        pq.pop();

        if(weight < dist[actual])
        {
            dist[actual] = weight;
            for( j = 0; j < adj[actual].s; j++ )
            {
                adjacent = adj[actual][j].f;
                wei = adj[actual][j].d + weight;

                if(cost < k)
                    pq.push(iii(ii(adjacent,wei),cost+1));
            }

        }
    }
}

void clearList(int n)
{
    REP(i,n)
    {
        adj[i].cl;
        dist[i] = INF;
    }
}

int main()
{

    int casos,n,m,p,e,w;

    scanf("%d",&casos);

    while(casos--)
    {
        scanf("%d %d %d",&n,&m,&k);
        clearList(n);
        while(m--)
        {
            scanf("%d %d %d",&p,&e,&w);
            adj[p].pb(ii(e,w));
        }
        dijkstra(0);
        if(dist[n-1]!=INF)
            printf("%lld\n",dist[n-1]);
        else
            printf("-1\n");
    }

    return 0;
}
