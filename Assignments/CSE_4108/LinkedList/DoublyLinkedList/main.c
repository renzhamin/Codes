
struct node{
    struct node *next,*prev;
    int value;
}*root,*end;

int list_size=0;

#include <stdio.h>
#include <stdlib.h>
#include "insertion.c"
#include "deletion.c"
#include "printing.c"

int main(){
    root=(struct node*)malloc(sizeof(struct node*));
    end=(struct node*)malloc(sizeof(struct node));
    root->next=end;
    end->prev=root;

    int n,value,index;
    char type;
    scanf("%d\n",&n);
    
    while(n--){
        scanf("%c %d %d\n",&type,&index,&value);
        switch(type){
            case 'I':{
                insert_front(index,value); 
                break;
            };
            case 'B':{
                insert_back(index,value); 
                break;
            };
            case 'D':{
                del_front(index); 
                break;
            };
            case 'F':{
                del_back(index);
                break;
            };
            case 'P':{
                showAll();
                break;
            };
            case 'R':{
                showAll_reverse();
                break;
            };
            default:{
                printf("Wrong Command Letter\n");
            }
        }
    }

}


/*

13
I 1 2
I 2 5
P
R
B 1 3
B 2 7
P
F 1
R
I 5 9
P
D 3
R

Output:
2 5 
5 2 
2 5 7 3 
7 5 2 
Index 5 Out of Bounds
2 5 7 
5 2

*/