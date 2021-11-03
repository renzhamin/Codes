#include <iostream>
using namespace std;
int d2b(int dec){
    int r=0,j=1;
    for(int i=0;dec>0;i++){
        r+=(dec%2)*j;
        dec/=2;
        j*=10;
    }
    return r;
}

int main(){
	int n;cin>>n;
    cout << d2b(n)<<endl;
}
