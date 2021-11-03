#include <iostream>

using namespace std;
int main(){
    string can;cin>>can;
    int cs=can.length();
    int t;cin>>t;
    while(t--){
    string w;cin>>w;
    int ws=w.length();
    int s=0;
    for(int i=0;i<ws;i++){
        for(int j=0;j<cs;j++){
            if(w[i]==can[j]) s++;
        }
    }
    cout<<(s==ws? "Yes":"No")<<endl;
    }
}
