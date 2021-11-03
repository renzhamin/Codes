#include <iostream>
#include <cstring>
using namespace std;
int cache[100][100];
int arr[100][100];
int find(int i, int j,int n){
   if(i>n || j>n)
    return 0;
   if(cache[i][j]!=-1)
   	return cache[i][j];
   else{
   	cache[i][j]=arr[i][j]+max(find(i+1,j,n), find (i+1,j+1,n));
	cout<<"cache["<<i<<"]"<<"["<<j<<"]="<<cache[i][j]<<endl;	
   	return cache[i][j];
   }
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n;cin>>t;
	while(t--){
		cin>>n; 
		memset(cache,-1,sizeof(cache));
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>arr[i][j];

		find(0,0,n-1);
/*		for(int i=0;i<n;i++,cout<<endl)
			for(int j=0;j<=i;j++)
				cout<<cache[i][j]<<" ";
*/		//cout<<cache[0][0]<<endl;
	}
}