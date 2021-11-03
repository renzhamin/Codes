#include<bits/stdc++.h>
using namespace std;
main()
{
	string s;cin>>s;
	int n=s.length(),su=0;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-i-1]) su++;
//		cout<<"at i "<<i<<" n-1-i = "<<n-1-i<<endl;
	}
	if(su==1) cout<<"YES";
	else if(su==0 && n%2!=0) cout << "YES";
	else cout<<"NO";
}
