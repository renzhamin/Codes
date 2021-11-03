#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s; cin>>s;
	int n=s.length(),cs=0;
	int arr[n+1],csum[n+1];
	arr[0]=0;arr[1]=0; csum[0]=0;csum[1]=0;
	for(int i=2;i<=n;i++){
		if(s[i-1]==s[i-2])
			arr[i]=1;
		else
			arr[i]=0;
		cs+=arr[i];
		csum[i]=cs;
	}

	//for(int i=1;i<=n;i++) cout<<csum[i]<<endl;
	int q,x,y;cin>>q;
	while(q--){
		cin>>x>>y;
		cout<<csum[y]-csum[x]<<endl; 
	}

}