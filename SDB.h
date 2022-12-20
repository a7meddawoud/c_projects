#ifndef medo
#define medo
#include <stdio.h>
#include "STD.h"
//---------counter is defined in the SDBAPP.c file and it is initialized by 0 so every time the programe run it will be 0 counter is used to count number of data in the list ---------------- 
extern uint8 counter;
//---------declaration   of the struct that will be used to receive the data  ---------------- 
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 //---------declaration  of the poiter that will point to the next data location ---------------- 
 struct SimpleDb* next;

}student;
 //---------declaration  of the functions that will be used in SDB.c ---------------- 
bool SDB_is_full();
bool SDB_IsIdExist(uint32 id);
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList();

#endif