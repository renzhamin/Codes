#include <iostream>
using namespace std;
int visited[(int)1e5+1];
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n,a,b;
	cin>>n>>a>>b;
	int arr[n+1];
	for(int i=1;i<=n;i++) 
		cin>>arr[i];
	if(a==b){
		cout<<0;return 0;
	}
	if(a==arr[a]){
		cout<<-1;return 0;
	}
	int cur=a,s=0;
	while(1){
		cur=arr[cur];
		if(visited[cur]){cout<<-1;return 0;}
		visited[cur]=1;
		s++;
		if(cur==b){cout<<s; return 0;}
	}
}