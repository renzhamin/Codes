#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int k;cin>>k;
	vector<bool> isprime;
	isprime.assign(n+1, 1);
	vector<int>prime;
	for (int p = 2; p * p <= n; p++){
		if (isprime[p] == 1)	{
			for (int i = p * p; i <= n; i += p)
				isprime[i] = 0;
		 }
	}
	int ptn=0;
	for (int p = 2; p<= n; p++)
		if (isprime[p]){
			prime.push_back(p);
			ptn++;
		}
    int s;
    int c=0;
    int x;
	for (int i = 13; i <=n; i++){
	  if(isprime[i]){
	    s=0;
		for(int p=2;prime[p]<=(n/2);p++){
			s=prime[p]+prime[p+1]+1;
			if(s==i){
			 //cout<<i<<"="<<"1+"<<prime[p]<<"+"<<prime[p+1]<<endl;
				 c++;
				 break;
			}
			x=p;
		}
	   }
	   if(c>k) break;
	}
	cout<<(k<=c? "YES":"NO");
//cout<<endl<<"Total noldbatch number : "<<c<<endl<<"Total prime till n : "<<ptn<<endl<<"Last accessed index : "<<x<<endl<<"Last accessed number : "<<prime[x];
}
