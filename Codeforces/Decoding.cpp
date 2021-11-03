#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;string s;cin>>n>>s;
	char a[n];
	int mid=(n-1)/2,r=1,l=1,now=mid,onl=mid,onr=n-mid-1;
	for(int i=0;i<n;++i){
		a[now]=s[i];
		if(onl>=onr){
			now=mid-l;
			l++;
			onl--;
		} else {
			now=mid+r;
			r++;
			onr--;
		}
	}	
	a[n]='\0';
	cout<<a<<"\n";
}