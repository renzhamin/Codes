#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	pair<int,char>mp[3];
	mp[0]={0,'A'},mp[1]={0,'B'},mp[2]={0,'C'};
	string s;

	int t=3;
	while(t--){
		cin>>s;
		if(s[1]=='>') mp[s[0]-'A'].first++; else mp[s[2]-'A'].first++;		
	}
	if(mp[0].first==1 && mp[1].first==1 && mp[2].first==1){
		cout<<"Impossible"<<"\n";
		return 0;
	}
	sort(mp,mp+3);
	for(auto i:mp) cout<<i.second;

}