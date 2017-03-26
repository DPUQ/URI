#include <bits/stdc++.h>
#define e end()
#define b begin()
#define f find
#define cl clear()
#define s size()
#define en "\n"
#define pdec(n) fixed << setprecision(n)

using namespace std;
typedef string st;
typedef long long ll;
typedef map<st,ll> msl;


int main()
{
    ios_base::sync_with_stdio(false);
    st cur;
    msl forest;
    msl::iterator it;
    int casos,cont=0;
    long total;

    cin >> casos; cin.ignore();

    while(casos--)
    {

        forest.cl;
        total = 0;

        if (cont != 0)
        {
            cout << en;
        }
        else
        {
            getline(cin,cur);
        }

        while(getline(cin,cur) && cur[0]!='\0')
        {
            forest[cur]++;
            total++;
        }

       for (it = forest.b; it != forest.e; it++)
            cout << it->first << " " << pdec(4) << (it->second*100.0)/total << endl;

        cont++;
    }


    return 0;
}
