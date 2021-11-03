	#include <iostream>
	#include <vector>
	#include <cmath>
	using namespace std;
	int main(){
		ios_base::sync_with_stdio(false);cin.tie(NULL);
		vector<bool>isprime(1000001,1);
		isprime[1]=0;
		for(int i=2;i*i<1000001;i++){
		  if(isprime[i])	
			for(int j=2*i;j<=1000000;j+=i)
				isprime[j]=0;
		}
		int n;cin>>n;
		long long num;		
		long long x;
		while(n--){
			cin>>num;
			x=sqrt(num);
			if(x*x==num && isprime[sqrt(num)])
				cout<<"YES"; 
			else 
				cout<<"NO";
			
			cout<<endl;
		}
	}