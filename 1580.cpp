#include <bits/stdc++.h>

using namespace std;

unsigned long long fac [1001];
char w[1001];
int alph[27];
const long long mod = 1000000007;

unsigned long long fact(int n){

if(fac[n]!=-1){
    return fac[n];
}

else if(n == 2){
    return fac [2] = 2;
}

else {
    return fac[n] = (fact(n-1) * n) % mod;
}

}

long long mod_pow(long long base, long long e) {
  long long ans = 1;
  while (e) {
    if (e & 1)
      ans = (ans * base) % mod;
    base = (base * base) % mod;
    e >>= 1;
  }
  return ans;
}

int main(){

    memset(fac,-1,sizeof fac);
    fac[0]=1;
    fac[1]=1;
    fact(1000);

    int i;
    long long res,ac;

    while(scanf("\n%s",&w)==1){
        memset(alph,0,sizeof alph);
        i=0;
        res=0; ac=1;
        do{
            alph[(int)w[i]-65]++;
            i++;
        }while(w[i]!='\0');

        res = fac[i];

        for(int j = 0; j<27; j++){
            ac = (ac * fac[alph[j]])%mod;
        }

        res = (res * mod_pow(ac, mod - 2)) % mod;

        printf("%lli\n",res);
    }

return 0;
}
