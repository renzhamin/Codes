#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int freq[10],tmp;

int main(){
    cin>>tmp;
    while(tmp>0){
        freq[tmp]++;
        cin>>tmp; 
    }
    vector<pair<int,int>>arr;
    for(int i=1;i<10;i++){
        if(freq[i])
            arr.emplace_back(freq[i],i);
    }
    sort(arr.begin(),arr.end());

    string time[2] = {" time"," times"};

    for(int i=arr.size()-1;i>=0;i--){
        tmp = arr[i].first;
        cout<<arr[i].second<<" occurs "<<tmp<<time[tmp>1]<<"\n";
    }
}
