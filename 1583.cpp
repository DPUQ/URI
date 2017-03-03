#include <bits/stdc++.h>
using namespace std;

char matriz[51][51];
vector<pair<int,int> > tes;
queue<pair<int,int> > cola;
pair<int,int> aux;


bool validar(int i,int j, int n, int m){

    if(i>=0 && i<=n && j>=0 && j<=m){

        if(matriz[i][j]=='A' && matriz[i][j]!='T')
            return true;

    }
    return false;
}

void floodfill(pair<int,int>p,int n, int m){

    if(matriz[p.first][p.second]!='A') return;

    cola.push(p);

    int iaux;
    int jaux;

    do{
        aux=cola.front();
        iaux=aux.first;
        jaux=aux.second;

        if(matriz[iaux][jaux]=='A' || matriz[iaux][jaux]=='T'){

            matriz[iaux][jaux]='T';
            cola.pop();

            if(validar(iaux,jaux+1,n,m)){
                cola.push(make_pair(iaux,jaux+1));
            }

            if(validar(iaux,jaux-1,n,m)){
                cola.push(make_pair(iaux,jaux-1));
            }

            if(validar(iaux-1,jaux,n,m)){
                cola.push(make_pair(iaux-1,jaux));
            }

            if(validar(iaux+1,jaux,n,m)){
                cola.push(make_pair(iaux+1,jaux));
            }
        }

    }while(!cola.empty());

}

int main(){

int n,m;
char c;

while(true){

    tes.clear();

    scanf("%d %d",&n,&m);

    if(n==0 && m==n)
        break;

    n=n-1;
    m=m-1;

    scanf("%c",&c);
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            scanf("%c",&c);
            matriz[i][j]=c;
            if(matriz[i][j]=='T'){
                tes.push_back(make_pair(i,j));
            }
        }
        scanf("%c",&c);
    }

    for(int i = 0; i<tes.size(); i++){

        aux= tes[i];
        matriz[aux.first][aux.second]='A';
        floodfill(aux,n,m);
    }

    for(int i = 0; i <= n; i++){
			for(int j = 0; j <= m; j++){
				printf("%c",matriz[i][j]);
			}
			printf("\n");
		}

		printf("\n");
}

return 0;

}
