#include <bits/stdc++.h>
#define ll long long 
using namespace std;


struct data{
    string name;
    int ml,ds,net,total;
};

int main(){
    int n;cin>>n;
    struct data student[n];
    for(int i=0;i<n;++i){
        cin>>student[i].name>>student[i].ml>>student[i].ds>>student[i].net;
        student[i].total=student[i].ml+student[i].ds+student[i].net;
    }

    #define equalbutnotreally(x,y) (a.x==b.x && a.y > b.y)    
    sort(student,student+n,[](auto a,auto b){
        if(a.total>b.total)
            return (bool)1;
        return equalbutnotreally(total,ml)||
            equalbutnotreally(ml,ds)||equalbutnotreally(ds,net);
    });

    for(int i=0;i<n;++i){
        cout<<i+1<<" "<<student[i].name<<"\n";
    }
}

