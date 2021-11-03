#include <iostream>
#define done return 0;
using namespace std;
int main(){
	freopen("Input.txt","r",stdin); freopen("Output.txt","w",stdout);
	long long o4,o7,o47,o74,e4,e7;
	cin>>o4>>o7>>o47>>o74;
	string s,s2;
	if(o47==0 && o74==0){
		s=string(o4,'4')+string(o7,'7');
		cout<<s<<endl;
		done;
	} 

	if(o74>o47){
		if(o4<o74 || o7<o74){
			cout<<-1; done;
		}
		e4=o4-o74; e7=o7-o74;
		
		if(e7>0) s+=string(e7,'7'); 

		if(o74-o47==1){
			for(int i=0;i<o74;i++) s+="74";
		} else{
			cout<<-1;done;
		}
		if(e4>0) s+=string(e4,'4');
		cout<<s<<endl;
		done;
	} else
	if(o47>o74){
		if(o4<o47 || o7<o47){
			cout<<-1; done;
		}
		e4=o4-o47; e7=o7-o47;

		if(e4>0){
			s=string(e4,'4');
		}
		if(o47-o74==1) for(int i=0;i<o47;i++) s+="47";
		else {
			cout<<-1; done;
		}

		if(e7>0) s+=string(e7,'7');
		cout<<s<<endl;
		done
	} else {

		e4=o4-o47; e7=o7-o74;

		if(o4<o47 || o7<o47){
			cout<<-1; done;
		}

		if(o4==o7){
			cout<<-1;done;
		}
		if(o4>o7){
			if(e7>0){cout<<-1;done;}
			e4--;
			if(e4>0) s+=string(e4,'4');
			for(int i=0;i<o47;i++) s+="47";
			s+='4';
		} else
		if(o7>o4){
			if(e4>0){cout<<-1;done;}
			for(int i=0;i<o47;i++) s+="74";
			s+='7';		
			e7--;	
			if(e7>0) s+=string(e7,'7');
		}
		cout<<s<<endl;
	}
}