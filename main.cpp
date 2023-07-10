#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>
#include<conio.h>
#include"stlib.h"
#include"li.h"
#include"acc.h"
#include"func.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void managementMenu();
void logInMenu();
void studentMenu();
void start();

int main(){
	start();
	return 0;
}

void managementMenu(){
	
	char op[][50]={
		"Sua doi thong tin sinh vien noi tru",
		"Huy dang ky noi tru",
		"Tra cuu thong tin",
		"Quay lai"
	};
	
    menu:
	fflush(stdin);
   
   int option=makeMenu(4,"\t\t***Ban quan li***\n\n",op);
   
   switch(option){
   		case 1:
   			changeStudentInfo();
   			pause();
   			goto menu;
   			break;
   		case 2:
   			deleteRegister();
   			pause();
   			goto menu;
   			break;
   		case 3:
   			searching();
   			pause();
   			goto menu;
   			break;
   		case 4:
   			start();
   			break;
   }
   
}


void logInMenu(){

	char op[][50]={ "Dang ky", "Dang nhap","Quay lai"};
	
	logIn:
	int option=makeMenu(3,"\t\t***Dang nhap***\n\n",op);
	
	int num;
	
	switch(option){
		
		case 1:
			signUp();
			break;
			
		case 2:
			if( !logIn() ){
				goto logIn;
				break;
			} else {
				system("cls");
				managementMenu();
			}
			break;
			
		default :
			start();
			break;

	}
}

void studentMenu(){
	
	char op[][50]= { "Dang ky noi tru","Quay lai"};
	
	int option=makeMenu(2,"\t\t***Menu sinh vien***\n\n",op);
	
	switch(option){
		
		case 1:
			boardingRegister();
			sleep(1);
			system("cls");
			start();
			break;
		case 2:
			
			start();
			break;
			
	}
}

void start(){
   
   char op[][50]={ "Ban quan li","Sinh vien","Thoat"};
   
   int option=makeMenu(3,"\t\tBan la ai?\n\n",op);
   
   switch(option){
   	
   		case 1:
   			logInMenu();
   			break;
   			
   		case 2:
   			studentMenu();
   			break;
   			
   		case 3:
   			return;
   }
}
