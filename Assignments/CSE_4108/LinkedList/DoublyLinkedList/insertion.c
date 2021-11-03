void insert_front(int index,int value){
    if(index>list_size+1) {
        printf("Index %d Out of Bounds\n",index);
        return;
    }
    list_size++;
    struct node *cur=root,*prevNode;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->value=value;
    while(cur!=end && index--) {
        cur=cur->next;
    }
    prevNode=cur->prev;
    prevNode->next=tmp;
    tmp->next=cur;
    tmp->prev=prevNode;
    cur->prev=tmp;
}

void insert_back(int index,int value){
    if(index>list_size+1) {
        printf("Index %d Out of Bounds\n",index);
        return;
    }
    list_size++;
    struct node *cur=end,*prevNode;
    struct node *tmp=(struct node*)malloc(sizeof(struct node));
    tmp->value=value;
    while(cur!=root && index--) {
        cur=cur->prev;
    }
    prevNode=cur->next;
    prevNode->prev=tmp;
    tmp->prev=cur;
    tmp->next=prevNode;
    cur->next=tmp;
}
