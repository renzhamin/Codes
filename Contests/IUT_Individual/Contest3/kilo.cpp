#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int a,b,n,i;
	cin>>a>>b>>n;
	for(i=1;i<=n;i++){
		if(i%a==0 && i%b==0){
			cout<<"FizzBuzz"<<endl;
		} else if(i%a==0) {
			cout<<"Fizz"<<endl;
		} else if(i%b==0){
			cout<<"Buzz"<<endl;
		} else {
			cout<<i<<endl;
		}

	}
	return 0;
}