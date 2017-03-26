#include <bits/stdc++.h>
#include <tr1/unordered_map>
#define f find
#define e end()
#define en "\n"

using namespace std;
typedef string st;
typedef std::tr1::unordered_map<st,st> mss;


mss mapa;

int main(){

ios::sync_with_stdio(false);
//cin.tie(NULL);

mapa["brasil"] = "Feliz Natal!";
mapa["alemanha"] = "Frohliche Weihnachten!";
mapa["austria"] = "Frohe Weihnacht!";
mapa["coreia"] = "Chuk Sung Tan!";
mapa["espanha"] = "Feliz Navidad!";
mapa["grecia"] = "Kala Christougena!";
mapa["estados-unidos"] = "Merry Christmas!";
mapa["inglaterra"] = "Merry Christmas!";
mapa["australia"] = "Merry Christmas!";
mapa["portugal"] = "Feliz Natal!";
mapa["suecia"] = "God Jul!";
mapa["turquia"] = "Mutlu Noeller";
mapa["argentina"] = "Feliz Navidad!";
mapa["chile"] = "Feliz Navidad!";
mapa["mexico"] = "Feliz Navidad!";
mapa["antardida"] = "Merry Christmas!";
mapa["canada"] = "Merry Christmas!";
mapa["irlanda"] = "Nollaig Shona Dhuit!";
mapa["belgica"] = "Zalig Kerstfeest!";
mapa["italia"] = "Buon Natale!";
mapa["libia"] = "Buon Natale!";
mapa["siria"] = "Milad Mubarak!";
mapa["marrocos"] = "Milad Mubarak!";
mapa["japao"] = "Merii Kurisumasu!";


st query;

while(cin >> query){
    if(mapa.f(query) != mapa.e)
    cout <<  mapa[query];
    else cout << "--- NOT FOUND ---";

    cout << en;

}

return 0;
}
