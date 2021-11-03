e#include <iostream>
using namespace std;

long add(long a,long b,long dif){
	if(dif==0) return 0;
	if(dif&1) return 1;
	else return 2;
}

long sub(long a,long b,long dif){
	if(dif==0) return 0;
	if(!(dif&1)) return 1;
	else return 2;
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	long a,b,r,ans=0;
	while(t--){
		cin>>a>>b;
		r=b-a;
		if(r>0)
			ans=add(a,b,r);
		else 
			ans=sub(a,b,abs(r));
		cout<<ans<<endl;
	}
}