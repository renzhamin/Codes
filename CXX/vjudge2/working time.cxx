#include <iostream>
#include <sstream>
using namespace std;
double total(string tm){
	string h1=tm.substr(0,2);
	string m1=tm.substr(3,4);
	stringstream hour(h1);
	stringstream minute(m1);
	double h,m;
	hour>>h;minute>>m;
	m=m/60;
	return (h+m);  
}

int main(){
	int t;cin>>t;
	while(t--){
	int n,h;cin>>n>>h;
	double s=0;
	for(int i=0;i<n;i++){
		double sd=0;
		string s1,s2;
		cin>>s1>>s2;
		sd=total(s2)-total(s1);
		s+=sd;
	}
    if(s>=h)
       cout<<"YES"<<endl;
    else
       cout<<"NO"<<endl;
	}
}

