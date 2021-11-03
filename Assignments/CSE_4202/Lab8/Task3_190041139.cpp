#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define pi pair<int,int>

struct Pair{
    int x,y;
};

int main(){
   Pair a;
   a.x=1,a.y=2;
}


template<typename T1,typename T2>
pi mp(T1 x,T2 y){  // make_pair
    return pi(x,y);
}


void pairs(){
    pi a=mp(3,5);
    vector<pi>arr;
    arr.push_back(mp(10,1));
    arr.push_back(mp(7,'A'));
    sort(arr.begin(),arr.end(),[](auto a,auto b){
            if(a.second<b.second)
                return 1;
            if(a.second==b.second)
                return (int)(b.first<a.first);
            return 0;
            });
    for(auto i:arr) 
        cout<<i.first<<" "<<i.second<<"\n";
    //will print 
    //10 1
    //7 65
}
