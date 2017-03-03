#include <bits/stdc++.h>
#define RC -1
using namespace std;

int matriz[201][201];
vector<pair<int,int> > tes;
queue<pair<int,int> > cola;
pair<int,int> aux;
int color,contador,menor,n,m;

bool validar(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        if(matriz[i][j]==color)
            return true;
    }
    return false;
}

void floodfill(pair<int,int>p)
{
    if(matriz[p.first][p.second]!=color) return;

    cola.push(p);

    int iaux;
    int jaux;

    do
    {
        aux=cola.front();
        iaux=aux.first;
        jaux=aux.second;

        if(matriz[iaux][jaux]==color)
        {
            contador++;
            matriz[iaux][jaux]=RC;
            cola.pop();

            if(validar(iaux,jaux+1))
            {
                cola.push(make_pair(iaux,jaux+1));
            }

            if(validar(iaux,jaux-1))
            {
                cola.push(make_pair(iaux,jaux-1));
            }

            if(validar(iaux-1,jaux))
            {
                cola.push(make_pair(iaux-1,jaux));
            }

            if(validar(iaux+1,jaux))
            {
                cola.push(make_pair(iaux+1,jaux));
            }
        }
        else
            cola.pop();

    }
    while(!cola.empty());

}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
            scanf("%d",&matriz[i][j]);
    }


    menor = 40001;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++){

            if(matriz[i][j]!=RC){
                color = matriz[i][j];
                contador = 0;
                floodfill(make_pair(i,j));

                if(menor > contador)
                    menor = contador;
            }
        }
    }

    printf("%d\n",menor);

    return 0;

}
