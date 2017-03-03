#include <bits/stdc++.h>
using namespace std;

int is,ie,y,yy;
char c1,c2;
bool visited[8][8];
int chessboard[8][8];
queue<pair<int,int> > cola;
pair <int,int> aux;


void init(){

for(int i = 0; i<8; i++){
    for(int j = 0; j<8; j++){
        chessboard[i][j]=0;
        visited[i][j]=false;
    }
}
}

bool validar(int i,int j){

    if(i>=0 && i<=7 && j>=0 && j<=7){
        return !visited[i][j];
    }

    return false;
}

void floodfill(pair<int,int>p){

    if(visited[p.first][p.second]) return;

    cola.push(p);
    visited[p.first][p.second] = true;
    chessboard[p.first][p.second] = 0;
    int iaux;
    int jaux;

    do{

        aux=cola.front();
        iaux=aux.first;
        jaux=aux.second;
        visited[iaux][jaux]=true;
        cola.pop();

        if(validar(iaux-2,jaux+1))
        {
            cola.push(make_pair(iaux-2,jaux+1));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux-2][jaux+1]||chessboard[iaux-2][jaux+1]==0)
                chessboard[iaux-2][jaux+1]=chessboard[iaux][jaux]+1;
        }

        if(validar(iaux-2,jaux-1))
        {
            cola.push(make_pair(iaux-2,jaux-1));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux-2][jaux-1]||chessboard[iaux-2][jaux-1]==0)
                chessboard[iaux-2][jaux-1]=chessboard[iaux][jaux]+1;
        }

        if(validar(iaux-1,jaux+2))
        {
            cola.push(make_pair(iaux-1,jaux+2));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux-1][jaux+2] || chessboard[iaux-1][jaux+2] == 0)
                chessboard[iaux-1][jaux+2]=chessboard[iaux][jaux]+1;
        }

        if(validar(iaux+1,jaux+2))
        {
            cola.push(make_pair(iaux+1,jaux+2));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux+1][jaux+2] || chessboard[iaux+1][jaux+2]==0)
                chessboard[iaux+1][jaux+2]=chessboard[iaux][jaux]+1;
        }

        if(validar(iaux+2,jaux+1))
        {
            cola.push(make_pair(iaux+2,jaux+1));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux+2][jaux+1] || chessboard[iaux+2][jaux+1]==0)
                chessboard[iaux+2][jaux+1]=chessboard[iaux][jaux]+1;
        }

        if(validar(iaux+2,jaux-1))
        {
            cola.push(make_pair(iaux+2,jaux-1));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux+2][jaux-1] || chessboard[iaux+2][jaux-1] == 0)
                chessboard[iaux+2][jaux-1]=chessboard[iaux][jaux]+1;
        }

        if(validar(iaux-1,jaux-2))
        {
            cola.push(make_pair(iaux-1,jaux-2));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux-1][jaux-2] || chessboard[iaux-1][jaux-2] == 0)
                chessboard[iaux-1][jaux-2]=chessboard[iaux][jaux]+1;
        }
        if(validar(iaux+1,jaux-2))
        {
            cola.push(make_pair(iaux+1,jaux-2));
            if(chessboard[iaux][jaux]+1<=chessboard[iaux+1][jaux-2]|| chessboard[iaux+1][jaux-2]==0)
                chessboard[iaux+1][jaux-2]=chessboard[iaux][jaux]+1;
        }

    }
    while(!cola.empty());


}

int main(){

while(scanf("\n%c%d %c%d",&c1,&y,&c2,&yy)!=EOF){

    init();

    y=y-1;
    yy=yy-1;

    switch(c1){

case 'a':
    is = 0;
    break;

case 'b':
    is = 1;
    break;

case 'c':
    is = 2;
    break;

case 'd':
    is = 3;
    break;

case 'e':
    is = 4;
    break;

case 'f':
    is = 5;
    break;

case 'g':
    is = 6;
    break;

case 'h':
    is = 7;
    break;

default:
    break;

    }

switch(c2){

case 'a':
    ie = 0;
    break;

case 'b':
    ie = 1;
    break;

case 'c':
    ie = 2;
    break;

case 'd':
    ie = 3;
    break;

case 'e':
    ie = 4;
    break;

case 'f':
    ie = 5;
    break;

case 'g':
    ie = 6;
    break;

case 'h':
    ie = 7;
    break;

default:
    break;

    }



floodfill(make_pair(is,y));


printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,(y+1),c2,(yy+1),chessboard[ie][yy]);
}

return 0;

}
