#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s;cin>>s;
	int n=s.length();
	int arr[n]{},sum=0;
	for(int i=0;i<n;++i){
		size_t b=s.find("bear",i);
		if(b==string::npos) break;
		for(int j=i;j<=b;j++)
			arr[j]=b+3;
		i=b; 		
	}
	for(int i=0;i<n&&arr[i];i++) sum+=(n-arr[i]);
	cout<<sum<<"\n"; 	
}