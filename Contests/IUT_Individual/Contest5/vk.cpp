#include<iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int l=s.length(),a=0,p=0,i=0;
	if(l==1)
	cout<<0;
	else{
		while(i<l-1){
			if(s[i]=='V'&&s[i+1]=='K')
			{p++; i+=2;}
			else if(a==0&&s[i]=='K'&&s[i+1]=='K')
			{a++; p++; i+=2;}
			else if(a==0&&s[i]=='V'&&s[i+1]=='V'&&s[i+2]!='K')
			{a++; p++; i+=2;}
			else
			i++;
		}
		cout<<p;
	}
}
