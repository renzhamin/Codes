#include <iostream>
using namespace std;
int freq[26];

int id(char x){
	return x-'a';
}

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,k,x,ind,sub,i;cin>>t;
	while(t--){
		string s;
		cin>>s>>k>>x;
		i=0,sub=0;
		for(i=0;i<s.length();i++) {
			ind=id(s[i]);
			if(++freq[ind]>x){
				k--	;
				if(k<0){
					break;
				} else {
					freq[ind]--;
					sub++;
				}
			}
		}
		cout<<i-sub<<endl;
		for(int i=0;i<26;i++) freq[i]=0;
	}
}