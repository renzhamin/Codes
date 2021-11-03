#include <iostream>
using namespace std;
int main(){
    int n,a,b,c,t1,t2,st,en,len,ans;
    cin>>n>>a>>b>>c>>t1>>t2;
    cin>>st>>en;
    ans=(en-st)*a;
    len=en;
    while(--n){
    	cin>>st>>en;
    	if(st-len>t1){
    		ans+=t1*a;
    		len+=t1;
    		if(st-len>t2){
    			len+=t2;
    			ans+=((t2*b)+(st-len)*c);
    		} else
    		    ans+=(st-len)*b;
    	} else
    	   ans+=(st-len)*a;
    	ans+=(en-st)*a;
    	len=en; 
    }
    cout<<ans<<endl;
}