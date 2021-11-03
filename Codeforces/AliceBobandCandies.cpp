#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	ll n,A,B,curA,curB,s;
	int t;cin>>t;
	while(t--){
		A=B=curA=curB=s=0;
		cin>>n;
		ll arr[n];
		for(int i=0;i<n;i++) cin>>arr[i];
        int i=0,j=n-1;
        bool a=1;
        while(i<=j){
           if(a){
              while(curA<=curB && i<=j) curA+=arr[i],i++;
              A+=curA;
              a=0;
              s++;
              curB=0;
           } else {
           	  while(curB<=curA && j>=i) curB+=arr[j],j--;
           	  B+=curB;
           	  s++;
           	  a=1;
           	  curA=0;
           }
        }
        cout<<s<<" "<<A<<" "<<B<<" "<<"\n";
	}
}