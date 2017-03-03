#include<bits/stdc++.h>
using namespace std;

int distancias[10001];
bool visited[10001];
queue<int>cola;

int sumar(int a){
    return a+1;
}

int invertir(int a){
    int num_inv = 0;
    int div_entera = a;
    int resto_div = 0;
    while (div_entera != 0) {
        resto_div = div_entera % 10;
        div_entera = div_entera / 10;
        num_inv = num_inv * 10 + resto_div;
}
    return num_inv;
}

void init(){

    memset(distancias,0,sizeof(distancias));
    memset(visited,0,sizeof(visited));

    while(!cola.empty())
        cola.pop();

}


int main(){

    int casos,origen,destino,aux,encolar;
    int resultado;
    scanf("%d",&casos);

    while(casos--){

        init();

        scanf("%d",&origen);
        scanf("%d",&destino);

        cola.push(origen);


        while(!cola.empty()){

            aux = cola.front();
            cola.pop();

            if(aux==destino){
                resultado = distancias[aux];
                break;
            }

            else{

                encolar = sumar(aux);

                if(encolar<10001 && !visited[encolar]){
                    distancias[encolar]=distancias[aux]+1;
                    visited[encolar]=true;
                    cola.push(encolar);
                }

                encolar = invertir(aux);

                if(encolar<10001 && !visited[encolar]){
                    distancias[encolar]=distancias[aux]+1;
                    visited[encolar]=true;
                    cola.push(encolar);
                }
            }

        }

        printf("%d\n",resultado);

    }

    return 0;

}
