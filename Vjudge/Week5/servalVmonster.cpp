#include <iostream>
using namespace std;
int main(){
    int h,a;
    int s=0;
    cin>>h>>a;
    while(h>0){
        h-=a;
        s++;
    }
    cout<<s<<endl;
}
