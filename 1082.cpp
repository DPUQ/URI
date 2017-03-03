#include <bits/stdc++.h>
#define UNVISITED -1
#define VISITED 1
#define MAX 27
using namespace std;

typedef pair<int, int> ii; // In this chapter, we will frequently use these
typedef vector<ii> vii; // three data type shortcuts. They may look cryptic
typedef vector<int> vi; // but they are useful in competitive programming
vi dfs_num; // global variable, initially all values are set to UNVISITED
vi cc;
vii AdjList[MAX];

void dfs(int u)   // DFS for normal usage: as graph traversal algorithm
{
    dfs_num[u] = VISITED; // important: we mark this vertex as visited
    cc.push_back(u);

    for (int j = 0; j < (int)AdjList[u].size(); j++)   // default DS: AdjList
    {

        ii v = AdjList[u][j]; // v is a (neighbor, weight) pair
        if (dfs_num[v.first] == UNVISITED)
            dfs(v.first);
    }

}

bool sortfunc (int i,int j) { return (i<j); }

void printcc(){

    sort(cc.begin(),cc.begin()+cc.size(),sortfunc);

    for(int i = 0; i<cc.size(); i++)
        printf("%c,",(char)cc[i]+97);

}

void limpiarLista(int v){

    for(int i = 0; i<v; i++){
        AdjList[i].clear();
    }
}

int main()
{

    int casos,v,a,s,t,caso=1,numcc;
    char c,b;

    scanf("%d",&casos);

    while(casos--)
    {
        scanf("%d",&v);
        scanf("%d",&a);

        while(a--)
        {
            scanf("\n%c %c",&b,&c);
            s = (int)(b) - 97;
            t = (int) (c) - 97;
            AdjList[s].push_back(ii(t,0));
            AdjList[t].push_back(ii(s,0));
        }

        dfs_num.assign(v, UNVISITED);
        numcc = 0;

        printf("Case #%d:\n",caso);

        for(int i = 0; i<v; i++)
        {
            if(dfs_num[i]==UNVISITED)
            {
                numcc++;
                dfs(i);
                printcc();
                cc.clear();
                printf("\n");
            }
        }

        printf("%d connected components\n",numcc);

        caso++;
        limpiarLista(v);
        printf("\n");
    }

    return 0;
}
