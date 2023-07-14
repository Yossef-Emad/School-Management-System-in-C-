#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include"stdbool.h"
typedef struct mybirthDate{
int day;
int month;
int year;
}birthDate;
typedef struct myListEntry{
char name[25];
float score;
int id;
int phoneNum;
char adresse[50];
birthDate date;

}ListEntry;
typedef struct myStudent{
ListEntry student;
struct myStudent*pPrev;
struct myStudent*pNext;

}Student;
typedef Student*TreeNodePtr;
typedef struct List{
Student*pHead;
Student*pTail;
int studentId;
}studentList;
void NEW_STUDENT(studentList*pl);
void create(studentList*pl);
void DELETE_STUDENT(studentList*pl);
void STUDENT_LIST(studentList*pl,TreeNodePtr pn);
void STUDENT_EDIT(studentList*pl);
TreeNodePtr RANK_STUDENT(TreeNodePtr pn,studentList* pl,studentList*px);
void STUDENT_SCORE(studentList*pl);
void RANK(TreeNodePtr* ptr,ListEntry num);
void RANK_ORDER(TreeNodePtr pn);
studentList* NEW_RANK(studentList*pl);
TreeNodePtr minValueNode(TreeNodePtr node);
TreeNodePtr maxValueNode(TreeNodePtr node);
#endif // STUDENT_H_INCLUDED

