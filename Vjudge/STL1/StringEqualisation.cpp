#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n--){
		string a,b;
		cin>>a>>b;
		string ans="NO";
		for(int i=0;i<a.length();i++)
			for(int j=0;j<b.length();j++)
				if(a[i]==b[j])
					ans="YES";
		
		cout<<ans<<endl;
	}
}