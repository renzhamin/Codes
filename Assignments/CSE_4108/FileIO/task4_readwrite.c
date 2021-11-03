#include <stdio.h>
#define err {printf("Error\n");return 0;}
int main()
{
    FILE *fp,*fw;

    if(!(fp=fopen("Program","rb"))) err
    if(!(fw=fopen("test","wb"))) err 


    for(int i=fgetc(fp);i!=EOF;i=fgetc(fp)) fputc(i,fw); 

    fclose(fp),fclose(fw);
}