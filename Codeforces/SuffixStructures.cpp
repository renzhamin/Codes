#include <bits/stdc++.h>
#define done(x) {cout<<x<<"\n";return 0;} 
#define ll long long 
using namespace std;

int sh[140],th[140];
string a[]={"automaton","array","both","need tree"};

int main(){
	string s,t;
	cin>>s>>t;

	int ns=s.length(),nt=t.length();


	if(ns<nt) done(a[3])

	for(int i=0;i<ns;++i){
		if(i<nt) th[t[i]]++;
		sh[s[i]]++;
	}

	int j=0;
	for(int i=0;i<ns&&j<nt;++i){
		if(s[i]==t[j]) j++;
	}

	if(j==nt) done(a[0])

	bool array=1;
	for(int i=0;i<nt&&array;i++) 
		if(sh[t[i]]<th[t[i]]) array=0;

	if(!array) done(a[3])

	if(ns==nt) done(a[1])

	done(a[2])

}