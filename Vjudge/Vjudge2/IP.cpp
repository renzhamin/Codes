#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int b2d(int n){
    int r,s=0;
    for(int i=0;n>0;i++){
        r=n%10;
        n/=10;
        s+=r*pow(2,i);
    }
}

int main(){
    printf("hello");
}
