#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<int>nodes[110];
int d[110];

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,e,x,y,s=0;
	cin>>n>>e;
	while(e--){
		cin>>x>>y;
		nodes[x].push_back(y);
		nodes[y].push_back(x);
		d[x]++,d[y]++;
	}
	while(1){
		vector<int>tmp;
		bool f=0;
		for(int i=1;i<=n;i++) if(d[i]==1){f=1;d[i]--;tmp.push_back(i);} 
		if(!f) break;
		s++;
		for(auto i:tmp)
			for(auto j:nodes[i])
				d[j]--;  			
	}
	cout<<s<<"\n";

}