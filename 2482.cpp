#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define f find
#define e end()
#define en "\n"

using namespace std;
typedef string st;
typedef std::tr1::unordered_map<st,st> mss;


mss mapa;

int main()
{

    int n,m;
    char c;

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);

    st lan,wor,name;

    scanf("%d\n",&n);

    while(n--)
    {

        std::getline(std::cin, lan);
        std::getline(std::cin, wor);
        mapa[lan] = wor;

    }

    scanf("\n%d\n",&m);

    while(m--)
    {
        std::getline(std::cin, name);
        std::getline(std::cin, lan);
        cout << name << en << mapa[lan] << en << en;
    }

    return 0;
}

