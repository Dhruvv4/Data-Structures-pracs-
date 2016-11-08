#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *next;
	int data;
}NODE;

void insert(NODE **p, int v){
	NODE *newnode = (NODE*)malloc(sizeof(NODE));
	NODE *temp;
	newnode->next = NULL;
	newnode->data = v;

	if(*p == NULL){
		*p = newnode;
	}
	else{
		temp = *p;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next= newnode;
	}
}

void display(NODE *p){
	while(p!= NULL){
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

int delete(NODE **p, int v){
	NODE *temp,*prev;

	temp = *p;
	prev = NULL;

	while(temp != NULL){
		if(temp->data == v)
			break;
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL){	 // Data not found
		return printf("Data not found\n");;
	}
	if(temp == *p){		// First Node
		*p = temp->next;
	}
	else{
		prev->next = temp->next;
		free(temp);
		//return printf("%d is Deleted\n",(*p)->data);
	}
	return 1;

}

void reverse(NODE **p){
	NODE *temp,*prev;

	prev = NULL;

	while(*p != NULL){
		temp = (*p)->next;
		(*p)->next = prev;

		prev = *p;
		*p = temp;
	}

	*p = prev;
}

int main(void){
	NODE *first = NULL;
	int choice, value;

	while(choice != 4){
		printf("Enter your choice:\n1.Insert\t2.Delete\t3.Reverse\t4.Exit\n");
		scanf("%d",&choice);

		switch(choice){
			case 1: printf("Enter the value to be inserted\n");
			scanf("%d",&value);
			insert(&first,value);
			display(first);
			break;

			case 2: printf("Enter the value to be Delete\n");
			scanf("%d",&value);
			delete(&first,value);
			display(first);
			break;

			case 3: printf("List Reversed\n");
			reverse(&first);
			display(first);
			break;

			case 4: printf("Program terminates\n");
			break;

			default: printf("Enter a valid choice\n");
			break;
		}
	}
	
}