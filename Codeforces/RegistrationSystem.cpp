#include <iostream>
#include <map>
using namespace std;
map<string,int>user;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string tmp;
	while(n--){
		cin>>tmp;
		if(user[tmp])
			cout<<tmp<<user[tmp]<<endl;
		else
			cout<<"OK"<<endl;
		user[tmp]++;
	}
	
}