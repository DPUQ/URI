#include <bits/stdc++.h>
#define 	enl 		"\n"
#define 	rep(i,a,n) 	for(int i = a; i<n; i++)
#define 	ft 			first
#define 	sd 			second
#define 	sz 			size()
#define 	bg 			begin()
#define 	ed 			end()
#define 	in 			insert


using namespace std;
typedef 	long long 			ll;
typedef 	pair<int,int> 		ii;
typedef 	vector<int> 		vi;

ll gcd(ll a, ll b){	return b == 0? a : gcd(b,a%b); }
ll lcm(ll a, ll b){ return a * (b / gcd(a,b)); }

class DisjointSet
{

private :
	/** Parent, rank and set size auxiliary arrays for the structure*/
    vi parent,ran,sizeSet;

public :
    DisjointSet(int n){
        ran.assign(n,0);
        sizeSet.assign(n,1);
        parent.resize(n);
        rep(i,0,n) parent[i] = i;
    }

    /** Find set of a given element */
    int findSet(int i) { return (parent[i] == i) ? i : (parent[i] = findSet(parent[i])); }

    /** Return if two elements are in the same set */
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    /** Make the union of two sets */
    void unionSet(int i, int j){

        if(!isSameSet(i,j)){
            int x = findSet(i), y = findSet(j);

            if(ran[x]>ran[y]) { parent[y] = x , sizeSet[x]+=sizeSet[y]; }

            else{
                parent[x] = y , sizeSet[y]+=sizeSet[x];
                if(ran[x] == ran[y]) ran[y]++;
            }

        }

    }

    /** Return the cardinality of the set who has a given element */
    int sizeOfSet(int i){ return sizeSet[findSet(i)]; }

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi digs(n);
	DisjointSet ds(n);
	rep(i,0,n){
		cin >> digs[i]; digs[i]--;
		ds.unionSet(i,digs[i]);
	}

	set<ii> pairs;

	rep(i,0,n) pairs.in(ii(ds.findSet(i),ds.sizeOfSet(i)));

	set<ii>::iterator it = pairs.bg;

	ll ans = (*it).sd;

	for(;it!=pairs.ed; it++)
		ans = lcm(ans,(*it).sd);

	cout << ans << enl;
	return 0;
}
