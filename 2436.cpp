#include <bits/stdc++.h>

using namespace std;

int l,c,ri,rj;
int mat[1001][1001];

bool validar(int i, int j){
    if(i>0 && i<=l && j>0 && j<=c)
        return ( mat[i][j]==1);
    return false;
}

int main(){

scanf("%d %d",&l,&c);
scanf("%d %d",&ri,&rj);

for(int i = 1; i<=l; i++){
    for(int j = 1; j<=c; j++){
        mat[0][j]=0;
        scanf("%d",&mat[i][j]);
    }
    mat[i][0] = 0;
}

queue<pair<int,int> > cola;
cola.push(make_pair(ri,rj));
pair<int,int> aux;

while(!cola.empty()){
    aux = cola.front();
    cola.pop();
    ri=aux.first;
    rj=aux.second;
    mat[ri][rj]=2;

    if(validar(aux.first+1,aux.second)){
        cola.push(make_pair(aux.first+1,aux.second));
    }

    if(validar(aux.first-1,aux.second)){
        cola.push(make_pair(aux.first-1,aux.second));
    }

    if(validar(aux.first,aux.second+1)){
        cola.push(make_pair(aux.first,aux.second+1));
    }

    if(validar(aux.first,aux.second-1)){
        cola.push(make_pair(aux.first,aux.second-1));
    }

}

printf("%d %d\n",ri,rj);

return 0;
}
