

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