#include <bits/stdc++.h>

using namespace std;

long n,i,sq;

int main(){

    while(true){

        scanf("%d",&n);

        if(n==0)
            break;

        i=1,sq=1;
        while((sq)<=n){
            if(sqrt(sq)==(int)sqrt(sq)) i!=1? printf(" %d",sq) : printf("%d",sq);
            i++;
            sq = i*i;
        }


        printf("\n");
    }

return 0;
}
