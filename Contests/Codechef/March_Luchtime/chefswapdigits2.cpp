#include <iostream>
#include <algorithm>
using namespace std;


int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		long long a,b,b1,b2,big,small,s1,s2,ans1=0,ans2=0,ans3=0,ans4=0,ans=0;
		cin>>a>>b;
		big=max(a,b); small=min(a,b);
		b1=big/10,b2=big%10,s1=small/10,s2=small%10;
			
		
		if(small<10 && big>9){
			s1=small;

			swap(b1,s1);
			ans1=b1*10+b2+s1;
			swap(b1,s1);
			
			swap(b2,s1);
			ans2=b1*10+b2+s1;
			swap(b2,s1);

			ans=max({ans1,ans2,a+b});
		
		} else
		
		if(a>9 && b>9){

			swap(b2,s1);
			ans1=b1*10+b2+s1*10+s2;
			swap(b2,s1);

			swap(b1,s2);
			ans2=b1*10+b2+s1*10+s2;
			swap(b1,s2);

			swap(b2,s2);
			ans3=b1*10+b2+s1*10+s2;
			swap(b2,s2);

			swap(b1,s1);
			ans4=b1*10+b2+s1*10+s2;
			swap(b1,s1);

			ans=max({ans1,ans2,ans3,ans4,a+b});

		} else
		
		if(a<10 && b<10)
			ans=a+b;

		cout<<ans<<endl;

	}
}