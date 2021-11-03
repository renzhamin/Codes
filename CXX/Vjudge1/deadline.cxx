#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	//	int t;cin>>t;
	//	while(t--){
	long int n;
	cin >> n;
	long int d;
	cin >> d;
	long int x, i;
	float x1;
	if (d <= n)
	{
		cout << "YES" << endl;
	}
	else
	{
		for (i = 1; i < n; i++)
		{
			x1 = ceil(d / (i + 1));
			x = i + x1;
		}
		/*	if(x<=n)
	  cout<<"YES"<<endl;
	else
	  cout<<"NO"<<endl;  */
	}
	cout << i;
	//	}
}