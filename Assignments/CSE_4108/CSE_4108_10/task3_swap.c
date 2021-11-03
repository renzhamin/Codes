#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pmalloc(x) (struct x*)malloc(sizeof(struct x))

#include "task1_structure.c"
#include "swap.c" 
#include "insert.c"
#include "delete.c"
#include "printing.c"

int main(){
    root=pmalloc(Clubs);
    int c,done=0;
    
    while(!done){
        c=choice();
        if(c==1) insert_club();
        else if(c==2) del_club();
        else if(c==3) showAll();
        else if(c==4) swap();
        else done=1;
    }
}




