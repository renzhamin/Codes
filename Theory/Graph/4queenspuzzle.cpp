#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int n=4;
int used[n][n],ans[92][n][n],sol;

void addsol(); void showsol();
bool check(int,int);

void bt(int row=0){
    for(int i=0;i<n;++i){
        if(check(row,i)){
            used[row][i]=1;
            if(row!=n-1)
                bt(row+1);
            else
                addsol();
            used[row][i]=0;
        }
    }
}


int main(){
    bt();
    cout<<sol<<"\n";
}


bool check(int row,int col){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(used[i][j]){
                if(i==row || j==col || 
                    abs(row-i)==abs(col-j))
                    return 0;                
            }
        }
    }
    return 1;
}


void addsol(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[sol][i][j]=used[i][j];
        }
    }
    sol++;
}


void showsol(){
    for(int s=0;s<sol;s++){
        for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 cout<<ans[s][i][j]<<" ";
             }
             cout<<"\n";
         } 
         cout<<"\n";
    }    
}