#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
pair<int,int>T[1000001];

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.second < b.second); 
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,q;cin>>t;
	while(t--){
		cin>>q;
		for(int i=0;i<q;i++)
			cin>>T[i].first>>T[i].second;
		sort(T,T+q,sortbysec);
		int end=-1000,s=0;
		for(int i=0;i<q;i++){
			if(T[i].first>=end){
				s++;
				end=T[i].second;
			}
		}
		cout<<s<<endl;

	}
}