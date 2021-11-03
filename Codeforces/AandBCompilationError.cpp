#include <iostream>
#include <set>
using namespace std;
multiset<string>m1,m2,m3;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	string tmp,x[2];	
	for(int i=0;i<n;i++){ cin>>tmp; m1.insert(tmp); }
	for(int i=0;i<n-1;i++) { cin>>tmp; m2.insert(tmp); }
	for(int i=0;i<n-2;i++) { cin>>tmp; m3.insert(tmp); }

	auto i=m1.begin(),j=m2.begin(),k=m3.begin();
	bool done=0;
	
	for(;j!=m2.end();i++)
		if((*i)!=(*j)){ x[0]=*i; done=1; break;}
		else j++;
	if(!done) x[0]=*i;

	done=0;

	for(i=m2.begin();k!=m3.end();i++)
		if((*i)!=(*k)) {x[1]=*i;done=1; break;}
		else k++;
	if(!done) x[1]=*i;

	cout<<x[0]<<endl<<x[1]<<endl;
}