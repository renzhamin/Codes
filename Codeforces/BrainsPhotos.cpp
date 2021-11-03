#include <iostream>
using namespace std;
int main(){
	string c="CMY";
	char tmp;bool f=0;
	int row,col;cin>>row>>col;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++){
			cin>>tmp;
			for(int k=0;k<3;k++)
				if(c[k]==tmp){
					f=1;
				}
		}
	
	if(f) 
		cout<<"#Color"; 
	else 
		cout<<"#Black&White";

}