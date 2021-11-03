#include <bits/stdc++.h>
#define ll long long 
using namespace std;
#define MX 1000000
#define undefined INT_MIN // cant be used as a value 

struct Map{
    int a[MX],keys[MX],size=0,realsize=0;
    
    Map(){
        for(int i=0;i<MX;i++) a[i]=undefined;
    }

    void insert(int key,int value){
        if(key<0 || key>=MX || value==undefined){
            return;
            // not supported
        }
        for(int i=0;i<size;++i){
           if(a[keys[i]]==value) return; 
        }
// default behaviour of std::map is not updating when same key is       inserted using the insert method ( not by access[ key ] = value )
        keys[size++]=key;
        sort(keys,keys+size);
        a[key]=value;
        realsize++;
    }
    
    int find(int key){
        if(key<0 || key>=MX){
            return undefined;
        }
        return a[key];
    }
    
    void erase(int key){
       if(key<0 || key>=MX){
            return;
        }
        if(a[key]!=undefined)
            realsize--;
        a[key]=undefined;
    }

    bool empty(){
        return realsize>0;
    }

};

int main(){
    Map mp;
    mp.insert(10,2);
    mp.insert(2,3);
    mp.insert(3,100);
    mp.erase(2);
    //traversing the map
    for(int i=0;i<mp.size;++i){
       if(mp.a[mp.keys[i]]!=undefined){
           cout<<mp.keys[i]<<","<<mp.a[mp.keys[i]]<<"\n";
       }
    }
    // will print 
    // 3,100
    // 10,2
    int x;
    if((x=mp.find(10))!=undefined){
        cout<<x<<"\n"; // prints 2
    }
    cout<<mp.empty()<<"\n"; //prints 1
    mp.erase(3); mp.erase(10);
    cout<<mp.empty()<<"\n"; // prints 0
}


void mapfunctions(){
    map<int,int>mp;
    //insert operations
    mp.insert(make_pair(1,3));
    mp.insert(make_pair(2,4));
    mp.insert(make_pair(3,5));
    auto it=mp.find(3); // return the iterator containing key 3
    cout<<it->second<<"\n"; // prints 5
    mp.erase(it);
    auto ft=mp.find(3); // will return mp.end() because 3 is erased
    mp.erase(2); // erase by value
    for(auto it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<"\n";
    } // only prints 1

    //alternative way to insert key elements
    mp[100]=0;
    cout<<mp[100]<<"\n"; // prints 0
    cout<<mp.empty()<<"\n"; // prints 1 as map is not empty
}
