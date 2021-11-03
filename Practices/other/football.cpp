#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int m,g;
	cin>>m>>g;
	int d[m],team,opp;
	for(int i=0;i<m;i++) {
		cin>>team>>opp;
			d[i]=opp-team;
	}
	sort(d,d+m);
	int s=0;
	for(int i=0;i<m && g>=0;i++){
		//cout<<"d["<<i<<"]="<<d[i]<<" ";
		if(d[i]<0) 
			s+=3;
		else {
			if(d[i]+1<=g)
				g-=(d[i]+1),s+=3;
			else if(d[i]==g)
				g-=d[i],s++;
		} 
		//cout<<"g="<<g<<" "<<"s="<<s<<endl;
	}
	cout<<s<<endl;
}