#include <iostream>
using namespace std;
int main(){
	int t,sum=0;cin>>t;
	int i,j,start=0,end;
	string s;
	while(t--){
		cin>>s;
		int n=s.length();
		end=n;
		for(i=0;i<n;i++)
			if(s[i]=='1') {start=i;break;} 
		for(j=n-1;j>=0;j--)
			if(s[j]=='1') {end=j;break;}
		sum=0;
		for(int k=start;k<end;k++)
			if(s[k]=='0') sum++;
		cout<<(n==1||i==n?0:sum)<<endl;
	}
}