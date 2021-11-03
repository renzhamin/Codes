#include <iostream>
using namespace std;


int kmp(string &text,string &pattern){
	
	int n=pattern.length(),l=text.length(),i=0,j=0,lps[n],s=0;
	lps[0]=0;
	//i-----j//
	for(j=1;j<n;){
		if(pattern[i]==pattern[j]) lps[j]=i+1,i++,j++;
		else {
			if(i) i=lps[i-1];
			else lps[j]=0,j++;
		}
	}
	//j---------i//
	i=0,j=0;
	while(i<l){
		if(pattern[j]==text[i])
			i++,j++;
		else {
			if(j) j=lps[j-1];
			else i++;
		}
		if(j==n){
			j=lps[j-1];
			s++;
		}
	}

	return s;

}





int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,T=1;cin>>t;
	string a,b;
	while(t--){
		cin>>a>>b;
		cout<<"Case "<<T++<<": ";
		cout<<kmp(a,b)<<endl;
	}
}