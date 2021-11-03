#include <iostream>
using namespace std;
int main(){
    int arr[]={1,3,4,5};
    int cu[4]={};
    cu[0]=arr[0];
    for(int i=1;i<4;i++){
        cu[i]=arr[i]+cu[i-1];
    }
    for(int i=0;i<4;i++){
        cout<<cu[i]<< " ";
    }
}
