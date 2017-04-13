#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a; i<n; i++)
#define MAX 50002
#define pb push_back

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;
typedef vector<bool> vb;

graph adj(MAX);
graph dp;
graph marks(MAX/2);
vi dfs_num(MAX),tin(MAX),tout(MAX);
int T,bound;

void dfs(int u, int par) {
  tin[u] = T++;
  dp[u][0] = par;
  int v;

  rep(i,1,bound+1)
    dp[u][i] = dp[dp[u][i-1]][i-1];

  rep(i,0,adj[u].size()) {
    v = adj[u][i];

    if (v!= par) {
      dfs_num[v] = dfs_num[u] + 1;
      dfs(v,u);
    }

  }
  tout[u] = T++;
}

bool anc(int x, int y){
    return ((tin[x]<=tin[y]) && (tout[y]<=tout[x]));
}

int lca(int x, int y){
    int s = x;

    if(anc(x, y))
        return x;

    if(anc(y,x))
        return y;

    for(int j=bound;j>=0;--j)
        if(!anc(dp[x][j], y))
            x=dp[x][j];

    return dp[x][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s,t,a;
    long maxDist = 0;
    cin >> n;

    rep(i,0,n){
        cin >> s;
        s--;
        marks[s].pb(i);
    }

    rep(i,0,n-1){
        cin >> s >> t;
        s--; t--;
        adj[s].pb(t);
        adj[t].pb(s);
    }

    T = 0, bound = 1;
    while ((1<<bound)<=n) bound++;

    dp.assign(n+1,vector<int>(bound+1));
    dfs(0,0);

    rep(i,0,n/2){
        s = marks[i][0],t = marks[i][1];
        a = lca(s,t);
        maxDist += dfs_num[s] + dfs_num[t] - 2*dfs_num[a];
    }

    cout << maxDist << "\n";

    return 0;
}
