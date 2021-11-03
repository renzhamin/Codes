#include <iostream>
#include <stack>
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string s; cin>>s;
	stack<char>arr;
	int n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='[') arr.push(s[i]);
		if(arr.empty()) goto no;
		if(s[i]==')' && arr.top()=='(') arr.pop();	
		if(s[i]==']' && arr.top()=='[') arr.pop();
		if(s[i]=='}' && arr.top()=='{') arr.pop();	
	}
	if(arr.empty()) cout<<"Yes\n";
	else
		no:
			cout<<"No\n";
	
}