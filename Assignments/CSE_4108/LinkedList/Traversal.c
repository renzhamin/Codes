#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    int value;
}*root;

void insert(int value){
    struct node *cur=root;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->value=value;
    while(cur->next) cur=cur->next;
    cur->next=tmp;
}

void showAll(){
    struct node *cur=root;
    if(!cur->next) printf("List Empty");
    while(cur=cur->next) printf("%d ",cur->value);
    printf("\n");
}

int main(){
    root=(struct node*)malloc(sizeof(struct node*));
    int n,value;
    char type[2];
    scanf("%d",&n);
    while(n--){
        scanf("%s",type);
        if(type[0]=='I'){
            scanf("%d\n",&value);
            insert(value);
        } else showAll();
    }
}