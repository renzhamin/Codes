#include <iostream>
using namespace std;
int main(){
  int t;cin>>t;
  while(t--){
	int arr[]={1,2,5,10,50,100};
	int n,rem,c=0;cin>>n;
	while(n!=0){
		for(int i=0;i<6;i++){
			if(n>=arr[i])
			  rem=arr[i];
		}
		n=n-rem;
		c++;
	}
	cout << c << endl;
  }
}
