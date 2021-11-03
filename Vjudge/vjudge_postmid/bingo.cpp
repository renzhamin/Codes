#include <iostream>
#include <map>
using namespace std;
map<int,string>mat;
map<int,string>mark;
int main(){
	int i,j,tmp;
	string ind;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++){
			ind=to_string(i)+to_string(j);
			cin>>tmp;
			mat[tmp]=ind;
		}	
	int n,x;cin>>n;
	while(n--){
		cin>>tmp;
		auto x=mat.find(tmp);
		if(x!=mat.end())mark[tmp]=mat[tmp];
	}
	int r1=0,r2=0,r3=0,c1=0,c2=0,c3=0,d1=0,d2=0;
	for(auto it=mark.begin();it!=mark.end();it++){
		if(it->second=="11" || it->second=="12" || it->second=="13") r1++;if(it->second=="21" || it->second=="22" || it->second=="23") r2++;if(it->second=="31" || it->second=="32" || it->second=="33") r3++;
		if(it->second=="11" || it->second=="21" || it->second=="31") c1++;if(it->second=="12" || it->second=="22" || it->second=="32") c2++;if(it->second=="13" || it->second=="23" || it->second=="33") c3++;
		if(it->second=="11" || it->second=="22" || it->second=="33") d1++;if(it->second=="13" || it->second=="22" || it->second=="31") d2++;
	}
	if(r1==3 || r2==3 || r3==3 || c1==3 || c2==3 || c3==3 || d1==3 || d2==3)
		cout<<"Yes";else cout<<"No";

}wW