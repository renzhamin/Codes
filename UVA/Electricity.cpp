#include <iostream>
using namespace std;
struct con{
	long long c,d,m,y;
};

bool leap(long long n){
	return ((!(n%4)&&(n%100)) || !(n%400));
}

int main(){
	// freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int n;
	long long month[]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(cin>>n && n){
		con arr[n+1];
		for(int i=0;i<n;i++) cin>>arr[i].d>>arr[i].m>>arr[i].y>>arr[i].c;
		long long cnt=0,y,m,d,md,dif,c=0;
		bool sy=0,sm=0;
		for(int i=0;i<n-1;++i,sy=0,sm=0){
			y=arr[i].y,m=arr[i].m,d=arr[i].d,md=month[arr[i].m-1];
			if(m==2 && leap(y)) md++;
			sy=arr[i+1].y==y; sm=arr[i+1].m==m;
			if((sy&&arr[i+1].m-m==1) || (m==12&&arr[i+1].m==1&&arr[i+1].y-y==1)){
				if(d==md && arr[i+1].d==1)
					cnt++,c+=(arr[i+1].c-arr[i].c); 
				continue;
			}
			dif=arr[i+1].d-d;
			if(dif==1 && sy && sm) cnt++,c+=(arr[i+1].c-arr[i].c);
		}
		cout<<cnt<<" "<<c<<"\n";
	}
}