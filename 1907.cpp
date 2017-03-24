#include <bits/stdc++.h>
#define MAX 1030
#define REP(i,a,n) for(int i = a; i<n; i++)

using namespace std;
string mat[MAX];
bool vis[MAX][MAX];

int n,m;
int dj[] = { 0 , 0 , 1 , -1};
int di[] = { 1 , -1 , 0 , 0};

bool validar(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m)
        return mat[i][j] == '.' && !vis[i][j];
    return false;
}

void dfs(int i,int j)
{

    vis[i][j]=1;
    int ni,nj;

    for (int k = 0; k < 4; k++)
    {
        ni = i + di[k];
        nj = j + dj[k];
        if(validar(ni,nj))
            dfs(ni,nj);

    }
}

int main()
{
    scanf("%d %d",&n,&m);

    REP(i,0,n){
        cin >> mat[i];
    }

    int c = 0;

    REP(i,0,n){
        REP(j,0,m){
            if(validar(i,j)){
                dfs(i,j);
                c++;
            }
        }
    }

    printf("%d\n",c);

    return 0;
}
