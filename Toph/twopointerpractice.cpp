#include <iostream>
#include <algorithm>
using namespace std;
int n,arr[100],B;

int k1(){
	int s=0;
	for(int i=0;i<n;i++){
		if(arr[i]==B) s++;
		if(arr[i]>B) break;
	}
	return s;
}

int k2(){
	int i=0,j=n-1,tmp,s=0;
	while(1){
		tmp=arr[i]+arr[j];
		if(tmp==B) s++;
		if(tmp>B) j--; else i++;
		if(i>=j) break;
	}
	return s;
}

int k3(){
	int s=0,tmp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				tmp=arr[i]+arr[j]+arr[k];
				if(tmp==B) s++;
				if(tmp>B) break;
			}
		}
	}	
	return s;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1,ans,k;cin>>t;
	while(t--){
		cin>>n>>k>>B;
		for(int i=0;i<n;i++) cin>>arr[i];
		sort(arr,arr+n);
		if(k==1) ans=k1(); else if(k==2) ans=k2(); else ans=k3();
		cout<<"Case "<<T++<<": "<<ans<<endl;
	}
}