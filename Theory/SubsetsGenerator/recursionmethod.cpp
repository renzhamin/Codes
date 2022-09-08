#include <iostream>
#include <vector>
using namespace std;

int n,cnt=0;
string s;

void subset(int i,string arr){
	if(i==n) {
		cout<<arr<<endl;
		return;
	}
	subset(i+1,arr);
	subset(i+1,arr+s[i]);  	
}


int main(){
	s="ABC";
	n=s.length();
	subset(0,"");
}