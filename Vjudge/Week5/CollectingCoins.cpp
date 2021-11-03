#include<iostream>
using namespace std;

int main()
{
    int t,a,b,c,n,s;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>n;
        s=a+b+c+n;
    	cout<<(s%3!=0||a>s/3||b>s/3||c>s/3?"NO":"YES")<<endl;
    }
}
