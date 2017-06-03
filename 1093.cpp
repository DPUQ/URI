#include <bits/stdc++.h>
#define enl "\n"
#define ptdec(q,n) fixed << setprecision(q) << n


using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	float res,p,v1,v2,at,d;
	while(cin >> v1 >> v2 >> at >> d && (v1 + v2 + at + d)){
		float n1 = ceil(v1/d) ,n2 = ceil(v2 / d);
		if(at == 3){
			res = n1 / (n1 + n2);
		}
		else{
			p = at / 6;
			res = (1 - pow((1-p)/p,n1))/(1 - pow((1-p)/p,n1 + n2));
		}

		cout << ptdec(1,res*100) << enl;
	}
	return 0;
}
