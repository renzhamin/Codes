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



int main(int argc,char **args){

    argv=args;
    if(argc != 2){
        printf("Usage: exePath filename\n");
        return 0;
    }
    printf("Which mode?\n1.Write to file\n2.Read from file\n3.Append to file\nEnter choice: ");

    int mode; 
    scanf("%d",&mode);

    if(mode==1) write(0);
    else if(mode==2) readfromfile();
    else if(mode==3) write(1);

}