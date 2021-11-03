#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int ar[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
		int a, b;
		cin >> a >> b;
		int c=a+b,s=0;
		while(c!=0){
			s+=ar[c%10];
			c/=10;
		}
		cout << s << endl;
	}
}
