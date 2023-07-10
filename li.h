#ifndef li.h
#define li.h
#include<stdio.h>
#include<stdlib.h>
#include"stlib.h"

typedef struct node{
	student data;
	node* next;
}node;

typedef struct list{
	node* head;
}list;


node* makeNode(student st);
void creatList(list* l);
void pushBack(list* l,node* newNode);
void deleteNode(list* l,node* oldNode);



#endif li.h
