#include <bits/stdc++.h>
#define ll long long 
using namespace std;
vector<int>arr = {0,1,2,3,4,5,6};
int n;

void print(){
    for(auto &i:arr) 
        cout<<i<<" ";
    cout<<"\n";
}

void left_rotate(int l, int r, int c){
    // left shift in [l,r] c times
    rotate(arr.begin()+l, arr.begin()+l+c, arr.begin()+r+1);
    print();
}

void right_rotate(int l, int r, int c){
    // right shift in [l,r] c times
    r++;
    rotate(arr.begin()+l, arr.begin()+r-c,arr.begin()+r);
}

int main(){
    right_rotate(1,5,2);
    print();
}
