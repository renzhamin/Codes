#include <iostream>
#include <vector>
using namespace std;
int main(){
	//freopen("Input.txt","r",stdin);
	int n,a,b,c,d;
	cin>>n;
	vector<int>arr(n+1);
	for(int i=1;i<=n;i++) arr[i]=i;
	cin>>a>>b>>c>>d;
	int i,j;
	for(i=a,j=b;i<j;i++,j--)
		swap(arr[i],arr[j]);
	//for(int i=1;i<=n;i++) cout<<arr[i]<<endl;
	for(i=c,j=d;i<j;i++,j--)
		swap(arr[i],arr[j]);
	for(i=1;i<=n;i++)
		cout<<arr[i]<<" ";

}