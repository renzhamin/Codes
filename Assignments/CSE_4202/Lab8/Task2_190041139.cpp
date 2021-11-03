#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    vector<int>arr;
    for(int i=1;i<6;i++) arr.push_back(i);

    vector<int>::iterator it;
    int i=1;
    for(it=arr.begin();it!=arr.end();it++,i++){
        if(i==3) arr.erase(it);
    }

    for(it=arr.begin();it!=arr.end();it++)
        cout<<*it<<"\n";
    //will print 1,2,4,5
}
