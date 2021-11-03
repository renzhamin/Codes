#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int n=8;
bool used[n][n],ans[92][n][n];
int sol;
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
    int t,x,y;cin>>t;
    while(t--){
        cin>>x>>y;
        cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n"<<"\n"; 
        vector<vector<int>>arr;
        vector<int>row(8);
        for(int s=0;s<sol;++s){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ans[s][i][j] && (i+1)==x && (j+1)==y){
                        for(int i=0;i<n;i++){
                            for(int j=0;j<n;j++){
                                if(ans[s][j][i]){
                                    row[i]=j+1;
                                }
                            }
                        }
                        arr.emplace_back(row);
                    }
                }
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();++i){
            if(i<9) cout<<" ";
            cout<<i+1<<"      ";
            for(int j=0;j<arr[i].size()-1;++j){
                cout<<arr[i][j]<<" ";
            }
            cout<<arr[i][arr[i].size()-1]<<"\n";
        }
        if(t)cout<<"\n";
    }
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