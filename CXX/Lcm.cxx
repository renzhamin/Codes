#include <iostream>
using namespace std;
int highestint(int arr[],int n){
	int max=arr[0];
	for(int i=1;i<n;i++){
		if (arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

int main(){
	int n,j;
	cin>>n;
	int r[n],s;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int max=highestint(arr,n);
	for(j=1;;j++){
        s=0;
		for(int i=0;i<n;i++){
			r[i]=(max*j)%arr[i];
			s+=r[i];
		}
		if(s==0){
			break;
		}
	}
	cout<<j*max;
}