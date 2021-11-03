#include<bits/stdc++.h>

using namespace std;

/// Typedef
typedef long long ll;

#define sc1(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld %lld",&a,&b)

int main() {

    ll tc, t = 1;

   // freopen("C:\\Users\\morol\\Desktop\\Clion\\input1.txt", "r", stdin);

    while (cin >> tc ) {
        ll arr[tc];

        vector <ll> vc;

        for (ll i = 0; i < tc; i++){
            sc1(arr[i]);
            vc.push_back(arr[i]);
        }


        ll tc2, num;
        sc1(tc2);
        for (ll i = 0; i < tc2; i++) {
            sc1(num);

            ll low = lower_bound(vc.begin(), vc.end(), num) - vc.begin();
            ll high = upper_bound(vc.begin(), vc.end(), num) - vc.begin();

            if(low == 0) cout << "X ";
            else cout << arr[low - 1] << " ";

            if(high == tc) cout << "X" << endl;
            else cout << arr[high] << endl;
        }


    }
    return 0;
}
