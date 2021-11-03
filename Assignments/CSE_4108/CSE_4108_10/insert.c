
void insert_club(){
    struct Clubs *tmp=pmalloc(Clubs);
    tmp->player=pmalloc(Player);
    printf("Enter Name : ");
    scanf("%[^\n]\n",tmp->name);
    
    printf("Enter year of Formation : ");
    scanf("%d\n",&tmp->year);

    printf("Enter yearly revrevenue : ");
    scanf("%d\n",&tmp->income);

    printf("Enter Position : ");
    int index;
    scanf("%d\n",&index); 

    struct Clubs *cur=root,*prev=root;
    while(cur && index--) {
        prev=cur;
        cur=cur->next;
    }
    if(index>0) {
        printf("Index Out of Bounds\n");
        return;
    }
    prev->next=tmp;
    tmp->next=cur;
}

void insert_player(){
    if(!root->next) {printf("List Empty\n");return;}
    struct Player *tmp=pmalloc(Player);
    char clubname[50];

    printf("Enter Player Name : "); scanf("%[^\n]\n",tmp->name);
    printf("Age of Player : ");     scanf("%d\n",&tmp->age);
    printf("Player Rating : ");     scanf("%d\n",&tmp->rating);
    printf("Yearly Salary : ");     scanf("%d\n",&tmp->salary);
    printf("Position : ");          scanf("%[^\n]\n",tmp->position);
    printf("Club contact : ");      scanf("%[^\n]\n",clubname);

    struct Clubs *cur=root->next;
    while(cur){
        if(!(strcmp(cur->name,clubname)))
            break;
        cur=cur->next;
    }
    if(!cur) {printf("Club not found\n");return;}

    struct Player* pcur=cur->player;
    while(pcur->next) pcur=pcur->next;
    pcur->next=tmp;
}