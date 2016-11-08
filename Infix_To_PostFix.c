a#include<stdio.h>
#include<stdlib.h>
#define size 30
typedef struct stack
{
int top;
int a[size];
}STACK;
int push(STACK*,int);
int pop(STACK*);
int peek(STACK);
int empty(STACK);
int preceed(char);
int main()
{
STACK s;
s.top=-1;
int i,j=0;
char str[20],post[20],c;
printf("enter the infix exprssion to get the post fix expression\n");
scanf("%s",str);
for(i=0;str[i];i++)
{
if(str[i]>='a'&&str[i]<='z')
post[j++]=str[i];
else if(empty(s)||str[i]=='('||str[i]=='^'||preceed((char)str[i])>preceed((char)s.a[s.top]))
push(&s,str[i]);
else
{
if(str[i]==')')
{
while((c=pop(&s))!='(')
post[j++]=c;
}
if(preceed((char)str[i])<=preceed((char)s.a[s.top]))
{
post[j++]=pop(&s);
push(&s,str[i]);
}
}
}
while(!empty(s))
{
post[j++]=pop(&s);
}
post[j]='\0';
printf("the post fix expression is %s\n",post);
}
int push(STACK*p,int v)
{
if(p->top==size-1)
return 0;
else
{
p->a[++p->top]=v;
return 1;
}
}
int pop(STACK*p)
{
if(p->top==-1)
return 0;
else
return p->a[p->top--];
}
int peek(STACK p)
{
if(p.top==-1)
return 0;
else
return p.a[p.top];
}
int empty(STACK p)
{
return (p.top==-1);
}
int preceed(char ch)
{
switch(ch)
{
case '^':
case '&':
return 4;
case '*':
case '/':
case '%':
return 3;
case '+':
case '-':
return 2;
default:
return 1;
}
}
