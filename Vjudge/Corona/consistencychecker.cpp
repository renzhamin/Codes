#include <iostream>
#include <map>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	while(t--){
		map<string,int>track;
		bool no=0;
		int n;cin>>n;
		while(n--){
			string s,ch;cin>>s;
			//if(track[s]>0) no=1;
			if(!no){
				for(int i=0;i<s.length();i++){
					ch+=s[i];
					if(track[ch]) no=1; else track[ch]++;
				}
			}
		}
		cout<<"Case "<<T++<<": ";
		if(no)
			cout<<"NO"<<endl; 
		else
			cout<<"YES"<<endl;
	}
}