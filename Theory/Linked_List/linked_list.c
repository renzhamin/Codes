#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    int value;
}*root;

int list_size=1;

void insert(int index,int value){
    if(index>list_size) {
        printf("Index Out of Bounds\n");
        return;
    }
    struct node *cur=root,*prev;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->value=value;
    while(cur && index--) {
        prev=cur;
        cur=cur->next;
    }
    list_size++;
    prev->next=tmp;
    tmp->next=cur;
}

void showAll(){
    struct node *cur=root;
    if(!cur->next) printf("List Empty");
    while(cur=cur->next) printf("%d ",cur->value);
    printf("\n");
}

void del(int index){
    if(index>=list_size) {
        printf("Index Out of Bounds\n");
        return;
    }

    struct node *cur=root,*prev;        
    while(cur && index--) {
        prev=cur;
        cur=cur->next;
    }

    list_size--;
    prev->next=cur->next;
    free(cur);
}



int main(){
    root=(struct node*)malloc(sizeof(struct node*));
    int n,value,index;
    char type;
    scanf("%d\n",&n);
    while(n--){
        scanf("%c %d %d\n",&type,&index,&value);
        if(type=='I')
            insert(index,value);
        else if(type=='D')
            del(index);
        else
            showAll();
    }
}