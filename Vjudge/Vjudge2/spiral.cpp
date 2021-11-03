#include <iostream>
using namespace std;
int main(){
   int t;cin>>t;
   while(t--){
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>arr[i][j];
    int r2,c2,r1=0,c1=0;r2=r;c2=c;
    cout<<endl;
    while(c1<c2 && r1<r2){
    for(int i=r1;i<c2;i++) cout<<arr[r1][i]<<" ";r1++;
    for(int i=r1;i<r2;i++) cout<<arr[i][c2-1]<<" ";c2--;
    if(r1<r2)
        for(int i=c2-1;i>=c1;i--) cout<<arr[r2-1][i]<<" ";r2--;
    if(c1<c2)
        for(int i=r2-1;i>=r1;i--) cout<<arr[i][c1]<<" ";c1++;
    }
   }
}
