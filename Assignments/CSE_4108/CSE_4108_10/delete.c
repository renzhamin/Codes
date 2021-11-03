
void del_club(){
    if(!root->next) {printf("List Empty\n");return;}
    char clubName[50];
    scanf("%[^\n]\n",clubName);
    
    struct Clubs *cur=root->next,*prev=root;
    while(cur){
        if(!(strcmp(cur->name,clubName)))
            break;
        prev=cur;
        cur=cur->next;
    }   
    if(!cur) {printf("Club not found\n");return;}

    prev->next=cur->next;
    free(cur);
}

void del_player(){
    if(!root->next) {printf("List Empty\n");return;}    

    char clubname[50],playername[50];
    printf("Enter Player Name : ");
    scanf("%[^\n]\n",playername); 
    printf("Enter Current Club : ");
    scanf("%[^\n]\n",clubname);

    struct Clubs *cur=root->next;
    while(cur){
        if(!(strcmp(cur->name,clubname)))
            break;
        cur=cur->next;
    } 
    if(!cur) {printf("Club not found\n");return;}

    struct Player *pcur=cur->player->next,*prev=cur->player;
    while(pcur){
        if(!(strcmp(pcur->name,playername)))
            break;        
        prev=pcur;
        pcur=pcur->next;
    }
    if(!pcur) {printf("Player not found\n");return;}
    
    prev->next=pcur->next;
    free(pcur);
}