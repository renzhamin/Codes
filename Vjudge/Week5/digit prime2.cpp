#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<long long>dprime;
int main(){
	vector<bool> isprime;
	isprime.assign(1000001, 1);
	dprime.assign(1000001, 0);
	vector<int>prime;
	for (int p = 2; p * p <= 1000000; p++){
		if (isprime[p] == 1)	{
			for (int i = p * p; i <= 1000000; i += p)
				isprime[i] = 0;
		 }
	}
	int t;scanf("%d",&t);
	while(t--){
	int n,k;
	//scanf("%d %d",&n,&k);
	int so=0;
	int co=0;
	int r=1;
	int nu;
	for (int p = 2; p<= 1000000; p++){
		if (isprime[p]){
			co=0;
			nu=p;
			while(nu>0){
				r=nu%10;
				co+=r;
				nu/=10;
			}
			if(isprime[co]) so++;
		}
		dprime[p]=so;
	}

		//printf("%d\n",so);
		long long d=dprime[100]-dprime[10];
		cout<<d;
	}
}
