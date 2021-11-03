#include <iostream>
using namespace std;
int main(){
// (=40,:=58,)=41
    int n;cin>>n;
    string msg;cin>>msg;
    int h=0,s=0;
    for(int i=0;i<n;i++){
        bool happy=((msg[i]==(char)58 && msg[i+1]==(char)41) || (msg[i]==(char)40 && msg[i+1]==(char)58));
        bool sad=(msg[i]==(char)58 && msg[i+1]==(char)40 || msg[i]==(char)41 && msg[i+1]==(char)58);
        if(happy) h++;
        else if(sad) s++;

    }
    if(h==s) cout << "BORED";
    else if(h>s) cout << "HAPPY";
    else cout << "SAD";
}
