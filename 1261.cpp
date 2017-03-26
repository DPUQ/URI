#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define f find
#define e end()
#define en "\n"

using namespace std;
typedef unsigned long long ull;
typedef string st;
typedef std::tr1::unordered_map<st,ull> msl;

msl mapa;

int main()
{
    ios::sync_with_stdio(false);
    ull res,val;
    st key,wd;

    int n,m;

    cin >> n >> m;

    while(n--){
        cin >> key >> val;
        mapa[key] = val;
    }

    while(m--){
        res = 0;
        do{
            cin >> wd;
            if(mapa.f(wd)!=mapa.e)
                res += mapa[wd];
        }while(wd != ".");

        cout << res << en;
    }

    return 0;
}
