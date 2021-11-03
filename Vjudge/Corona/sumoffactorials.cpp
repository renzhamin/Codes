#include <iostream>
#include <deque>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	unsigned long long fact[21];
	fact[0]=1;
	for(int i=1;i<=20;i++)
		fact[i]=i*fact[i-1];
	int t,T=0;cin>>t;
	while(t--){
		unsigned long long n; cin>>n;
		deque<int>s;
		for(int i=20;i>=0;i--)
			if(fact[i]<=n)
				n-=fact[i],s.push_front(i);
		cout<<"Case "<<++T<<": ";
		
		if(n==0) {
			for(int i=0;i<s.size()-1;i++)
				cout<<s[i]<<"!+";
			cout<<s[s.size()-1]<<"!"<<endl;
		} else 
			cout<<"impossible"<<endl;

	}
}