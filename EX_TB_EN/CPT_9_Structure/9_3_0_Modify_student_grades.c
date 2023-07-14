#include <stdio.h>
struct student
{
    int num;
    char name[10];
    int computer,english,math;
    double average;
};
int update_score(struct student *p,int n,int num,int course,int score);

int main()
{
    int course,i,n,num,pos,score;
    struct student students[50];
    printf("Input n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Input the info of No.%d:\n",i+1);
        printf("number:");
        scanf("%d",&students[i].num);
        printf("name:");
        scanf("%s",&students[i].name);
        printf("math score:");
        scanf("%d",&students[i].math);
        printf("english score:");
        scanf("%d",&students[i].english);
        printf("computer score:");
        scanf("%d",&students[i].computer);
    }
    printf("Input the number of the student to be update:");
    scanf("%d",&num);
    printf("Choice the course:1.math 2.english 3.computer:");
    scanf("%d",&course);
    printf("Input the new score:");
    scanf("%d",&score);
    pos=update_score(students,n,num,course,score);
    if(pos==-1){
        printf("Not fount!\n");
    }else{
        printf("After update:\n");
        printf("num\tmath\tenglish\tcomputer\n");
        printf("%d\t%d\t%d\t%d\n",students[pos].num,students[pos].math,students[pos].english,students[pos].computer);
    }
    return 0;
}
int update_score(struct student *p,int n,int num,int course,int score)
{
    int i,pos;
    for(i=0;i<n;i++,p++){
        if(p->num==num)break;
    }
    if(i<n){
        switch(course){
            case 1:p->math=score;break;
            case 2:p->english=score;break;
            case 3:p->computer=score;break;
        }
        pos=i;
    }else{
        pos=-1;
    }
    return pos;
}