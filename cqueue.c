#include <stdio.h>
#include <stdlib.h>
#define size 100

typedef struct queue
{
	int a[size];
	int front, rear;
}QUEUE;

int insert(QUEUE *s,int v)
{
	if(((s->front==-1)&&(s->rear==size-1))||(s->rear+1)%size==s->front)
		{
		printf("queue is full \n");
		return 0;
		}

	else
		{
		s->rear=(s->rear+1)%size;
		s->a[s->rear]=v;
		return 1;
		}
}

int delete(QUEUE *s)
{
	if(s->front==s->rear)
		{
		printf("\nqueue is empty\n");
		return 0;
		}
	else
	{
		s->front=(s->front+1)%size;
		return s->a[s->front];
	}
}

void display(QUEUE s)
{
	int i;
	if(s.rear!=s.front)
	{		i=s.front+1;
		while(i!=s.rear)
		{
			printf("%d\t",s.a[i]);
			i=(i+1)%size;
		}
		printf("%d\t",s.a[s.rear]);
	}
}

int main(void)
{
	QUEUE q;
	q.rear=-1;
	q.front=-1;
	insert(&q,10);
	insert(&q,20);
	insert(&q,30);
	insert(&q,40);
	insert(&q,50);
	display(q);
	delete(&q);
	display(q);
	
}
