#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;cin>>n;
	string a = "I hate ";
	string b = "I love ";
	string c = "that ";
	if (n % 2 == 0)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			cout << a << c;
			if (i != n / 2)
				cout << b << c;
			else
				cout << b;
		}
		cout << "it";
	}
	else
	{
		for(int i=1;i<=n/2;i++){
			cout<<a<<c;
			cout<<b<<c;
		}
		cout<<a<<"it";
	}
}