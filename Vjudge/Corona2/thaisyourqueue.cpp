#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long p,c,e;
	char com;
	int T=1;
	while(cin>>p>>c && p&&c){
		deque<int>arr;
		for(int i=1;i<=p && i<=1000;i++) arr.push_back(i);
		cout<<"Case "<<T++<<":\n";
		while(c--){
			cin>>com;
			if(com=='E') {
				cin>>e;
				auto it=find(arr.begin(),arr.end(),e);
				arr.push_front(e);
				arr.erase(it);
			}
			else{
				cout<<arr.front()<<endl;
				arr.push_back(arr.front());
				arr.pop_front();
			}
		}
	}	
}