#include <bits/stdc++.h>
#define pb push_back
#define s size()
#define cl clear()
#define all(i) (i.begin(),i.end())
#define REP(i,a,n) for(int i = a; i<n; i++)

using namespace std;
typedef vector<long> vl;

vl can;

int binarySearch( int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (can[mid] == x)  return min(mid,binarySearch(l, mid-1, x)!=-1?binarySearch(l, mid-1, x):mid);
        if (can[mid] > x) return binarySearch(l, mid-1, x);
        return binarySearch(mid+1, r, x);
   }

   return -1;
}
int main()
{

    int n,q,top,c=1,res;
    long au,q1;

    while(true)
    {
        scanf("%d %d",&n,&q);

        if(n==0 && n==q) break;

        top = n;
        can.cl;

        while(n--)
        {
            scanf("%ld",&au);
            can.pb(au);
        }

        sort all(can);

        printf("CASE# %d:\n",c);

        while(q--){
            scanf("%ld",&q1);
            res = binarySearch(0,top,q1);

            if(res!=-1){
                printf("%ld found at %d\n",q1,res+1);
            }
            else{
                printf("%ld not found\n",q1);
            }
        }

        c++;
    }


    return 0;
}
