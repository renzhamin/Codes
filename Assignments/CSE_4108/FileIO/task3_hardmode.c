#include <stdio.h>
#include <string.h>
#define nofile {printf("File doesn't exist\n");return;}
#define err {printf("Error\n");return;}

char **argv;


void readfromfile(){
    FILE *fp;
    if(!(fp=fopen(argv[1],"r"))) nofile
    for(int i=fgetc(fp);i!=EOF;i=fgetc(fp)) putchar(i); 

    fclose(fp);
}

void write(int append){
    getchar();
    FILE *fw,*fp;
    if(append){
        
        if(!(fp=fopen(argv[1],"r"))) nofile
        fclose(fp);
        if(!(fw=fopen(argv[1],"a"))) err

    } else if(!(fw=fopen(argv[1],"w"))) err    
    
    printf("Enter a Blank line to stop\n");
    
    char text[1000];
    while(1){
        fgets(text,1000,stdin);
        if(text[0]=='\n') break;
        fputs(text,fw);
    }

    fclose(fw);
}

void edit(){
    FILE* fp;

    if(!(fp=fopen(argv[1],"r+"))) nofile
    fseek(fp,0,SEEK_END);
    int end=ftell(fp);

    printf("Enter position: ");
    int i; scanf("%d",&i);
    getchar();

    if(i>end){
        printf("No such position.\nDo you want to append(y/n): ");
        char x; scanf("%c",&x);
        fclose(fp);
        if(x=='y') write(1);
        printf("Finished Editing\n");
        return;
    }

    printf("Enter a Blank line to stop\n");
    fseek(fp,i,SEEK_SET);
    char text[1000];
    while(1){
        fgets(text,1000,stdin);
        if(text[0]=='\n') break;
        fputs(text,fp);
    }
    printf("Finished Editing\n");
    fclose(fp);
}

void rename_file(){
    getchar();
    char s[1000];
    printf("Enter new name : ");
    scanf("%[^\n]",s);
    FILE *fp,*fw;
    if(!(fp=fopen(argv[1],"r"))) nofile
    if(!(fw=fopen(s,"w"))) err

    for(int i=fgetc(fp);i!=EOF;i=fgetc(fp)) fputc(i,fw); 

    fclose(fp),fclose(fw);
    remove(argv[1]);
    printf("File renamed successfully\n");
}

int main(int argc,char **args){

    argv=args;
    if(argc!=2){
        printf("Usage : exePath filename\n");
        return 0;
    }

    printf("1.Create new file\n2.Edit an existing file\n3.Rename a file\n4.Read from a file\nEnter choice: ");
    int mode;
    scanf("%d",&mode);

    if(mode==1) write(0);
    else if(mode==2) edit();
    else if(mode==3) rename_file();
    else if(mode==4) readfromfile();

}