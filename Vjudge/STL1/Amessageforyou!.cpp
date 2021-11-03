#include <iostream>
using namespace std;
int k,arr[13],nxt,i,j,index;
string team;
int main(){
	freopen("Input.txt","r",stdin);
	freopen("Output.txt","w",stdout);
	int t;cin>>t;while(t--){
		nxt=-1;
		cin>>k>>team;
		for(i=0;i<13;i++) cin>>arr[i];
		for(i=0;i<13;i++){
			for(j=0;j<k;j++)
				if(team[j]==('A'+i))
					break;
			if(j==k && arr[i]>nxt){
				nxt=arr[i];
				index=i;
			}
		}
		cout<<(char)('A'+index)<<endl;
	}
}