
void del_front(int index){
    struct node *cur=root,*prevNode;        
    if(index>list_size) {
        printf("Index %d Out of Bounds\n",index);
        return;
    }
    list_size--;
    while(cur!=end && index--) {
        cur=cur->next;
    }

    prevNode=cur->prev;
    prevNode->next=cur->next;
    cur->next->prev=prevNode;
    free(cur);
}

void del_back(int index){
    struct node *cur=end,*prevNode;        
    if(index>list_size) {
        printf("Index %d Out of Bounds\n",index);
        return;
    }
    list_size--;
    while(cur!=root && index--) {
        cur=cur->prev;
    }

    prevNode=cur->next;
    prevNode->prev=cur->prev;
    cur->prev->next=prevNode;
}

