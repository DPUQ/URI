#include <bits/stdc++.h>
#define Node pair<int,long long>
using namespace std;

int v,e;
const int MAX = 501;
vector<Node> ady[MAX];
int marked[MAX];
long long dist[MAX];
const int infinito = 1001;

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

int origen,destino,peso,queries,q1,q2;
bool encontrado;

while(true){


    scanf("%d %d",&v,&e);

    if(v==0 && v==e)
        break;

    limpiarLista();

    for(int i=0; i<e; i++){

        encontrado = false;

        scanf("%d %d %d",&origen,&destino,&peso);

        if(!ady[destino].empty()){

            for(int j = 0; j < ady[destino].size();j++){

                if(ady[destino][j].first == origen){
                    ady[origen].push_back(Node(destino,0));
                    ady[destino][j].second=0;
                    encontrado = true;
                    break;
                }
            }

            if(!encontrado){
                ady[origen].push_back(Node(destino,peso));
            }

        }

        else{
            ady[origen].push_back(Node(destino,peso));
        }


    }

    scanf("%d",&queries);

    for(int i = 0; i<queries ; i++){

        init();
        scanf("%d %d",&q1,&q2);
        dijkstra(q1);

        if(dist[q2]!=infinito){
            printf("%lli\n",dist[q2]);
        }

        else
            printf("Nao e possivel entregar a carta\n");
    }

    printf("\n");

    }

return 0;

}
