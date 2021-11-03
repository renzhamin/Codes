#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,r,c,T=1;cin>>t;
	while(t--){
		cin>>r>>c;
		int s=0,tmp,sum=0;
		for(int i=0;i<r;i++){
			sum=0;
			for(int j=0;j<c;j++){
				cin>>tmp;
				sum+=tmp;
			}
			s=s^sum;
		}
		cout<<"Case "<<T++<<": ";
		if(s) 
			cout<<"Alice\n"; 
		else
			cout<<"Bob\n";
	}

}