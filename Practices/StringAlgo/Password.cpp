#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e6;

int Z[mx];

void Z_Algo(string s){
    int n = s.length();
    int l=0,r=0,k;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && s[r]==s[r-l])
                r++;
            Z[i]=r-l;
            r--;
        } 
        else {
            k=i-l;
            if(i+Z[k]<r+1){
                Z[i] = Z[k];
                continue;
            } 

            l=i;
            while(r<n && s[r]==s[r-l])
                r++;
            Z[i]=r-l;
            r--;
        }
    }
}   


int main(){
    string s; cin>>s;
    Z_Algo(s);
    int mx=-1,n=s.size();
    int mxLen=0,ind=0;


    for(int i=1;i<n;i++){
        if(Z[i]+i==n && Z[i]<=mx){
            if(Z[i]>mxLen){
                ind = i;
                mxLen = Z[i];
            }
        }
        mx = max(mx,Z[i]);
    }

    if(!mxLen){
        cout<<"Just a legend"<<"\n";
    } else {
        cout<<s.substr(ind,mxLen)<<"\n";
    }

}
