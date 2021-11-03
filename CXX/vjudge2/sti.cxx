#include <iostream>
#include <sstream>
using namespace std;
int sti(string s){
	stringstream i(s);
	double x;
	i>>x;
	return x;
}

int main(){
	cout<<str2int("0099");
}