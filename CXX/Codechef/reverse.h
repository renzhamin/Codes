#include <iostream>
using namespace std;
int reverse(int n){
	int rem=0;
	while(n!=0){
		rem=rem*10+n%10;
		n/=10;
	}
	return rem;
}

