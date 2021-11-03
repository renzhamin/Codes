#include <iostream>
using namespace std;
int fact(int n){
	int s=1;
	for(int i=1;i<=n;i++){
		s*=i;
	}
	return s;
}
