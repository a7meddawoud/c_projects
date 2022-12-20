#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "SDBAPP.h"
//------- int the start of the app number of students is 0 ----------------
uint8 counter=0;
//-------------- this function is a super loop that asks user of his choice-----------
void SDB_APP(){
	uint8 ch;
	while(1){
		printf(" To add entry, enter 1 \n To get used size in database, enter 2 \n To read student data, enter 3 \n To get the list of all student IDs, enter 4 \n To check is ID is existed, enter 5 \n To delete student data, enter 6 \n To check is database is full, enter 7 \n To exit enter 0 \n :");
		scanf("%d",&ch);
		if(ch==0){
			break;
		}
		//-------- user cann't do any operation before adding at least 1 student------
		else if (ch!=1 && counter==0){
			printf("--------- please add at least 1 entry --------- \n");
		}
		else{
			SDB_action(ch);
		}
	}
}
//--------- this function takes the choice from SDB_APP function and take action according to the choice-------
void SDB_action(uint8 choice){
		uint32 idd;
		bool xx;
		switch(choice){
			case 1:
				xx=SDB_AddEntry();
				if(xx==1){
					printf("------------------ data added ------------------\n");
				}
				else{
					printf("------------------ data not added ------------------\n");
				}
				break;
			case 2:
				printf("------------------ the used size is %d ------------------\n",SDB_GetUsedSize());
				break;
			case 3:	
				printf("enter student id");
				scanf("%d",&idd);
				SDB_ReadEntry(idd);
				break;
			case 4:
				SDB_GetList();
				break;
			case 5:	
				printf("enter student id");
				scanf("%d",&idd);
				if(SDB_IsIdExist(idd)){
					printf("------------------ id exist ------------------ \n");
				}
				else{
					printf("------------------ not exist ------------------\n");
				}
				break;
			case 6:
				printf("enter student id");
				scanf("%d",&idd);
				SDB_DeletEntry(idd);
				break;
			case 7:
				if(SDB_is_full()){
					printf("------------------ the list is full ------------------ \n");
				}
				else{
					printf("------------------ the list is not full ------------------ \n");
				}
				break;
			default:
			printf("------------------ enter vaild num ------------------\n");
		}
			
}