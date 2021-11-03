#include <iostream>
#include <vector>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long t,T=1;cin>>t;
	while(t--){
		vector<long long>arr;
		long long y;cin>>y;
		long double test,ty;
		long long x;
		ty=y;
		x=(10*y)/9;
		// test=x+1;
		// if((9*test)/10>(ty-1.0)) arr.push_back(test);
		arr.push_back(x);
		while(1){
			x--;
			if((long double)(9*x)/10>(long double)(y-1))
				arr.push_back(x);
			else
				break;
		}

		cout<<"Case "<<T++<<": ";

		for(auto i=arr.rbegin();i!=arr.rend();i++)
			cout<<*i<<" ";
		cout<<endl;


	}
}