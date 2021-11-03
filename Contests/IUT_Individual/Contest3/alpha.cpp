#include <iostream>
#include <cstdlib>
#include <set>

#define sc(a) scanf("%d",&a)


using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	int t,n,w,tmp,y; sc(t);
	for(int T=1;T<=t;T++){
		set<int>arr;
		sc(n); sc(w);
		int s=1;
		while(n--){
			sc(tmp);
			sc(y);
			arr.insert(y);
		}
		auto x=arr.begin();
		for(auto i=arr.begin();i!=arr.end();i++){
			y=(*x)+w;
			if(*i>y){
				x=i;
				s++;
			}
		}
		printf("Case %d: %d\n",T,s);
	}
}