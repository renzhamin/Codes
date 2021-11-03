//Codeforces Chossing The Commander
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int alph=2;
const int maxBits=27;
const int mx=3e6;
 
 
struct TrieNode{
    int len=0;
}T[mx];
 

class BitTrie{
    int trie[mx][alph],nodeNo;
    queue<int>vaccant;
public:
    int id=0;
 
    BitTrie(int ID=0){
        id=ID;
    }
 
    int nextId(int ind){
        return trie[id][ind];
    }
 
    bool exists(int ind){
        return nextId(ind)!=0;
    }
 
    int nextNode(int ind){
        int &I=trie[id][ind];
        if(!I){
            if(vaccant.size()){
                I = vaccant.front();
                vaccant.pop();
            } 
            else 
            I=++nodeNo;
        }
        return I;
    }
 
    TrieNode& next(int ind){
        return T[nextId(ind)];
    }
 
    void goNext(int ind){
        id=nextId(ind);
    }
 
    TrieNode& node(){
        return T[id];
    }

    void insert(int num){
        string s=bitset<maxBits>(num).to_string();
        id=0;
        for(int i=0;i<maxBits;i++){
            id=nextNode(s[i]-'0');
            T[id].len++;
        } 
    }
    
    void erase(int num){
        string s=bitset<maxBits>(num).to_string();
        id=0;
        for(int i=0;i<maxBits;i++){
            int &cur=trie[id][s[i]-'0'];
            id=cur;
            T[cur].len--;
            if(T[cur].len==0){
                vaccant.push(cur);
                cur=0;
            }
        } 
    }
 
}x;
 

ll noOfFollowers(ll personality,ll leadership){
    string ps=bitset<maxBits>(personality).to_string();
    string ls=bitset<maxBits>(leadership).to_string();
    x.id=0;
    ll ans=0;
    for(int i=0;i<maxBits;i++){
        int p = ps[i]-'0';
        int l = ls[i]-'0';
        if(l==0){
            x.goNext(p);
        } else {
            if(x.exists(p))
                ans += x.next(p).len;
            x.goNext(p^1);
        }
        if(x.node().len==0) break;
    } 
    return ans;
}

int main(){
    int c,t;
    cin>>t;
    while(t--){
        ll personality,leadership;
        cin>>c>>personality;

        if(c==1){
            x.insert(personality);
        } else if(c==2){
            x.erase(personality);
        } else {
            cin>>leadership;
            cout<<noOfFollowers(personality,leadership)<<"\n";
        }
    }
}
