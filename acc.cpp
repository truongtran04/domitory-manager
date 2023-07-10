#include"acc.h"


int random(){
	int min=0,max=100;
	return min + (int)( rand() * (max - min + 1.0) / (1.0 + RAND_MAX) );
}


bool imNotRobot(){
	
	srand((unsigned int)time(NULL));
	
	int num1=random();
	int num2=random();
	
	int result;
	printf("\n\t\t Ban co phai la robot?\n\t\t      %d  +  %d  =  ",num1,num2);
	scanf("%d",&result);
	if(result==num1+num2){
		printf("\n\t\t Cam on con nguoi!\a");
		return true;
	} else{
		printf("\n\t\t You are a stupid robot -.-\a");
		sleep(1);
		system("cls");
		return false;
	}
}

bool compare(account a,account b){
	if(strcmp(a.userName,b.userName)==0 && strcmp(a.passWord,b.passWord)==0){
		return true;
	} else return false;
}

bool checkingAccount(account a){
	
	if(strlen(a.userName)<6)
		return false;
	
	if(strlen(a.passWord)<6)
		return false;
	
	bool flag1=false,flag2=false, flag3=false;
	
	for( int i=0 ; i<strlen(a.passWord) ; i++ ){
		
		if( isdigit(a.passWord[i]) !=0 ){
			flag1=true;
			continue;
		}
		
		if( ispunct(a.passWord[i]) !=0 ){
			flag2=true;
			continue;
		}
		
		if( isupper(a.passWord[i]) !=0 ){
			flag3=true;
			continue;
		}
	}
	
	if( flag1==true && flag2==true && flag3==true ){
		return true;
	} else return false;
}

bool agreement(){
	
	int ch;
	int option=1;
	
	while(ch!=KEY_ENTER){
		printf("\n\t\t\t\t  ***DANG KY***\n\n");
		printf("\t\t\t  ***Dieu khoan ve mat khau***\n");
		printf("\n\t\t 1. Ten dang nhap co do dai toi thieu 6 ky tu");
		printf("\n\t\t 2. Mat khau co it nhat 6 ki tu, bao gom chu so,\n\t\t ki tu viet hoa va ki tu dac biet!");
		printf("\n\n\t\t %s Dong y va tiep tuc", option==1?"> ":" ");
		printf("\n\t\t %s Thoat", option==2?"> ":" ");
		
		ch=getch();
		
		switch(ch){
			
			case KEY_UP:
				if(option>1){
					option--;
				}
				break;
			case KEY_DOWN:
				if(option<2){
					option++;
				}
				break;
			default:
				break;
		}
			
		system("cls");
	}
		
	switch(option){
		case 1:
			return true;
			break;
		case 2:
			return false;
			break;
	}
}


void signUp(){
	
	account a,b;
	
	if(agreement()==false) return;
	
	signUp:
	printf("\n\t\t\t\t  ***DANG KY***\n\n");
	printf("\n\t\t Ten dang nhap:  ");
	scanf("%s",a.userName);
	
	printf("\n\t\t Mat khau:  ");
	scanf("%s",a.passWord);
	
	
	if( checkingAccount(a) == false ){
		printf("\n\t\t Ten dang nhap hoac mat khau khong hop le!\a");
		pause();
		goto signUp;
	}
	
	int code=2604;
	int xcode;
	code:
	printf("\n\t\t Ma bao mat:  ");
	scanf("%d",&xcode);
	if(xcode!=code){
		printf("\n\t\t Ma bao mat khong dung!\a");
		goto code;
	}
	
	if( imNotRobot()==false) return;
	sleep(1);
	
	FILE *f=fopen("account.txt","a+");
	if(f==NULL){
		printf("\n\t\t * Loi mo file account.txt!\a");
	}else {
		while(fscanf(f,"%s %s",b.userName,b.passWord)!=EOF){
			if(compare(a,b)==true){
				printf("\n\n\t\t Tai khoan da ton tai!\a");
				printf("\n\t\t Hay dang nhap hoac tao tai khoan khac!");
				pause();
				goto signUp;
			}
		}
		fprintf(f,"%-50s %-50s\n",a.userName,a.passWord);
		printf("\n\n\t\t Tao tai khoan thanh cong!\a");
		pause();
	}
	fclose(f);
}

bool logIn(){
	
	account a;
	
	logIn:
	printf("\n\t\t\t\t***DANG NHAP***\n\n");
	printf("\n\t\t Ten dang nhap:  ");
	scanf("%s",a.userName);
	printf("\n\t\t Mat khau:  ");
	scanf("%s",a.passWord);
	
	
	FILE *f2=fopen("account.txt","r");
	account b;
	if(f2==NULL){
		printf("\n\t\t ** Loi mo file account.txt!\a");
	} else{
		while(fscanf(f2,"%s %s",b.userName,b.passWord) != EOF){
			if(compare(a,b)==true){
				if( !imNotRobot() ) {
					fclose(f2);
					return false;
				} else {
					printf("\n\n\t\t Dang nhap thanh cong!\a");
					fclose(f2);
					return true;
				}
			}
		}
	}
	
	fclose(f2);
	printf("\n\n\t\t Dang nhap that bai!\a");
	printf("\n\t\t Tai khoan hoac mat khau khong dung!");
	pause();
	goto logIn;
}
