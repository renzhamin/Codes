#include <iostream>
#include <map>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,m;
	map<string,string>dict;
	cin>>n>>m;
	string s[n],tmp,tmp2;
	while(m--){
		cin>>tmp>>tmp2;
		dict[tmp]=tmp2;
	} 
	int i=0;
	while(n--){
		cin>>tmp;
		tmp2=dict[tmp];	
		if(tmp.length()>tmp2.length())
			s[i]=tmp2;
		else
			s[i]=tmp;
		i++;
	}
	for(int k=0;k<i;k++)
		cout<<s[k]<<" ";
}