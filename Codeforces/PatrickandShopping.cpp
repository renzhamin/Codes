#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int x,y,z; cin>>x>>y>>z;
	cout<<min({(x+y)*2,x+y+z,min(x,y)*2+z*2});
}