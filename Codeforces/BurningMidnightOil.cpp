#include <iostream>
#define ll long long 
using namespace std;

ll v,k;

bool check(ll mid){
	ll l=mid,m=k;
	while(m<=mid){
		// cout<<"k="<<m<<" l="<<l<<" mid="<<mid<<"\n";
		l+=(mid/m);
		m*=k;
	}
	return l>=v;
}

ll bs(){
	ll low=1,high=v,mid;
	while(low<high){
		mid=(high+low)/2;
	// cout<<"low="<<low<<" high="<<high<<" mid="<<mid<<"\n";
		if(check(mid))
			high=mid;
		else
			low=mid+1;
	}
	return high;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	cin>>v>>k;
	cout<<bs()<<"\n";
}