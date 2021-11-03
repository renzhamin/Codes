#include <iostream>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long left,right,down,up,maxl,maxr,maxu,maxd,x,y,tmp,move,d;
	int testCase;cin>>testCase;
	while(testCase--){
		bool f=1;
		cin>>left>>right>>down>>up>>x>>y>>maxl>>maxd>>maxr>>maxu;
		tmp=left-right;
		if(tmp>0){ 
			if(x-tmp<(maxl))
				f=0 ;

		} else if(tmp<0) {
			d=abs(tmp);
			if(x+d>maxr)
				f=0;
		}

		if(tmp==0){		
			if(maxl==maxr && (right || left))
				f=0;
		}


		tmp=down-up;
		if(tmp>0){ 
			if(y-tmp<(maxd))	
				f=0 ;
		} else if(tmp<0) {
			d=abs(tmp);
			if(y+d>maxu)
				f=0;
		}

		if(tmp==0){
			if(maxu==maxd && (down || up))
				f=0;
		}

		if(f)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
