#include <iostream>
using namespace std;

long long a,b,b1,b2,big,small,s1,s2,ans1=0,ans2=0,ans3=0;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		cin>>a>>b;
		big=max(a,b); small=min(a,b);
		b1=big/10,b2=big%10,s1=small/10,s2=small%10;
		ans1=b1*10+s2+b2*10+s1;
		ans3=s2*10+b2+s1*10+b1;
		if(small<10)
			ans1=ans1%10*10+ans1/10;
		if(a<10 && b<10)
			ans1=0;
		ans2=(a+b);
		ans3=max(ans1,max(ans3,ans2));
		cout<<ans3<<endl;
	}
}