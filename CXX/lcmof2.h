#include <iostream>
using namespace std;
int lcmof2(int a,int b){
	int max,min;
	if(a>b){
	  max=a;min=b;
	}
	else{
	  max=b;min=a;
	}
	 int i;int s;
	 for( i=1;;i++){
	 	s=0;
	 	s=(max*i)%min;
	 	if(s==0)
	 	  break;
	 }
	 return (max*i);
}
