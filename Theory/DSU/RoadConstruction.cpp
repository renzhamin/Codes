#include <bits/stdc++.h>
#define ll long long 
using namespace std;
map<string,string>parent;
map<string,int>s;

string root(string x){
    return (x==parent[x]?x:parent[x]=root(parent[x]));
}


void Union(string a,string b){
    if(s[a]>s[b]) swap(a,b);
    parent[a]=b;
    s[b]+=s[a];
}

ll kruskal(pair<int,pair<string,string>>*edges,int n){
    ll sum=0;
    string x,y;
    for(int i=0;i<n;i++){
        x=root(edges[i].second.first),
        y=root(edges[i].second.second);
        if(x==y) continue;
        Union(x,y);
        sum+=edges[i].first;
    }         
    return sum;
}

int main(){
    int t,T=1,w;cin>>t;
    string a,b;
    while(t--){
        int n,l=0;cin>>n;
        parent.clear(),s.clear();
        pair<int,pair<string,string>>edges[n];
        while(n--){
            cin>>a>>b>>w;
            if(!s[a])parent[a]=a,s[a]=1;
            if(!s[b])parent[b]=b,s[b]=1;
            if(!w){
                string x=root(a),y=root(b);
                if(x!=y)
                    Union(x,y);
                continue;
            }
            edges[l].first=w;
            edges[l].second.second=b;
            edges[l].second.first=a;
            l++;
        }
        cout<<"Case "<<T++<<": ";
        
        sort(edges,edges+l);
        ll sum=kruskal(edges,l);
        
        auto it=parent.begin();
        string tmp=root(it->first);
        for(auto i:parent)
            if(root(i.first)!=tmp)
                goto imp;

        cout<<sum<<"\n";
        continue;
        imp:
        cout<<"Impossible"<<"\n";
    }

}

/*
1
12
Dhaka Sylhet 0
Ctg Dhaka 0
Sylhet Chandpur 9
Ctg Barisal 9
Ctg Rajshahi 9
Dhaka Sylhet 9
Ctg Rajshahi 3
Sylhet Chandpur 5
Khulna Rangpur 7
Chandpur Rangpur 7
Dhaka Rajshahi 6
Dhaka Rajshahi 7

*/