#include <stdio.h>
#include <stdlib.h>
#include"Student.h"
#include"stdbool.h"
#define INSERTSTUDENT     1
#define DELETESTUDENT     2
#define PRINTLIST  3
#define STUDENTEDIT   4
#define RANKSTUDENT  5
#define UPDATESCORE    6
#define PRINTRANK    7
#define EXIT       8
int i=0;
int main(){
system("color fc");
TreeNodePtr ptr=NULL;
studentList s,v;
create(&s);
create(&v);
NEW_STUDENT(&s);
NEW_STUDENT(&s);
NEW_STUDENT(&s);
//STUDENT_LIST(&s,ptr);
ptr=RANK_STUDENT(ptr,&s,&v);
STUDENT_LIST(&s,ptr);










}






















