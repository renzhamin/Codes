#include <iostream>
#include <set>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	set<int>st;
	int n,k,c=0;
	cin>>n>>k;
	int tmp,start=0,end=0,mx=0;
	bool f=1;
	for(int i=0;i<n;++i){
		cin>>tmp;
		if(st.find(tmp)==st.end()){
			st.insert(tmp);
			c++;
			if(f) start=i+1,f=0;
		} else {
			st.clear();
			end=i+1;
			f=1;
			c=0;
		}
	}
	cout<<start<<" "<<end<<"\n";
}