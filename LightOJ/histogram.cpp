#include <iostream>
#include <stack>
#include <string.h>
#include <utility>
using namespace std;
const int mx=30000;
int arr[mx],c1[mx],c2[mx],ind[mx],ans;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,x,T=1;cin>>t;
	while(t--){
		stack<int>st,st2;
		cin>>n;
		memset(ind,0,n*sizeof(int));
		memset(c1,0,n*sizeof(int));
		memset(c2,0,n*sizeof(int));
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=0;i<n;i++){
		//left to right//
			while(!(st.empty()) && st.top()>=arr[i]) {
				c1[i]+=ind[st.top()];
				st.pop();
			}
			c1[i]++;
			st.push(arr[i]);
			ind[st.top()]=c1[i];
		}
		//-------------------------------//
		//right to left

		for(int i=n-1;i>=0;i--){
			while(!(st2.empty()) && st2.top()>=arr[i]) {
				c2[i]+=ind[st2.top()];
				st2.pop();
			}
			c2[i]++;
			st2.push(arr[i]);
			ind[st2.top()]=c2[i];			
		}
		//-------------------------------//
		ans=-1;
		for(int i=0;i<n;i++){
			ans=max((c1[i]+c2[i]-1)*arr[i],ans);
		}
		cout<<"Case "<<T++<<": ";
		cout<<ans<<endl;
	}
}