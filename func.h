#ifndef func.h
#define func.h
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"stlib.h"
#include"li.h"


void pause();
void changeStudentInfo();
void deleteRegister();
void searchingRoom();
void searchingStudent();
void searching();
void managementMenu();
int makeMenu(int num,char title[], char op[][50]);
void writeToFile(list* l);
list* readFromFile(list* l);
void boardingRegister();

#endif func.h
