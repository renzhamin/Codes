#include <iostream>
#include <deque>
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	string com,s[4]={"pushLeft","pushRight","popLeft","popRight"};
	string r[6]={"Pushed in left: ","Pushed in right: ","Popped from left: ",
						"Popped from right: ","The queue is full","The queue is empty"};
	int t,n,m,T=0;cin>>t;
	while(t--){
		int size=0,tmp;
		deque<int>arr;
		cin>>n>>m;
		cout<<"Case "<<++T<<":\n";
		while(m--){
			cin>>com;
			if(com==s[0]){
				cin>>tmp;
				if(n>size){
					arr.push_front(tmp);
					cout<<r[0]<<tmp<<endl; size++;
				} else
					cout<<r[4]<<endl;
			} 
			else if(com==s[1]){
				cin>>tmp;
				if(n>size){
					arr.push_back(tmp);
					cout<<r[1]<<tmp<<endl; size++;
				} else
					cout<<r[4]<<endl;
			}
			else if(com==s[2]){
				if(size!=0){
					auto v=arr.begin();
					cout<<r[2]<<*v<<endl;
					arr.pop_front(); size--;
				} else
					cout<<r[5]<<endl;
			}
			else if(com==s[3]){
				if(size!=0){
					auto v=arr.rbegin();
					cout<<r[3]<<*v<<endl;
					arr.pop_back(); size--;
				} else
					cout<<r[5]<<endl;
			}
		}
	}
}