#include <stdio.h>
#include <stdlib.h>
#define allocate (struct Data*)malloc(sizeof(struct Data))
#define equalbutnotreally(x,y) cur->x==cur->next->x  && \
                               cur->y < cur->next->y 

struct Data{
    char name[100];
    int ds,net,ml,total;
    struct Data *next;
}*root,*cur,*prev;

void swap(struct Data *a,struct Data *b){
    struct Data *tmp=allocate;
    prev->next=b;
    a->next=b->next;
    b->next=a;
    prev=b;
}

int main(){
    root=allocate; cur=allocate;
    prev=allocate; 
    cur=root;

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        struct Data *tmp=allocate;
        scanf("%s %d %d %d",tmp->name,&tmp->ml,&tmp->ds,&tmp->net);
        tmp->total=tmp->ml+tmp->ds+tmp->net;
        cur->next=tmp;
        cur=tmp;
    }

    for(int i=0;i<n-1;i++){  
        prev=root;
        cur=root->next;
        for(int j=0;j<n-i-1;j++){
            if( cur->total < cur->next->total || (
                equalbutnotreally(total,ml)   ||  
                equalbutnotreally(ml,ds)      ||
                equalbutnotreally(ds,net))){

                swap(cur,cur->next);
            }   
            else{
                prev=cur;
                cur=cur->next;
            }
        }
    }

    cur=root;
    int i=1;
    while(cur=cur->next) 
        printf("%d %s\n",i++,cur->name );

}
/*
5
Bryan 80 95 85
Howie 80 80 80
Andrew 80 70 90
Kevin 95 85 99
Nick 95 85 80
*/