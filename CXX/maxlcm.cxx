#include <iostream>
using namespace std;

int lcmof2(int a,int b){
	int max,min;
	if(a>b){
	  max=a;min=b;
	}
	else{
	  max=b;min=a;
	}
	 int i;int s;
	 for( i=1;;i++){
	 	s=0;
	 	s=(max*i)%min;
	 	if(s==0)
	 	  break;
	 }
	 return (max*i);
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