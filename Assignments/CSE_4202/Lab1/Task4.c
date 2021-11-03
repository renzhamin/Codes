#include <stdio.h>

int main(){
    char tmp[10];
    int n;
    scanf("%d",&n);
    int A=0,S=0;
    for(int i=0;i<n;i++){
        scanf("%s",tmp);
        if(tmp[0]=='A') A++;
        else S++;
    } 
    if(A>S)
        printf("Adham\n");
    else if(A<S)
        printf("Sartaj\n");
    else
        printf("No imposter\n");
}