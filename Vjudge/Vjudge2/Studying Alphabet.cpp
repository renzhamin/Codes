#include<bits/stdc++.h>
using namespace std;
int main(){
    string can;cin>>can;
    sort(can.begin(),can.end());
    int n;cin>>n;
    string w;
    for(int i=0;i<n;i++){
        cin>>w;
        sort(w.begin(),w.end());
        if(can==w)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}
