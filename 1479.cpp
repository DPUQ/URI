#include <bits/stdc++.h>
#define Node pair<int,long long>
using namespace std;

int v,e;
const int MAX = 1001;
vector<Node> ady[MAX];
int marked[MAX];
long long dist[MAX];
const int infinito = 100001;

class cmp{
public:
  bool operator()(Node n1,Node n2){
    if(n1.second>n2.second)
      return true;
    else
      return false;
  }
};


void init(){

  memset(marked,0,sizeof(marked));
  for(int j = 0; j <= v; j++){
    dist[j] = infinito;
  }
}

void limpiarLista(){

    for(int j = 0; j<=v; j++){
    ady[j].clear();
    }
}

void dijkstra(int s){
    priority_queue< Node , vector<Node> , cmp > pq;
    pq.push(Node(s, 0));
    dist[s] = 0;
    int actual, j, adjacent;
    long long weight;

    while( !pq.empty() ){

      actual = pq.top().first;
      pq.pop();

      if( marked[actual] == 0 ){
        marked[actual] = 1;
        for( j = 0; j < ady[actual].size(); j++ ){
          adjacent = ady[actual][j].first;
          weight = ady[actual][j].second;
          if( marked[adjacent] == 0 ){
            if( dist[adjacent] > dist[actual] + weight ){
              dist[adjacent] = dist[actual] + weight;
              pq.push(Node( adjacent, dist[adjacent] ));
            }
          }
        }
      }
    }

}


int main(){

int origen,destino,peso,queries,q1,q2,q3;
char consulta;

while(true){


    scanf("%d %d",&v,&e);

    if(v==0 && v==e)
        break;

    limpiarLista();

    for(int i=0; i<e; i++){

        scanf("%d %d %d",&origen,&destino,&peso);
        ady[origen].push_back(Node(destino,peso));

    }

    scanf("%d",&queries);

    for(int i = 0; i<queries ; i++){

        scanf("\n%c",&consulta);
        if(consulta == 'R'){
            scanf("%d %d",&q1,&q2);

            for(int i = 0; i<ady[q1].size(); i++){
                if(ady[q1][i].first == q2){
                    ady[q1].erase(ady[q1].begin()+i);
                }
            }
        }
        else if(consulta == 'I'){
            scanf("%d %d %d",&q1,&q2,&q3);
            ady[q1].push_back(Node(q2,q3));
        }

        else if(consulta == 'P'){
            scanf("%d",&q1);
            init();
            dijkstra(1);

            if(dist[q1]!= infinito){
                printf("%lli\n",dist[q1]);
            }
            else{
                printf("-1\n");
            }
        }


    }

    printf("\n");

    }

return 0;

}
