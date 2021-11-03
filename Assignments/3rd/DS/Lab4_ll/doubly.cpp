#include <bits/stdc++.h>
using namespace std;

struct Node{
    struct Node *next,*prev;
    int value;
    Node(){
        next = NULL;
        prev = NULL;
    }
    Node(int key){
        value = key;
        next = NULL;
        prev = NULL;
    }

}*head,*tail;

int list_size=1;


void showAll(){
    struct Node *cur=head->next;
    if(cur==tail) printf("List Empty");
    while(cur!=tail){
        printf("%d ",cur->value);
        cur=cur->next;
    }
    printf("\n");
}

void showAll_reverse(){
    struct Node *cur=tail->prev;
    if(cur==head) printf("List Empty");
    while(cur!=head){
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
    struct Node *cur=head,*prevNode;
    struct Node *tmp=new Node(value);

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
    struct Node *cur=tail,*prevNode;
    struct Node *tmp=new Node(value);

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
    struct Node *cur=head,*prevNode;        
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
    struct Node *cur=tail,*prevNode;        
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

void insert_after_node(int key,int value){
    if(list_size==1) {
        printf("No nodes in the list");
        return;
    }
    list_size++;
    struct Node *cur=head->next,*prevNode;
    bool found=0;
    while(cur!=tail && cur->value!=key) {
        cur=cur->next;
    }
    
    if(cur==tail){
        printf("Node not found\n");
        return;
    }

    cur = cur->next;

    struct Node *tmp=new Node(value);
    prevNode=cur->prev;
    prevNode->next=tmp;
    tmp->next=cur;
    tmp->prev=prevNode;
    cur->prev=tmp;
}

void update_node(int key,int value){
    if(list_size==1) {
        printf("No nodes in the list\n");
        return;
    }
    list_size++;
    struct Node *cur=head->next,*prevNode;

    while(cur!=tail && cur->value!=key) {
        cur=cur->next;
    }

    if(cur==tail){
        printf("Node not found\n");
        return;
    }
    cur->value=value;
}

void del_by_value(int value){
    if(list_size==1) {
        printf("No nodes in the list\n");
        return;
    }
    struct Node *cur=head->next,*prevNode;        
    list_size--;
    while(cur!=tail && cur->value!=value) {
        cur=cur->next;
    }
    if(cur==tail){
        printf("Node not found\n");
        return;
    }
    prevNode=cur->prev;
    prevNode->next=cur->next;
    cur->next->prev=prevNode;
    free(cur);
}


void init_list(){
    head = new Node();
    tail = new Node();
    head->next=tail;
    tail->prev=head;
}
