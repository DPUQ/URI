#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i<n; i++)

using namespace std;
typedef vector<int> vi;

class DisjointSet
{

private :
    vi parent,ran,sizeSet;
    int sets;


public :
    DisjointSet(int n,vi points)
    {
        sets = n;
        ran.assign(n,0);
        sizeSet = points;
        parent.resize(n);
        rep(i,n) parent[i] = i;
    }

    int findSet(int i)
    {
        return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {

        if(!isSameSet(i,j))
        {
            int x = findSet(i), y = findSet(j);

            if(ran[x]>ran[y])
            {
                parent[y] = x , sizeSet[x]+=sizeSet[y];
            }

            else
            {
                parent[x] = y , sizeSet[y]+=sizeSet[x];
                if(ran[x] == ran[y]) ran[y]++;
            }

            sets--;
        }

    }

    int numSets()
    {
        return sets;
    }
    int sizeOfSet(int i)
    {
        return sizeSet[findSet(i)];
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,a,b,q,cont;

    while (true)
    {
        cin >> n >> m;

        if(n == m && m == 0) break;

        vi points(n);
        cont = 0;

        rep(i,n) cin >> points[i];

        DisjointSet ds(n,points);

        while(m--)
        {
            cin >> q >> a >> b;

            a--; b--;

            if(q==1) ds.unionSet(a,b);

            else if(q==2){
                if(ds.findSet(0) == ds.findSet(a)){
                    if(ds.sizeOfSet(0) > ds.sizeOfSet(b))
                        cont++;
                }else if(ds.findSet(0) == ds.findSet(b)){
                    if(ds.sizeOfSet(0) > ds.sizeOfSet(a))
                        cont++;
                }
            }
        }

        cout << cont << "\n";
    }

    return 0;
}
