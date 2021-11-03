#include <iostream>
#include <map>
using namespace std;
multimap<int,int>m;
int main(){
	freopen("Input.txt","r",stdin);
	int n,tmp;cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp; m.insert({tmp,i+1});
	}
	int s=0,j=0;
	for(auto i=m.rbegin();i!=m.rend();i++,j++)
		s+=j*(i->first)+1;
	cout<<s<<endl;
	for(auto i=m.rbegin();i!=m.rend();i++)
		cout<<i->second<<" ";	
	cout<<endl;

}
