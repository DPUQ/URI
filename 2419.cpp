#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

char mapa[MAX][MAX];
bool encola [MAX][MAX];

queue<pair<int,int> > cola;
int n,m;
char color = '.';
char RC = 'X';
char tierra = '#';
int contador;

int validar(int i,int j)
{
    if(i>=0 && i<n && j>=0 && j<m)
    {
        if(mapa[i][j]==color && !encola[i][j])
        {
            return 1;
        }
        return -1;
    }
    return 0;
}

bool esborde(int i, int j){
    return i==0 || i==(n-1) || j==0 || j==(m-1);
}

void floodfill(pair<int,int>p)
{
    cola.push(p);
    pair<int,int> aux;

    int iaux;
    int jaux;

    do
    {
        aux=cola.front();
        iaux=aux.first;
        jaux=aux.second;

        cola.pop();

        if(mapa[iaux][jaux]==color)
        {
            if(validar(iaux,jaux+1)==1)
            {
                cola.push(make_pair(iaux,jaux+1));
                encola[iaux][jaux+1]=true;
            }
            else if(validar(iaux,jaux+1) == -1)
            {
                if(mapa[iaux][jaux+1]==tierra && mapa[iaux][jaux]!=tierra)
                {
                    mapa[iaux][jaux+1]=RC;
                    contador++;
                }
            }

            if(validar(iaux,jaux-1)==1)
            {
                cola.push(make_pair(iaux,jaux-1));
                encola[iaux][jaux-1]=true;
            }
            else if(validar(iaux,jaux-1) == -1)
            {
                if(mapa[iaux][jaux-1]==tierra && mapa[iaux][jaux]!=tierra)
                {
                    mapa[iaux][jaux-1]=RC;
                    contador++;
                }
            }

            if(validar(iaux-1,jaux)==1)
            {
                cola.push(make_pair(iaux-1,jaux));
                encola[iaux-1][jaux]=true;
            }
            else if(validar(iaux-1,jaux) == -1)
            {
                if(mapa[iaux-1][jaux]==tierra && mapa[iaux][jaux]!=tierra)
                {
                    mapa[iaux-1][jaux]=RC;
                    contador++;
                }
            }

            if(validar(iaux+1,jaux)==1)
            {
                cola.push(make_pair(iaux+1,jaux));
                encola[iaux+1][jaux]=true;
            }
            else if(validar(iaux+1,jaux) == -1)
            {
                if(mapa[iaux+1][jaux]==tierra && mapa[iaux][jaux]!=tierra)
                {
                    mapa[iaux+1][jaux]=RC;
                    contador++;
                }
            }
        }

        mapa[iaux][jaux]=RC;
    }
    while(!cola.empty());

}

int main()
{
    char c;
    scanf("%d %d\n",&n,&m);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            scanf("%c",&mapa[i][j]);
        }
        scanf("%c",&c);
    }

    contador = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(mapa[i][j]==color)
            {
                floodfill(make_pair(i,j));
            }
            else if(esborde(i,j)&&mapa[i][j]==tierra){
                mapa[i][j]=RC;
                contador++;
            }
        }
    }

    printf("%d\n",contador);

    return 0;
}
