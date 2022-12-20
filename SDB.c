#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "SDB.h"

//------------- declare head pointer as a global variable so any variable in this file can acess it-------
student* head;

//------------------------- the following function check if the list is full or not ------------------
bool SDB_is_full(){
	//--------- the maximum capity of the list is 10 so if counter is 10 so it is full-------
	if (counter == 10) {
		return true;
	}
	else {
		return false;
	}
}
//----------------------- this function is used to get the number of students in our list -----------
uint8 SDB_GetUsedSize() {
	return counter;
}
//----------------- this function is used to check if id is alraedy exist or not -----------------
bool SDB_IsIdExist(uint32 id){

	student* ptr=(student*)malloc(sizeof(student));
	ptr=head;
	while(ptr->Student_ID!=id){
		ptr=ptr->next;
		if(ptr==NULL){
			//---------- if all data was checked and not found function returns f (id not exist)-----
			return false;
		}
	}
	//---------- if the ID exist return true --------------
	return true;
	
}
//----------------- this function is used to add new data to our linked list -----------------
bool SDB_AddEntry(){
	//------ first check if the list is not full -------
	if (SDB_is_full()){
		printf("------------------ data is full ------------------\n");
		
		return 0;
	}
	else{
	student* ptr=NULL;
	uint32 id, year, c1_id, c1_g, c2_id, c2_g, c3_id, c3_g;	
	//--------------------------get student data from user -------------------------------------
		printf("\n-enter student number %d ID :",counter+1);
		scanf("%d",&id);
		//------------ if the user is alraedy exists so it can't be added-----------
		if(counter!=0){
			if (SDB_IsIdExist(id)){
				printf("------------------ user already exist ------------------\n");
				return 0;
			}
		}
		printf("\n-enter student number %d year :",counter+1);
		scanf("%d",&year);	
		printf("\n-enter student number %d course1 ID :",counter+1);
		scanf("%d",&c1_id);
		printf("\n-enter student number %d course1 grade :",counter+1);
		scanf("%d",&c1_g);
		printf("\n-enter student number %d course2 ID :",counter+1);
		scanf("%d",&c2_id);
		printf("\n-enter student number %d course2 grade :",counter+1);
		scanf("%d",&c2_g);
		printf("\n-enter student number %d course3 ID :",counter+1);
		scanf("%d",&c3_id);
		printf("\n-enter student number %d course3 grade :",counter+1);
		scanf("%d",&c3_g);

	//------------------------- add data to our linked list------------------------
		if (counter ==0){
			//-------- if this is the frist data it will be in the head of the list -------------
			head=(student*)malloc(sizeof(student));
			head->Student_ID=id;
			head->Student_year=year;
			head->Course1_ID=c1_id;
			head->Course1_grade=c1_g;
			head->Course2_ID=c2_id;
			head->Course2_grade=c2_g;
			head->Course3_ID=c3_id;
			head->Course3_grade=c3_g;
			head->next=NULL;
			counter ++;
		return 1;
		}
		//------- if head alraedy had data we will make a new struct and make last one next pointer point to it ---------------
		else {
			ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			student* new=(student*)malloc(sizeof(student));
			new->Student_ID=id;
			new->Student_year=year;
			new->Course1_ID=c1_id;
			new->Course1_grade=c1_g;
			new->Course2_ID=c2_id;
			new->Course2_grade=c2_g;
			new->Course3_ID=c3_id;
			new->Course3_grade=c3_g;
			new->next=NULL;
			ptr->next=new;
			counter++;
		return 1;
		}
		
		return 0;
	}
}

//-------------------------------------------- delete entry function ----------------------------
void SDB_DeletEntry(uint32 id){

		student* ptr=NULL;
		ptr=head;
		//---------- if the data that will be deleted is in the head the head will be the next struct of the list ----------
		if(ptr->Student_ID=id){
			head=ptr->next;
			free(ptr);
			counter--;
			printf("------------------ data deleted ------------------\n");
		}
		//-------- if it is not in the head we will make pointer point to the one that will be deleted and anther point to the previous one------ 
		else{
			student* ptr2=NULL;
			ptr2=head;
			while(ptr->Student_ID!=id){
				ptr2=ptr;
				ptr=ptr->next;
				if(ptr=NULL){
					printf("------------------ not found ------------------\n");
					return ;
				}
			}
			//---------- the previous one will point to the next one and then it will be deleted--------------
			ptr2->next=ptr->next;
			free(ptr);
			counter--;
			printf("------------------ data deleted ------------------\n");
		}
	}
//--------------------------- this function is used to read a data of student given his ID -------------------------------
bool SDB_ReadEntry(uint32 id){
	if(SDB_IsIdExist(id)){
	student* ptr=NULL;
	ptr=head;
	//-------------- make pointer to point to the student with the given id  then print all his data ----------
	while(ptr->Student_ID!=id){
		ptr=ptr->next;
	}
	printf("-->student ID is %d :\n", ptr->Student_ID);
	printf("-->student year is %d :\n", ptr->Student_year);
	printf("-->student course 1 id is %d :", ptr->Course1_ID);
	printf("-->and it is grade is %d :\n", ptr->Course1_grade);
	printf("-->student course 2 id is %d :", ptr->Course1_ID);
	printf("-->and it is grade is %d :\n", ptr->Course2_grade);
	printf("-->student course 1 id is %d :", ptr->Course3_ID);
	printf("-->and it is grade is %d :\n", ptr->Course3_grade);
	return true;
	}
	else {
		printf("------------------not found ------------------\n");
	}
		
}
//--------------------------------------- this function is used to print the ids of all students --------------------
void SDB_GetList(){

		student* ptr=NULL;
		ptr=head;
		uint8 co=1;
		while(ptr!=NULL){
			printf("-->number %d ID is %d \n",co,ptr->Student_ID);
			ptr=ptr->next;
			co++;
	
	}
}
