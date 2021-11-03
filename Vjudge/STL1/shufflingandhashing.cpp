#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  freopen("Input.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin >>t;
  while (t--) {
    bool flag = 0;
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    for (int i = 0 ; i < t.size(); i++) {
      string x = t.substr(i, s.size());
      sort(x.begin(), x.end());
      if (x == s)
        flag = 1;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
}







