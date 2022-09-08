#include <bits/stdc++.h>

using namespace std;

const int SIZE_N = 1e7;
const int SIZE_P = SIZE_N;

bool flag[SIZE_N+5];
int primes[SIZE_P+5];

int seive()
{
	int i,j,total=0,val;

	for(i=2;i<=SIZE_N;i++) flag[i]=1;
	
	val=sqrt(SIZE_N)+1;

	for(i=2;i<val;i++)
       	if(flag[i])
            		for(j=i;j*i<=SIZE_N;j++)
                		flag[i*j]=0;

	for(i=2;i<=SIZE_N;i++)
   	if(flag[i])
        		primes[total++]=i;

	return total;
}

int store_primes[100],freq_primes[100], store_divisor[10000], Total_Prime, ans;

void divisor(int N)
{
  int i,val,count;

  val=sqrt(N)+1;
  Total_Prime=0;
  for(i=0;primes[i]<val;i++)
  {
    if(N%primes[i]==0)
    {
      count=0;
      while(N%primes[i]==0)
      {
          N/=primes[i];
          count++;
      }
      store_primes[Total_Prime]=primes[i];
      freq_primes[Total_Prime]=count;
      Total_Prime++;
    val=sqrt(N)+1;     // sqrt again for fast compute.
    }
  }
  if(N>1)
  {
    store_primes[Total_Prime]=N;
      freq_primes[Total_Prime]=1;
      Total_Prime++;
  }
}
void Generate(int cur,int num,int x=0)
{
  int i,val;

  // printf("primes[%d]=%d cur=%d,num=%d\n\n",x,primes[x],cur,num);
  if(cur==Total_Prime)
  {
      store_divisor[ans++]=num;
  }
  else
  {
      val=1;
      for(i=0;i<=freq_primes[cur];i++)
      {
        Generate(cur+1,num*val,i);
        val=val*store_primes[cur];
      }
  }
}



int main()
{
  int total=seive();
  int n,i;

  while(scanf("%d",&n)==1)
  {
    divisor(n);
      ans=0;
      Generate(0,1);
      sort(&store_divisor[0],&store_divisor[ans]);

      printf("Total No of Divisors: %d\n",ans);
      for(i=0;i<ans;i++)
            printf("%d ",store_divisor[i]);
      printf("\n");
  }
}
