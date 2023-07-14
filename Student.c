#include"Student.h"
#include <stdio.h>
#include <stdlib.h>
#include"string.h"
extern int i;
void create(studentList*pl){
pl->pHead=NULL;
pl->pTail=NULL;
pl->studentId=1;

}
void NEW_STUDENT(studentList*pl){
    i=0;
    Student*pn=(Student*)malloc(sizeof(Student));
    if(pn==NULL){
    printf("no memory available\n");
              return;}

    printf("please Enter Student Name: ");

    //fgets(pn->student.name,20,stdin);
     scanf("%s",&pn->student.name);


    printf("please Enter Student score(0<GPA<4): ");
    scanf("%f",&pn->student.score);
    printf("please Enter Student Birth Date(11/9/2020): ");
    scanf("%d/%d/%d",&pn->student.date.day,&pn->student.date.month,&pn->student.date.year);
    printf("please Enter Student Adresse: ");
    fgets(pn->student.adresse,25,stdin);
    scanf("%s",&pn->student.adresse);
    printf("please Enter Student Phone Number: ");
    scanf("%d",&pn->student.phoneNum);

   pl->studentId++;
   pn->student.id=pl->studentId;
    pn->pNext=NULL;
   pn->pPrev=NULL;
    if(pl->pHead==NULL){

        pl->pHead=pl->pTail=pn;
    }
    else{
            //inserting by alphabetical ascending
        Student*temp=pl->pHead;

    while(temp!=NULL&&(strcmp(pn->student.name,temp->student.name)==1)){
      temp=temp->pNext;

    }

        if(temp==pl->pHead){

           pn->pNext=pl->pHead;
           pl->pHead->pPrev=pn;
           pl->pHead=pn;
        }
        else if(temp==NULL){
        pn->pPrev=pl->pTail;
        pl->pTail->pNext=pn;
        pl->pTail=pn;
        }

        else{
         pn->pNext=temp;
         pn->pPrev=temp->pPrev;
         temp->pPrev->pNext=pn;
         temp->pPrev=pn;


        }


    }

    return;

}
void DELETE_STUDENT(studentList*pl){
    ListEntry copy_data;
    printf("Enter any of Student ID  of the student you want to delete his or her information\n for ID press A and remember to press Any key if you will cancel delete operation\n");
     if(getche()=='A'){
     scanf("%d",&copy_data.id);}
     else{
        return;}

 if(pl->pHead==NULL){
    printf("There is no students here\n");
     return;}
  else{
     Student*temp=pl->pHead;
     //searching by id or phone Number
    while(temp!=NULL&&(copy_data.id!=temp->student.id)){
      temp=temp->pNext;
    }

       if(temp == NULL)
       {
           printf("Not Found Re Enter Again\n");
           return;
       }
       else
       {
           if(pl->pHead == pl->pTail)
           {

              pl->pHead = pl->pTail = NULL;
              free(temp);
           }
           else if(temp == pl->pHead)
           {

              pl->pHead = pl->pHead->pNext;

              pl->pHead->pPrev = NULL;

              free(temp);
           }
           else if(temp == pl->pTail)
           {

              pl->pTail = pl->pTail->pPrev;

              pl->pTail->pNext = NULL;

              free(temp);

           }
           else
           {
                temp->pPrev->pNext = temp->pNext;
                temp->pNext->pPrev = temp->pPrev;
                free(temp);
           }



  }


return;

  }

  }
void STUDENT_LIST(studentList*pl,TreeNodePtr pn){
 RANK_ORDER(pn);
 /*
if(i==1){

    i=0;
}
else{
    if(pl->pHead == NULL)
    {
        printf("List is empty\n");
        return;
    }
Student* temp=pl->pHead;
  while(temp!=NULL){

printf("StudentName is: %s\nStudentId is: %d\nStudentScore is: %f\nStudentBirthDate is: %d/%d/%d\nStudentAddress is: %s\nStudentPhoneNumber is: %d\n",temp->student.name,temp->student.id,temp->student.score,temp->student.date.day,temp->student.date.month,temp->student.date.year,temp->student.adresse,temp->student.phoneNum);
  //printf("the name is %s\nthe id is %d\n",temp->student.name,temp->student.id);
   temp=temp->pNext;
  }

i=0;}*/

}
void STUDENT_EDIT(studentList*pl){

    ListEntry copy_data;
  printf("please Enter the Id You Wanna Update\n his or her information for ID press A and press any key to cancel your Edit \n");

   if(getche()=='A'){
    scanf("%d",&copy_data.id);}
        else{
            return;
        }


      Student*temp=pl->pHead;
     //searching by id or phone Number
    while(temp!=NULL&&(copy_data.id!=temp->student.id)){
      temp=temp->pNext;
    }
// remember to edit here
if(temp==NULL){printf("the student does not exist");return;}

    printf("please Enter New Name: \n");

    scanf("%s",&temp->student.name);
    printf("please Enter New ID: \n");

    scanf("%d",&temp->student.id);
    printf("please Enter New Address: \n");

    scanf("%s",&temp->student.adresse);
    printf("please Enter New Birth Date(11/9/2020): \n");

    scanf("%d/%d/%d",&temp->student.date.day,&temp->student.date.month,&temp->student.date.year);
    printf("please Enter New Phone Number: \n");

    scanf("%d",&temp->student.phoneNum);
   return;
}
TreeNodePtr RANK_STUDENT(TreeNodePtr pn,studentList* pl,studentList*px){


Student*temp;
for(temp=pl->pHead;temp!=NULL;temp=temp->pNext){
    RANK(&pn,temp->student);

    }
i=1;


return pn;


}

void RANK(TreeNodePtr* ptr,ListEntry num){

    if(*ptr==NULL){

*ptr=(Student*)malloc(sizeof(Student));

if(*ptr!=NULL){
 (*ptr)->student=num;
 (*ptr)->pNext=NULL;
 (*ptr)->pPrev=NULL;

}
else{printf("there is no memory");}

}

else{
  if(num.score<(*ptr)->student.score){

    RANK(&((*ptr)->pPrev),num);
  }
  else if(num.score>(*ptr)->student.score){

    RANK(&((*ptr)->pNext),num);
  }
  else{
    printf("dub\n");
  }

}
}
void RANK_ORDER(TreeNodePtr pn){
if(pn!=NULL){
    RANK_ORDER(pn->pNext);
printf("StudentName is: %s\nStudentId is: %d\nStudentScore is: %f\nStudentBirthDate is: %d/%d/%d\nStudentAddress is: %s\nStudentPhoneNumber is: %d\n",pn->student.name,pn->student.id,pn->student.score,pn->student.date.day,pn->student.date.month,pn->student.date.year,pn->student.adresse,pn->student.phoneNum);

    RANK_ORDER(pn->pPrev);
}

}
void STUDENT_SCORE(studentList*pl){


      Student*temp=pl->pHead;
     //searching by id or phone Number
    while(temp!=NULL){
            printf("%s Enter your new score",temp->student.name);
            scanf("%d",&temp->student.score);
      temp=temp->pNext;
    }
    return;
}
TreeNodePtr maxValueNode(TreeNodePtr node)
{
    TreeNodePtr current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->pPrev != NULL)
        current = current->pPrev;

    return current;
};
TreeNodePtr minValueNode(TreeNodePtr node)
{
    TreeNodePtr current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->pNext != NULL)
        current = current->pNext;

    return current;
}
studentList* NEW_RANK(studentList* pl){
    studentList*px=NULL;
    px->pHead=px->pTail=NULL;

    Student*temp=pl->pHead;
    while(temp!=NULL){
Student*pn=(Student*)malloc(sizeof(Student));
if(pn==NULL){printf("no memory allocate\n");return px;}
//strcpy(pn->student.adresse,temp->student.adresse);
//pn->student.id=temp->student.id;
strcpy(pn->student.name,temp->student.name);
pn->student.phoneNum=temp->student.phoneNum;
pn->student.score=temp->student.score;
pn->student.date.day=temp->student.date.day;
pn->student.date.month=temp->student.date.month;
pn->student.date.year=temp->student.date.year;
pn->pNext=NULL;
pn->pPrev=NULL;

if(px->pHead==NULL){px->pHead=px->pTail=pn;


}
else{

      Student*arr=px->pHead;

    while(arr!=NULL&&(pn->student.score)<(arr->student.score)){
      arr=arr->pNext;

    }

        if(arr==px->pHead){
 printf("hi");
           pn->pNext=px->pHead;
           px->pHead->pPrev=pn;
           px->pHead=pn;
        }
        else if(arr==NULL){
        pn->pPrev=px->pTail;
        px->pTail->pNext=pn;
        px->pTail=pn;
        }

        else{
         pn->pNext=arr;
         pn->pPrev=arr->pPrev;
         arr->pPrev->pNext=pn;
         arr->pPrev=pn;


        }





}


temp=temp->pNext;
    }
return px;
}



