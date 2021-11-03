#include <iostream>
#include <sstream>
using namespace std;
int main(){
    int n;cin>>n;
    int i;
    for(i=0;i<n;i++){
        string s[n];
        cin>>s[i];
        if(s[i][0]=='m') continue;
        stringstream ss(s[i]);
        int x;ss>>x;
        if(x!=(i+1)){
            cout<<"something is fishy"<<endl;
            break;
        }
    }
    if(i==n)
        cout<<"makes sense"<<endl;
}
