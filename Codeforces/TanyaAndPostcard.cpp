#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    pair<int,int>freq[26]{},f2[26]{};
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();++i){
        if(isupper(a[i])){
            freq[a[i]-'A'].first++;
        } else {
            freq[a[i]-'a'].second++;
        }
    }
    for(int i=0;i<b.length();++i){
        if(isupper(b[i])){
            f2[b[i]-'A'].first++;
        } else {
            f2[b[i]-'a'].second++;
        }
    }
    int y=0,w=0;
    for(int i=0;i<26;++i){
        int yc=min(freq[i].first,f2[i].first);
        int ys=min(freq[i].second,f2[i].second);
        y+=ys+yc;
        freq[i].first-=yc;f2[i].first-=yc;
        freq[i].second-=ys;f2[i].second-=ys;
        w+=min(freq[i].first+freq[i].second,
                f2[i].first+f2[i].second);
    }

    cout<<y<<" "<<w<<"\n";
}