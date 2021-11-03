#include <iostream>
using namespace std;
int main(){
    int n;n=5;
    int arr[]={2,9,12,16,25};
    int m;
    cin>>m;
    int mid,low=0,high=n-1;
    mid=(high+low)/2;
    while(low<=high){
        mid=(high+low)/2;
        if(arr[mid]==m)
            break;
        if(arr[mid]>m)
            high=mid-1;
        if(arr[mid]<m)
            low=mid+1;

    }
    if(arr[mid]<=m && mid+1<(n-1)) mid++;

    //cout<<low<<endl<<high<<endl;
    cout<<arr[mid]<<endl;
}
