#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pmalloc(x) (struct x*)malloc(sizeof(struct x))

#include "task1_structure.c"
#include "insert.c"
#include "delete.c"
#include "printing.c"

int main(){
    root=pmalloc(Clubs);
    int done=0;
    
    while(!done){
        int c=choice();
        if(c==1) insert_club();
        else if(c==2) del_club();
        else if(c==3) showAll();
        else done=1;
    }
}