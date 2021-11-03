
void showAll(){
    if(!root->next) {printf("List Empty\n");return;}

    struct Clubs *cur=root->next;
    printf("Showing Clubs List :\n====================\n");
    while(cur){
        printf("%s\n%d\n%d\n",cur->name,cur->year,cur->income);
        struct Player* pcur=cur->player->next;
        cur=cur->next;
    
        if(pcur)
            printf("List of PLayers :\n--------------------\n");
        else {
            printf("No player contacts\n====================\n");
            continue;
        }
    
        while(pcur) {
            printf("%s\nAge : %d, Rating : %d, Salary : %d, Position : %s\n--------------------\n",
                pcur->name,pcur->age,pcur->rating,pcur->salary,pcur->position);
            pcur=pcur->next;
        }
        printf("====================\n");
    }    
}


int choice(){
    printf("What to you want to do?\n1.Create Club\n2.Delete Club\n3.View Club info\n4.Swap Clubs\nChoice : ");
    int c;
    scanf("%d\n",&c);
    return c;
}