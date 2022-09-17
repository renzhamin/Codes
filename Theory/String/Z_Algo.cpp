#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int mx=1e6+1;

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
    string pattern="abc";
    string text="abcFFabcRRabcD";
    text = pattern + "#" + text;
    Z_Algo(text);
    for(int i=pattern.size();i<text.size();i++){
        if(Z[i]==pattern.size()){
            cout<<"Match at "<<i-pattern.size()-1<<"\n";
        }
    }
}
