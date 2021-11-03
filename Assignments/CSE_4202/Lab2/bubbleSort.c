#include <stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


int bubblesort(int *start,int *end){
    int swaped=0; 
    for(int *i=start;i<end;i++){
        for(int *j=i+1;j<end;j++){
            if(*i>*j){
                swap(i,j);
                swaped++;
            }
        }
    }
    return swaped;
}
