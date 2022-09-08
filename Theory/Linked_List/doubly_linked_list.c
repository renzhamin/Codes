#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next,*prev;
    int value;
}*root,*end;

int list_size=1;


void showAll(){
    struct node *cur=root->next;
    if(cur==end) printf("List Empty");
    while(cur!=end){
        printf("%d ",cur->value);
        cur=cur->next;
    }
    printf("\n");
}

void showAll_reverse(){
    struct node *cur=end->prev;
    if(cur==root) printf("List Empty");
    while(cur!=root){
        printf("%d ",cur->value);
        cur=cur->prev;
    }
    printf("\n");
}



void insert_front(int index,int value){
    if(index>list_size) {
        printf("Index Out of Bounds\n");
        return;
    }
    list_size++;
    struct node *cur=root,*prevNode;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->value=value;
    while(index--) {
        cur=cur->next;
    }
    prevNode=cur->prev;
    prevNode->next=tmp;
    tmp->next=cur;
    tmp->prev=prevNode;
    cur->prev=tmp;
}

void insert_back(int index,int value){
    if(index>list_size) {
        printf("Index Out of Bounds\n");
        return;
    }
    list_size++;
    struct node *cur=end,*prevNode;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->value=value;
    while(index--) {
        cur=cur->prev;
    }
    prevNode=cur->next;
    prevNode->prev=tmp;
    tmp->prev=cur;
    tmp->next=prevNode;
    cur->next=tmp;
}


void del_front(int index){
    if(index>=list_size) {
        printf("Index %d Out of Bounds\n",index);
        return;
    }
    struct node *cur=root,*prevNode;        
    list_size--;
    while(index--) {
        cur=cur->next;
    }

    prevNode=cur->prev;
    prevNode->next=cur->next;
    cur->next->prev=prevNode;
    free(cur);
}

void del_back(int index){
    struct node *cur=end,*prevNode;        
    if(index>=list_size) {
        printf("Index %d Out of Bounds\n",index);
        return;
    }
    list_size--;
    while(index--) {
        cur=cur->prev;
    }

    prevNode=cur->next;
    prevNode->prev=cur->prev;
    cur->prev->next=prevNode;
    free(cur);
}


int main(){
    root=(struct node*)malloc(sizeof(struct node*));
    end=(struct node*)malloc(sizeof(struct node));
    root->next=end;
    end->prev=root;
    insert_front(1,1);
    insert_front(1,2);
    insert_front(1,3);
    del_front(1);
    showAll();
}


void menu(){

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
