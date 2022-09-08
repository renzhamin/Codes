#include <iostream>
using namespace std;
struct rec{
	int xmin,xmax,ymin,ymax;
};
int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string no="No Overlap";
	int t,x1,x2,y1,y2,area;cin>>t;
	while(t--){
		rec a,b;
		cin>>a.xmin>>a.ymin>>a.xmax>>a.ymax;
		cin>>b.xmin>>b.ymin>>b.xmax>>b.ymax;
		x1=max(a.xmin,b.xmin),x2=min(a.xmax,b.xmax);
		y1=max(a.ymin,b.ymin),y2=min(a.ymax,b.ymax);
		area=(y2-y1)*(x2-x1);
		if(area<=0){
			cout<<no<<"\n";
			cout<<t?"\n":"";
			continue;
		}
		cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
		cout<<t?"\n":"";
	}
}

/*
1
0 0 10 10
10 0 15 15
*/