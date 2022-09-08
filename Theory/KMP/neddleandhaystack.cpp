#include <iostream>
#include <vector>
using namespace std;


vector<int> kmp(string &text,string &pattern){
	
	int n=pattern.length(),l=text.length(),i=0,j,lps[n];
	lps[0]=0;
	vector<int>found;
	
	for(j=1;j<n;){
		if(pattern[i]==pattern[j]) lps[j]=i+1,i++,j++;
		else {
			if(i) i=lps[i-1];
			else lps[j]=0,j++;
		}
	}

	i=0,j=0;
	while(i<l){
		if(pattern[j]==text[i])
			i++,j++;
		else {
			if(j) j=lps[j-1];
			else i++;
		}
		if(j==n){
			found.push_back(i-n);
			j=lps[j-1];
		}
	}

	return found;

}






int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;
	string text,pattern;
	
	while(cin>>n>>pattern>>text){
		vector<int>arr=kmp(text,pattern);
		for(auto i:arr) cout<<i<<endl;
		if(arr.empty()) cout<<endl;
	}	

}