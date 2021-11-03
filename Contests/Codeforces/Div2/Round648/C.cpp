#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	#ifdef localhost
		freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	#endif
	
	ll n;cin>>n;
	int a[n+1],b[n+1];
	int d1[n+1]{},d2[n+1]{};
	int tmp;

	for(int i=1;i<=n;i++) {
		cin>>tmp;
		a[tmp]=i;
	}  
	for(int i=1;i<=n;i++) {
		cin>>tmp;
		b[tmp]=i;
	}  

	for(int i=1;i<=n;++i){
		int i1=a[i];
		int i2=b[i];
		if(i2>=i1){
			d1[i2-i1]++;
		} else {
			d1[n-i1+i2]++;
		}
	}
	int s1=*max_element(d1,d1+n);

	for(int i=1;i<=n;++i){
		int i1=a[i];
		int i2=b[i];
		if(i1<=i2){
			d2[i2-i1]++;
		} else {
			d2[i1+n-i2]++;
		}
	}

	int s2=*max_element(d2,d2+n);

	cout<<max(s1,s2)<<"\n";


}