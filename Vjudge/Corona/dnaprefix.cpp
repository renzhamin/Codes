#include <iostream>
#include <cstdio>
#include <map>
#define si(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1,value,n;si(t);
	while(t--){
		map<string,int>sub;
		si(n);
		int ans=-1;
		while(n--){
			char s[55],tmp[55];
			ss(s);
			for(int i=0;s[i];i++){
				tmp[i]=s[i]; tmp[i+1]='\0';
				value=(++sub[tmp])*(i+1);
				ans=max(ans,value);
			}			
		}
		printf("Case %d: %d\n",T++,ans);
	}
}