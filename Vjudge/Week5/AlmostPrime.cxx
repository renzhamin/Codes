#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<bool> isprime;
	isprime.assign(n, 1);
	vector<int>prime;
	for (int p = 2; p * p <= n; p++){
		if (isprime[p] == 1)	{
			for (int i = p * p; i <= n; i += p)
				isprime[i] = 0;
		 }
	}
	for (int p = 2; p<= n; p++)
		if (isprime[p]){
			prime.push_back(p);
		}
    int s;
    int c=0;
	for (int i = 6; i <=n; i++){
		s=0;
		for(int p=0;prime[p]<=(n/2);p++){
			if(i%prime[p]==0) s++;
		}
		if(s==2) c++;
	}
	
	cout<<c;
}
