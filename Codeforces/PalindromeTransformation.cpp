#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n,p;
    string str;
    cin>>n>>p>>str;
    ll i=0,j=n-1,arr[n]{};
    while(i<j){
        if(str[i]!=str[j]){
            arr[i]=arr[j]=min((str[i]-str[j]+26)%26,(str[j]-str[i]+26)%26);
        } 
        i++,j--;
    }   
    ll barrier=n/2,ans=0,mp;
    if(p<=barrier){
        if(2*p-1>barrier){
            mp=p-1;
            for(i=p-1;i<barrier;i++) {
                ans+=arr[i];
                if(arr[i]>0) mp=i;
            } 
            ans+=max((mp-p-1)*2,0LL);
            mp=p-2;
            if(mp>0) ans++;
            for(i=p-2;i>=0;--i){
                ans+=arr[i];
                if(arr[i]>0) mp=i;
            }
            ans+=max(p-2-mp,0LL);
        } else {
            mp=p-1;
            for(i=p-1;i>=0;--i){
                ans+=arr[i];
                if(arr[i]>0) mp=i;
            }     
            ans+=((p-1-mp)*2,0LL);
            mp=p;       
            for(i=p;i<barrier;i++) {
                ans+=arr[i];
                if(arr[i]>0) mp=i;
            } 
            ans+=((barrier-1-mp),0LL);
        }
        cout<<ans<<"\n";
    }
}