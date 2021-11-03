#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool x(pair<int,int>&a,pair<int,int>&b){
	if(a.second==b.second) return a.first>b.first;
	else return a.second<b.second;
}

int numofdiv(int n){
	int s=0;
	for(int i=1;i<=n;i++)
		if(n%i==0)
			s++;
	return s;	
}

pair<int,int>cache[1001];

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	
	for(int i=1;i<=1000;i++){
		cache[i].first=i;
		cache[i].second=numofdiv(i);
	}

	sort(cache,cache+1001,x);

	int t,n,T=1;cin>>t;
	while(t--){
		cin>>n;
		cout<<"Case "<<T++<<": "<<cache[n].first<<endl;
	}
}