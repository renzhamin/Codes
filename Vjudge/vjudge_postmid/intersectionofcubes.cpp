#include <iostream>
using namespace std;
int main(){
	int t;cin>>t;for(int k=1;k<=t;k++){
		int n;cin>>n;
		int x1,x2,y1,y2,z1,z2;
		x1=y1=z1=0;x2=y2=z2=1000;
		int x,y,z,tmp;
		while(n--){
			for(int i=0;i<6;i++){
				if(i==0) {cin>>tmp;x1=max(x1,tmp);}
				else if(i==1) {cin>>tmp;y1=max(y1,tmp);}
				else if(i==2) {cin>>tmp;z1=max(z1,tmp);}
				else if(i==3) {cin>>tmp;x2=min(x2,tmp);}
				else if(i==4) {cin>>tmp;y2=min(y2,tmp);}
				else if(i==5) {cin>>tmp;z2=min(z2,tmp);}
			}
		}
		
		x=x2-x1;y=y2-y1;z=z2-z1;
		if(x<0 || y<0 || z<0) cout<<"Case "<<k<<": "<<0<<endl;
		else cout<<"Case "<<k<<": "<<x*y*z<<endl;
	}
}