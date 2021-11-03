#include <bits/stdc++.h>
#define ll long long 
using namespace std;

vector<int>arr;
int tmp,n;

int bs_rec(int lo,int hi,int x){
    if(lo > hi) return -1;
    int mid = (hi+lo)/2;
    if(x == arr[mid]) return mid;
    else if(x < arr[mid]) return bs_rec(lo,mid-1,x);
    else return bs_rec(mid+1,hi,x);
}

int bs_iter(int lo,int hi,int x){
    while(lo <= hi){
        int mid = (hi+lo)/2;
        if(x == arr[mid]) return mid;
        else if(x < arr[mid]) hi = mid - 1;
        else lo = mid+1;
    }
    return -1;
}

int main(){
    cin>>tmp;
    while(tmp>=0){
        arr.emplace_back(tmp);
        cin>>tmp;
    }
    n = arr.size();

    cin >> tmp;

    cout<<bs_iter(0,n-1,tmp)<<" (using iteration)"<<endl;
    cout<<bs_rec(0,n-1,tmp)<<" (using recursion)"<<endl;
}
