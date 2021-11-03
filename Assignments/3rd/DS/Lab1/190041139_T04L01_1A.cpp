#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<pair<int,int>>arr,ans;
// energe - index
int n,tmp,N,s;

vector<int> bs(int lo,int x){
    int hi=n-1,mid,start=lo;
    while(lo<=hi){
        mid = (lo+hi)>>1LL;
        if(arr[mid].first == x)
            break;
        else if(arr[mid].first>x)
            hi = mid-1;
        else
            lo = mid+1;
    }
    if(lo > hi) return {};
    vector<int>ans;

    int i = mid;
    while(i<n && arr[i].first == x)
        ans.emplace_back(i++);

    i = mid-1;
    while(i >= start && arr[i].first == x)
        ans.emplace_back(i--);

    return ans;
}


int main(){
    cin>>tmp;
    for(int i=0;tmp!=0;i++){
        arr.emplace_back(tmp,i);
        cin>>tmp;
    }
    n = arr.size();

    sort(arr.begin(),arr.end());

    cin>>N;

    for(int i=0;i<n-1;i++){
        auto v = bs(i+1,N-arr[i].first);
        s = v.size();
        if(!s) continue;
        for(int j=0;j<s;j++){
            ans.emplace_back(arr[i].second,arr[v[j]].second);
        }
    }

    n = ans.size();
    if(!n) {
        cout<<"No pair found!"<<"\n";
        return 0;
    }
    cout<<n<<" Paris :\n";
    for(int i=0;i<n;i++){
        cout<<"(worker-"<<ans[i].first+1<<", worker-"<<ans[i].second+1<<")\n";
    } 
}
