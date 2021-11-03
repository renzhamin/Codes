#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a;cin>>b;cin>>c;
	int s=0;
	int max;int res[2];
	if((a>b) && (a>c)){
	   max=a;
	   res[0]=b;res[1]=c;
	}else if(b>a && b>c){
	   max=b;
	   res[0]=a;res[1]=c;
	 }
	 else {
	   max=c;
	   res[0]=b;res[1]=a;
	 }
	 if((res[0]+res[1])<=max){
	 	s=max-res[0]-res[1]+1;
	 } else {
	 	s=0;
	 } 
	 cout << s;
}