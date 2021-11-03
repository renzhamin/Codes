#include <iostream>
using namespace std;

int gcd(int a, int b) { 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 

    if (a == b) 
        return a; 

    if (a > b) 
      return gcd(a-b, b); 

    return gcd(a, b-a); 
} 
int lcmof2(int a,int b){
	int s=(a*b)/(gcd(a,b));
	return s;
}

int main(){
	int n;cin>>n;
	int maxlcm=0;
	int tmp;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
		    tmp=lcmof2(arr[i],arr[j]);
			if(tmp>maxlcm){
				maxlcm=tmp;
			}
		}
	}
	cout<<maxlcm<<endl;
}