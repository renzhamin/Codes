#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
#define base 1000000007LL
#define mod 2096725343LL
char str[100005];
typedef long long ll;
int main() {
   while (scanf("%s\n",str)) {
        int n = strlen(str);
        int l = n - 1;
        ll h1 = 0;
        ll h2 = 0;
        ll cbase = 1;
        int best = 0;
        for (int j = l; j >= 0; j--) {
            h2 = (h2 * base + str[j]) % mod;
            h1 = (h1 + str[j] * cbase) % mod;
            if (h1 == h2)
                best = n - j;
            cbase = (cbase * base) % mod;
        }
        for (int i = 0; i < n; i++)
            putchar(str[i]);
        for (int i = (n - best) - 1; i >= 0; i--)
            putchar(str[i]);
        putchar('\n');
    }
    return 0;
}
