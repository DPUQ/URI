#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int origen, destino, peso;

    bool operator!=(const Edge& rhs) const{
        if(rhs.origen!=origen || rhs.destino!=destino || rhs.peso!=peso){
            return true;
        }
        return false;
    }
};

int v,a;
const int maxim=10000;
int parent[maxim];
int ran[maxim];
long long resultado;
Edge edges[maxim];


void init(){

    memset(ran,0,sizeof(int)*(v+1));
    for(int i=1; i<=v; i++){
        parent[i]=i;
    }
}

int cmp1(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->peso > b1->peso;
}

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


void kruskal(){

    Edge actual;
    int aux=0;
    int x,y;
    qsort(edges, a, sizeof(edges[0]), cmp1);

    for(int i=0; aux<(v-1); i++){
        actual=edges[i];
        x=find(actual.origen);
        y=find(actual.destino);

        if(x!=y){
            aux++;
            unionFind(x, y);
            resultado += actual.peso;
        }
    }

}


int main(){

int origen,destino,peso;

while( scanf("%d %d",&v,&a)==2){

    for(int i = 0; i<a; i++){
        scanf("%d",&origen);
        scanf("%d",&destino);
        scanf("%d",&peso);
        edges[i].origen=origen;
        edges[i].destino=destino;
        edges[i].peso=peso;
    }


    resultado=0;
    init();
    kruskal();

    printf("%lli\n",(resultado));


    }

return 0;

}

