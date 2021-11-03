#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define err {printf("Error\n");return 0;}

int main(int argc, char **argv){
    FILE *file1, *file2;
    if(argc!=3){
        printf("Usage: exePath file1 file2\n");
        return 0;
    }

    if(!(file1=fopen(argv[1],"rb"))) err
    if(!(file2=fopen(argv[2],"rb"))) err

    int same=1,i=0;
    char ch1,ch2;
    int first=1;
    while(1){
        ch1 = fgetc(file1);
        if(ferror(file1)) err
        if(feof(file1)) break;

        ch2 = fgetc(file2);
        if(ferror(file2)) err
        if(feof(file2)) break;

        if(ch1!=ch2){
            if (first){
                printf("Files differ in positions: ");
                first=0;
            }
            printf("%d ",i);
            same=0;   
        }
        i++;
    }

    if(same) printf("The files are same.");

    printf("\n");

    fclose(file1),fclose(file2);
}
