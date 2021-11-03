#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;cin>>n; pair<int,int>price[n];
	
	for(int i=0;i<n;i++){
		cin>>price[i].first>>price[i].second;
	}

	sort(price,price+n);
	
	for(int i=0;i<n-1;i++){
		if(price[i].second>price[i+1].second){
			cout<<"Happy Alex";
			return 0;
		}
	}
	
	cout<<"Poor Alex";
}