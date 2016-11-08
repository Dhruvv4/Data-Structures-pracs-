#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	struct node *next;
	int data;
}NODE;

typedef struct STACK{
	struct node *last;
}STACK;

int push(STACK *s, int v){
	NODE *newnode;
	newnode = (NODE*)malloc(sizeof(NODE));
	if (newnode == NULL)
		return 0;
	else{
		newnode->data = v;
		newnode->next = s->last;
		s->last = newnode;
		return 1;
	}
}

int pop(STACK *s){
	NODE *temp;
	int v;

	if(s->last == NULL)
		return 0;
	
	else{
		temp = s->last;
		v = temp->data;
		s->last = s->last->next;
		free(temp);
		return v;
	}
}

int isEmpty(STACK s){
	if(s.last == NULL){
		return 1;
	}
	else
		return 0;
	
}

void display(STACK s){
	NODE *temp;
	temp = s.last;
	while(temp != NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
}

int main(void){
	STACK s;
	s.last = NULL;
	int ch, val, c;

	while(ch != 5){
		printf("Enter your choice:\n1.Push\n2.Pop\n3.isEmpty\n4.Display\n5.Exit\n");
		scanf("%d",&ch);

		switch(ch){
			case 1: printf("Enter the value to be inserted\n");
				scanf("%d",&val);
				push(&s,val);
				break;

			case 2: pop(&s);
				break;

			case 3:
			if(isEmpty(s) == 1)
				printf("List is empty\n");
			else
				printf("List is not empty\n");
			break;

			case 4: display(s);
			break;

			case 5: break;

			default: printf("Invalid choice\n");
			break;
		}
	}
	
}