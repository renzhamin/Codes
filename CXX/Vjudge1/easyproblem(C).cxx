#include <iostream>
using namespace std;
int main(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int s=0;
	for(int i=0;i<n;i++){
		s+=arr[i];
	}
	if(s!=0){
		cout<<"HARD"<<endl;
	} else {
		cout<<"EASY"<<endl;
	}
}