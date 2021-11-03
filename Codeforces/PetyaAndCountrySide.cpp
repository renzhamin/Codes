#include <bits/stdc++.h>
#define mx 100000
#define ll long long 
using namespace std;

ll n,Left[mx],Right[mx],ind[mx],arr[mx],ans=0;
stack<ll>st1,st2;

void compute(int i,ll *cango,stack<ll>&st){
	while(!st.empty() && arr[i]>=st.top()){
		cango[i]+=ind[st.top()];
		st.pop();
	}
	while(!st.empty() && arr[i]<st.top()) st.pop();
	cango[i]++;
	ind[arr[i]]=cango[i];
	st.push(arr[i]);
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) compute(i,Left,st1);
	memset(ind,0,sizeof(n+1)*sizeof(ll));
	for(int i=n-1;i>=0;i--) compute(i,Right,st2);
	for(int i=0;i<n;i++) ans=max(ans,Left[i]+Right[i]-1);
	cout<<ans<<"\n";
}