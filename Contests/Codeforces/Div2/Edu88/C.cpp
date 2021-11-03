#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define done(x) {cout<<x<<"\n";continue;}  
using namespace std;

ld foo(ld h,ld c,ld t){
	return (t-c)/(2.0*t-h-c);
}

ld cav(ld h,ld c,ld x){
	return (h*x+c*(x-1.0))/(2.0*x-1.0);
}

int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	int tc;cin>>tc;
	while(tc--){
		ld h,c,t;
		cin>>h>>c>>t;
		
		if(t>=h) done(1)

		bool col= (h+c)/2.0 >= t;
		if(col) 
			done(2)

		ld a1=foo(h,c,t);
		
		ld ans1=floor(a1);
		ld ans2=ceil(a1);

		ld av1=cav(h,c,ans1);
		ld av2=cav(h,c,ans2);

		ld dif1=fabs(t-av1);
		ld dif2=fabs(t-av2);
		

		ans1*=2;ans1--;  ans2*=2;ans2--;

		(dif1<=dif2)?cout<<(ll)ans1<<"\n":cout<<(ll)ans2<<"\n";
	}

}