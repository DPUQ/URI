#include <bits/stdc++.h>

using namespace std;

char number[100001];
int i;

bool leap()
{
    for(i = 0; i<sizeof(number); i++)
    {
        if(number[i]=='\0')
            break;
    }

    int numberd4 = (int)(number[i-2]-48)*10 + (int)(number[i-1]-48);
    int numberd100 = (int)(number[i-3]-48)*100 + (int)(number[i-2]-48)*10 + (int)(number[i-1]-48);

    if(numberd4 % 4 == 0 && numberd100 % 100 != 0)
    {
        return true;
    }

    else if (numberd100 % 100 == 0)
    {
        numberd4 = (int)(number[i-4]-48)*10 + (int)(number[i-3]-48);
        if(numberd4%4 == 0)
            return true;
    }


    return false;
}

bool huluculu()
{

    int total = 0;
    int parse;

    for(int j = 0; j<i; j++)
    {
        parse = (int)(number[j] - 48);
        total += parse;
    }

    if(total%3 == 0 && (number[i-1]=='0' || number[i-1]=='5'))
        return true;

    return false;

}

bool bulukulu()
{

    int parse,pares = 0, impares = 0;

    for(int j = 0; j<i; j++)
    {
        parse = (int)(number[j] - 48);

        if(j%2==0)
            pares+=parse;
        else
            impares+=parse;
    }

    if(abs(pares-impares)%11 == 0 && (number[i-1]=='0' || number[i-1]=='5'))
        return true;

    return false;
}


int main()
{
    bool l,h,b,c=0;

    while(scanf("\n%s",&number)==1)
    {
        if(c!=0)
             printf("\n");

        l = leap();
        h = huluculu();
        b = bulukulu();

        if(l)
            printf("This is leap year.\n");

        if(h)
            printf("This is huluculu festival year.\n");

        if(b&&l)
            printf("This is bulukulu festival year.\n");

        if (!l && !h)
            printf("This is an ordinary year.\n");

        memset(number,'\0',sizeof(number));
        c++;

    }
    return 0;
}
