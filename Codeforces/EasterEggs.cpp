#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s="VIBGYOR";
	int n;cin>>n;
	for(int i=0,j=0;i<n;cout<<s[j],i++,++j) if(j>6) j=3;  
}