#include <iostream>
using namespace std;
int main(){
    long long steak,pans,time=0;;
    cin>>steak>>pans;
    while(steak>0){
        steak-=pans;
        time+=5;
    }
    if(time<10) time=10;
    cout<<time<<endl;
}
