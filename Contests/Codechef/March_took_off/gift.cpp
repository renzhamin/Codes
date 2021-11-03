#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		long n;cin>>n;
		char s[n+10];
		cin>>s;
		int x=0,y=0,j=0;
		for(int i=0;i<n;i++){
			if(s[i]=='L'){
				x--;
				for(j=i+1;j<n;j++){
					if(s[j]=='L' || s[j]=='R')
						i++;
					else
						break;
				}
			}
			else if(s[i]=='R'){
				x++;
				for(j=i+1;j<n;j++){
					if(s[j]=='L' || s[j]=='R')
						i++;
					else
						break;
				}
			}
			else if(s[i]=='U'){
				y++;	
				for(j=i+1;j<n;j++){
					if(s[j]=='U' || s[j]=='D')
						i++;
					else
						break;
				}
			}
			else if(s[i]=='D'){
				y--;
				for(j=i+1;j<n;j++){
					if(s[j]=='U' || s[j]=='D')
						i++;
					else
						break;
				}
			}
			if(i>=(n-1)) break;
			//cout<<"i="<<i<<" s[i]="<<s[i]<<endl;
		}
		cout<<x<<" "<<y<<endl;
	}
}