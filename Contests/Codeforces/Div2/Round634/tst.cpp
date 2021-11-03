#include <iostream>
#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main(){
	long long LIFE,VOIDAB,LIGHT;
	int t;cin>>t;
	while(t--){
		cin>>LIFE>>VOIDAB>>LIGHT;
		while(LIFE>18 && VOIDAB){
			LIFE/=2;
			LIFE+=10;
			VOIDAB--;
		}
		while(LIFE && LIGHT){
			LIFE-=10;
			LIGHT--;
		}
		LIFE<=0?
			printf("YES\n"):
			printf("NO\n");
	}
}