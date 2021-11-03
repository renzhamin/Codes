#include <iostream>
#include <string.h>
using namespace std;
int arr[105],N,X;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,tmp,lowest,x;cin>>t; 
	while(t--){
		memset(arr,0,sizeof(arr));
		lowest=-1;
		cin>>N>>X;
		x=X;
		for(int i=0;i<N;i++){
			 cin>>tmp;
			 arr[tmp]=1;
			 lowest=max(lowest,tmp);
		}
		int l;
		for(l=1;l<=lowest+x;l++){
			if(!arr[l])
				X--;
			if(!X) if(!arr[l+1]) break;
		}
		cout<<l<<endl;
	}
}