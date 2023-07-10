#include"li.h"

node* makeNode(student st){
	node* newNode=(node*)malloc(sizeof(node));
	newNode->data=st;
	newNode->next=NULL;
	return newNode;
}

void creatList(list* l){
	l->head=NULL;
}

void pushBack(list*l, node* newNode){
	if(l->head==NULL){
		l->head=newNode;
		return;
	} else{
		
		node* temp=l->head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		
		temp->next=newNode;
	}
}


void deleteNode(list* l, node* oldNode){
	node* temp = l->head;
    node* prev = NULL;

	if (prev == NULL) {
                
        l->head = temp->next;
        
    }else {
                
        prev->next = temp->next;
        
    }
    
}
