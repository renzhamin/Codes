#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int at=30;

string process(string line,int pos){
    int extra=0;
    for(int i=0;i<line.size();i++){
        if(isalpha(line[i])){
            extra=i; break;
        }
    }
    string ans=line.substr(0,pos);
    for(int i=pos;i<=at+extra;i++)
        ans += " ";
    ans += "= ";
    for(int i=pos+1;i<line.size();i++)
        ans += line[i];
    return ans;
}

int main(int argc,char **argv){
    if(argc<2) {
        cout<<"no input file"<<"\n";
        return 0;
    }
    if(argc>2){
        at = stoi(argv[2]);
    }
    fstream file(argv[1]);
    string line;
    int ind;
    while(getline(file,line)){
        ind = line.find('=');
        if(ind!=-1){
            cout<<process(line,ind)<<"\n";
        } else {
            cout<<line<<"\n";
        }
    }
}
