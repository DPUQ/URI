#include <bits/stdc++.h>

using namespace std;

struct point{
    double x;
    double y;

};

struct Edge{
    int origen, destino;
    double peso;

    bool operator!=(const Edge& rhs) const{
        if(rhs.origen!=origen || rhs.destino!=destino || rhs.peso!=peso){
            return true;
        }
        return false;
    }
};
int v,a;
const int maxim = 124751;
int parent[maxim];
int ran[maxim];
double resultado;
Edge edges[maxim];
point puntos[501];


void init(){

    memset(ran,0,sizeof(int)*(v+1));
    for(int i=0; i<v; i++){
        parent[i]=i;
    }
}


int cmp(const void* a, const void* b)
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

    if (ran[xroot] < ran[yroot])
        parent[xroot] = yroot;
    else if (ran[xroot] > ran[yroot])
        parent[yroot] = xroot;

    else{
        parent[yroot] = xroot;
        ran[xroot]++;
    }
}

void kruskal(){

    Edge actual;
    int aux=0;
    int x,y;
    qsort(edges, a, sizeof(edges[0]), cmp);

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

float dist(point a,point b){
    float res = sqrt((pow((b.x-a.x),2)+ pow((b.y-a.y),2)));
    return res;
}

int main(){

    int casos,x,y,k;
    scanf("%d",&casos);

    while(casos--){
        scanf("%d",&v);
        a=v*(v-1)/2;

        for(int i=0; i<v; i++){
            scanf("%d",&x);
            scanf("%d",&y);
            puntos[i].x = x;
            puntos[i].y = y;
        }

        k = 0;

        for(int i = 0; i<v; i++){
            for(int j=i+1; j<v; j++){
                edges[k].origen = i;
                edges[k].destino = j;
                edges[k].peso = dist(puntos[i],puntos[j]);
                k++;
            }

        }


        init();
        resultado = 0;
        kruskal();
        printf("%.2f\n",(resultado/100));

    }


return 0;
}

