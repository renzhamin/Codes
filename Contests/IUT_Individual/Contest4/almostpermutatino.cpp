#include <iostream>
#include <algorithm>
using namespace std;
int arr[8][8],permute[8];
const int Max = (int)1e+9;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,len;
	cin>>n>>len;
	for(int i=0;i<n;i++){
		for(int j=0;j<len;j++){
			char digit;cin>>digit;
			arr[i][j]=digit-48;
		}
	}
	for(int i=0;i<len;i++) permute[i]=i;
	int res=Max;
	do{
		int maxi=-Max,mini=Max;
		for(int i=0;i<n;i++){
			int tmp=0;
			for(int j=0;j<len;j++)
				(tmp*=10)+=arr[i][permute[j]];
			maxi=max(maxi,tmp); 
			mini=min(mini,tmp);
			res=min(maxi-mini,res);
		}
	}while(next_permutation(permute,permute+len));

	cout<<res<<endl;
}
