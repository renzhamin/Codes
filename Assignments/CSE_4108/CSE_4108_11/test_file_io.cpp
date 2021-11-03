#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxstudents=10,maxcourse=10;

struct courses{
    char name[200],id[200];
    double gpa,credit;
    int marks;
}courseinfo[maxcourse];

int mx=30;

struct student{
    char name[200],id[200],residence[200],
         year[10],section[10],prog[200],dept[200];
    int cou
    struct courses course[maxcourse];
    double cgpa;
} students[maxstudents];

double cg;

int idparser(char *id,struct student &st){
    st.year[2]=id[0],st.year[3]=id[1];
    st.year[4]='\n';st.year[5]='\0';
    char x=id[4];
    if(x=='4') strcpy(st.dept,"CSE\n");
    else if(x=='1') strcpy(st.dept,"MCE\n");
    else if(x=='2') strcpy(st.dept,"EEE\n");
    else if(x=='3') strcpy(st.dept,"TVE\n");
    else return 0;
    x=id[5];
    if(x=='1') strcpy(st.prog,"Bachelor of Science\n");
    else if(x=='2') strcpy(st.prog,"Higher Diploma\n"); 
    else return 0;
    st.section[0]='A'+id[6]-49;
    st.section[1]='\n';
    return 1;
}

double gpacalc(int marks,int totalmarks){
    double p=marks/(double)totalmarks*100,gpa;
    if(p>=80) return gpa=4;
    else if(p>=70) gpa=3.5;
    else if(p>=60) gpa=3;
    else if(p>=50) gpa=2.5;
    else gpa=2;
    return gpa;
}



int collectcourseinfo(){
    FILE* fp=fopen("courses.txt","r");
    char tmp[200];
    int l=0;
    while(!feof(fp)){
        fgets(tmp,200,fp);
        strcpy(courseinfo[l].name,tmp);
        fgets(tmp,200,fp);
        strcpy(courseinfo[l].id,tmp);
        fgets(tmp,200,fp);
        courseinfo[l].credit=atof(tmp);
        fgets(tmp,200,fp); // .....
    }
    fclose(fp);
}


int collectmarks(struct student &st){
    FILE* fp=fopen("marks.txt","r");
    char tmp[200];
    int l=0;
    cg=0;
    while(!feof(fp) && l<mx){
        fgets(tmp,200,fp);
        if(!strcmp(st.id,tmp)){
            fgets(tmp,200,fp);
            fgets(tmp,200,fp);
            courses[l].marks=atoi(tmp);
            courses[l].gpa=gpacalc(courses[l].marks,courses[l].credit*100);
            cg+=courses[l].gpa;
            l++;
        }
    }
    if(l) cg/=(double)l;
    fclose(fp);
    return l;
}

void showdetails(int l){
    if(!l) printf("No results\n");
    for(int i=0;i<l;++i){
        printf("Course: %sCourse ID: %sCourse Credit: %.2f\nAttained Marks: %d\nAttained Grade Point: %.2f\n",courses[i].name,courses[i].id,courses[i].credit,courses[i].marks,courses[i].gpa);
    }
}

void showstudentinfo(){
    printf("Name: %sAddress: %sStudent ID: %sYear of admission: %sProgram: %sDepartment: %sSection: %sCGPA: %.2f\n",name,residence,id,year,prog,dept,section,cg);    
}

int fillinfo(struct student *st){
    FILE* fp=fopen("students.txt","r");
    char tmp[200];
    int l=0;
    while(!feof(fp) && l<maxstudents){
        fgets(tmp,200,fp);
        strcpy(st[l]name,tmp);    
        fgets(tmp,200,fp);
        strcpy(st[l]id,tmp);
        fgets(tmp,200,fp);
        strcpy(st[l++]residence,tmp);
    }
    fclose(fp);
    return (f?1:0);
}

int main(){
    year[0]='2',year[1]='0';
    while(1){
        printf("Enter your Student ID: ");
        fgets(id,200,stdin);
        if(id[0]=='0') break;
        if(!idparser(id)){
            printf("Invalid ID\n");
            continue;
        }
        if(!fillinfo(id)){
            printf("ID not found\n");
            continue;
        }
        int l=collectmarks(id);
        showstudentinfo();
        printf("Do you want to see your result in details?\n1. Yes\n2. No\nEnter Choice: ");
        int c;
        scanf("%d",&c); getchar(); 
        if(c==1) showdetails(l);
        else if(c!=2) printf("Invalid input\n");
    }
}