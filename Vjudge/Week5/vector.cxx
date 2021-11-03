#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> vec;
	int i;
	for(i=1;i<=10;i++){
		vec.push_back(i);
	}
	for(i=0;i<vec.size();i++)
	    cout<<vec[i]<<endl;
}