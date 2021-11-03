#include <iostream>
#include <map>
using namespace std;
map<string,int>str;
int main(){		
	int n;
	string s;
	cin>>n>>s;
	string s1,s2;
	int sum=0;
	for(int i=0;i<n-1;i++){
		s1=s.substr(i,2);
		str[s1]++;
		if(str[s1]>sum) { sum=str[s1];s2=s1;}
	}
	cout<<s2[0]<<s2[1]<<endl;
}