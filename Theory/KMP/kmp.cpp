#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string &text,string &pattern){
	
	int n=pattern.length(),l=text.length(),i=0,j=0,lps[n];
	lps[0]=0;
	vector<int>found;
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
			found.push_back(i-n);
			j=lps[j-1];
		}
	}

	return found;

}



