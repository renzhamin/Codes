#include <stdio.h>

void reverseDigits(int *a){
    int n=*a;
    *a=0;

    while(n > 0){
        *a *= 10;
        *a += n%10;
        n/=10;
    }
}

int main(){
    int arr[5]={12,23,45,23,54};

    for(int i=0;i<5;i++){
        reverseDigits(&arr[i]);
        printf("%d\n",arr[i]);
    }
}
