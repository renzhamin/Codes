#include <bits/stdc++.h>
#define ll long long 
using namespace std;

unordered_map<char, int> mp; 
int p[10];
string s[3];

ll f(int i){
    ll m=1,num=0;
    for(int j=s[i].size()-1;j>=0;j--){
        num+=p[mp[s[i][j]]]*m;
        m*=10;
    }
    return num;
}


int main(){
    int n=10;
    iota(p,p+n,0);
    cin>>s[0]>>s[1]>>s[2];
    int id=0;
    unordered_set<char>st;
    for(int i=0;i<3;i++){
        for(int j=0;j<s[i].size();j++){
            st.emplace(s[i][j]);
        }
    }
    if(st.size()>10){
        cout<<"UNSOLVABLE"<<"\n";
        return 0;
    }
    for(auto &i:st) mp[i]=id++; 
    do {
        bool f1 = 0;
        for(int i=0;i<3;i++){
            if(p[mp[s[i][0]]]==0){
                f1=1; break;
            }
        }
        if(f1) continue;
        ll N1=f(0),N2=f(1),N3=f(2);
        if(N1+N2==N3){
            cout<<N1<<" "<<N2<<" "<<N3<<"\n";
            return 0;
        }
        
    } while(next_permutation(p,p+n));
    cout<<"UNSOLVABLE"<<"\n";
}
/*
send
more
money
*/
