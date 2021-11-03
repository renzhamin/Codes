#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
#define max 1000002

using namespace std;
void GenPrime();
void DigitPrime();
long int prime[max];
long int dprime[max];

int main()
{
    GenPrime();
    DigitPrime();
    long int t,t1,t2,i,sum,n,j,total;
    //freopen("in.txt","r",stdin);
    while(scanf("%ld",&t)==1)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%ld%ld",&t1,&t2);
            total=dprime[t2]-dprime[t1-1];
            printf("%ld\n",total);
        }
    }
    return 0;
}

void GenPrime()
{
    long int i,j,m;
    m=(long int)sqrt(max);
    memset(prime, 1, sizeof(prime));
    prime[0]=prime[1]=0;
    for(i=2;i<=m;i++)
    {
        if(prime[i])
        {
            for(j=i+i;j<max;j+=i)
                prime[j]=0;
        }

    }

}
void DigitPrime()
{
    long int n,i,nodprime,sum;
    nodprime=0;
    for(i=2;i<max;i++)
    {
        if(prime[i])
        {
            sum=0;
            n=i;
            while(n>0)
            {
                sum+=n%10;
                n/=10;
            }
            sum+=n;
            if(prime[sum])
                nodprime+=1;
        }
        dprime[i]=nodprime;
    }
}
