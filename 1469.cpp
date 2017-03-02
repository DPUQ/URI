#include <bits/stdc++.h>
#define MAX 502
#define INF 102
#define UNVISITED 0
#define VISITED 1

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vii adj [MAX];

int menor,s;
int edades[MAX];

void dfs(int u){

    dfs_num[u] = VISITED;
    if(edades[u]<menor && u!=s) menor = edades[u];
    ii v;
    for(int j = 0; j<(int)adj[u].size();j++){
        v = adj[u][j];
        if(dfs_num[v.first]==UNVISITED)
            dfs(v.first);
    }

}

void reset(int v){

    for(int i = 0; i<=v; i++){
        adj[i].clear();
    }

}


int main(){

    int v,a,i,t,c,aux;
    char q;
    vii vaux;

    while(scanf("%d %d %d",&v,&a,&i)==3){
        reset(v);
        c=1;

        while(c<=v){
            scanf("%d",&edades[c]);
            c++;
        }


        while(a--){
            scanf("%d %d",&s,&t);
            adj[t].push_back(ii(s,0));
        }

        while(i--){
            scanf("\n%c",&q);
            if(q=='T'){
                scanf("%d %d",&s,&t);
                for(int j = 1; j<=v; j++){
                    for(int k = 0; k<(int)adj[j].size();k++){
                        if(adj[j][k].first == s){
                            adj[j][k].first = t;
                        }else if(adj[j][k].first == t){
                            adj[j][k].first = s;
                        }
                    }
                }
                vaux=adj[s];
                adj[s]=adj[t];
                adj[t]=vaux;
            }
            else if(q=='P'){
                scanf("%d",&s);
                dfs_num.assign(v+1, UNVISITED);
                menor = INF;
                dfs(s);
                if(menor!=INF)
                    printf("%d\n",menor);
                else
                    printf("*\n");
            }
        }

    }

return 0;
}
