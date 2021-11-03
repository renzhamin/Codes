#include <iostream>
#include <cmath>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	float cup=0,med=0,tmp,n=3;
	while(n--){
		cin>>tmp; cup+=tmp;
	} 
	n=3;
	while(n--){
		cin>>tmp; med+=tmp;
	}
	cin>>n;
	cout<<(ceil(cup/5)+ceil(med/10)<=n? "YES":"NO");

}