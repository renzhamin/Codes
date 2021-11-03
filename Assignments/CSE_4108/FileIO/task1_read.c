#include <stdio.h>
#define err {printf("Error\n");return 0;}

int main(int argc,char **argv){
    FILE *fp,*fw;

    if(argc != 2){
        printf("Usage: exePath filename\n");
        return 0;
    }

    if(!(fp=fopen(argv[1],"r"))) err


    for(int i=fgetc(fp);i!=EOF;i=fgetc(fp)) putchar(i); 

    fclose(fp);

}