#include <iostream>
using namespace std;

int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t;cin>>t;
	for(int T=1;T<=t;T++){
		string s[100],res[100]; s[0]="http://www.lightoj.com/";
		int page=0,r=0,l_page=0; string com;
		while(cin>>com && com!="QUIT"){
			if(com=="VISIT"){
				cin>>s[++page];
				res[r++]=s[page];
				l_page=page;
			} else if(com=="BACK"){
				if(page-1<0)
					res[r++]="Ignored";
				else
					res[r++]=s[--page];
			} else if(com=="FORWARD"){
				if(page+1>l_page)
					res[r++]="Ignored";
				else
					res[r++]=s[++page];
			}
		}
		cout<<"Case "<<T<<":\n";
		for(int i=0;i<r;i++)
			cout<<res[i]<<endl;

	}
}