#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct rec{
	double xmin,xmax,ymin,ymax;
};

bool in(rec &a,double x,double y){
	return (x>a.xmin && x<a.xmax && y>a.ymin && y<a.ymax);
}

int main(){
	//freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	char r;
	int n=0;
	vector<rec>arr;
	while(cin>>r && r!='*'){
		rec tmp;
		cin>>tmp.xmin>>tmp.ymax>>tmp.xmax>>tmp.ymin;
		arr.push_back(tmp); n++;
	}
	double x,y;
	int p=1,dumb;
	while(cin>>x>>y && (x!=9999.9 && y!=9999.9)){
		bool f=0;
		for(int i=0;i<n;++i){
			if(in(arr[i],x,y)){
				cout<<"Point "<<p<<" is contained in figure "<<i+1<<"\n";
				f=1;;
			}
		}
		if(!f)
			cout<<"Point "<<p<<" is not contained in any figure"<<"\n";
		p++;
	}
}