#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define pmalloc(x) (struct x*)malloc(sizeof(struct x))

struct Player{    
    char name[50],position[50];
    int age,rating,salary;
    struct Player *next;
};


struct Clubs{
    char name[50];
    int year,income;
    struct Clubs *next;
    struct Player *player;
}*root;

int list_size=1;

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

    if(index>list_size) {
        printf("Index Out of Bounds\n");
        return;
    }

    struct Clubs *cur=root,*prev=root;
    while(index--) {
        prev=cur;
        cur=cur->next;
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
    printf("Enter Player Name : "); scanf("%[^\n]\n",playername); 
    printf("Enter Current Club : "); scanf("%[^\n]\n",clubname);

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


void copyVal(struct Clubs *dest,struct Clubs *source){
    strcpy(dest->name,source->name);
    dest->year=source->year;
    dest->income=source->income;
    dest->player=source->player;
}

void swap(){
    if(!root->next) {printf("List Empty\n");return;}
    printf("Enter two postions to swap : ");
    int p1,p2; scanf("%d %d",&p1,&p2);
    struct Clubs *cur=root->next,*club1=0,*club2=0;
    int i=0;
    while(cur && ++i){
        if(i==p1) club1=cur;
        if(i==p2) club2=cur;
        cur=cur->next;
    }
    if(!club1 || !club2) {printf("Invalid position\n");return;}

    struct Clubs *tmp=pmalloc(Clubs);    
    copyVal(tmp,club1);
    copyVal(club1,club2);
    copyVal(club2,tmp);
}

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


int main(){
    root=pmalloc(Clubs);
    int c,done=0;
    while(!done){
        printf("What to you want to do?\n1.Create Club\n2.Delete Club\n3.View Club info\n4.Swap Clubs\n5.Add player\n6.Delete player\nChoice : ");
        scanf("%d\n",&c);
        switch(c){
            case 1 : {
                insert_club();
                break;
            }
            case 2 : {
                del_club();
                break;
            }
            case 3 : {
                showAll();
                break;
            }
            case 4 : {
                swap();
                break;
            }
            case 5 : {
                insert_player();
                break;
            }
            case 6 : {
                del_player();
                break;
            }
            default: done=1;
        }
    }
}