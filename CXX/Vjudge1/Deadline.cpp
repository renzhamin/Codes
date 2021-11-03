#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--){
	double n,d;
	long long int x;
	cin>>n>>d;
    bool yes=false;
    if(d<=n)
        cout<<"YES"<<endl;
     else {
		for (int i = 1; i <n;i++){
			 x = i +ceil(d/(i+1));
			if(x<=n){
			  yes=true;
			  break;
			}
		}
	cout<<(yes?"YES":"NO")<<endl;
     }
	}
}