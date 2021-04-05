#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>
struct queue
{int data;
struct queue *ptr;
};

struct queue *f= NULL, *r = NULL; //f front , r rear-> which points to null.
void insert(int);
void remove();
void display();

void main()
{clrscr();
int choice,n,num;
do
{
printf("\n \t\t Choose the operation to perform \n ");
printf("\t\t --------------------------------\n ");
printf("\t\t 1. Push \n\t\t 2. Pop\n\t\t 3. Display\n\t\t 4. Exit");
printf("\n \t\t Enter your choice: ");
scanf(“ %d ”, &choice);
switch(choice)
{
case 1:
{printf("\t\t Enter the element");
scanf(“%d ”, &num);
insert(num);
break;
}
case 2:
{
remove();
}
case 3:
{
display();
break;
}
case 4:
{ clrscr();
printf("\n \n \t\t Thank you");
break;
}
default:
{printf("\t\t Enter Valid Choice: ");
}
}
}while(choice != 4);
getch();
}
void insert(int num)
{ struct queue *temp; // temp pointer to traverse.
temp = (struct queue *)(malloc(sizeof(struct queue))) ;
if(f == NULL)
{temp->ptr = NULL;
f = r = temp; // both the front and rear point to the first and only node.
temp->data = num;
}
else
{r->ptr = temp;
temp->ptr = NULL;
temp->data = num;
r = r->ptr;
}
}
void remove()
{ struct queue *remove = f; //A pointer that points to the front element.
f = f->ptr; //front pointer points to the next element in the queue.
free(remove); //free the space for the element stored in the front most part of the queue.
}
void display()
{struct queue *dis = f;
if((f == r) && (f == NULL))
{printf("\t\t Queue Empty");
}
else
{ printf( "\t\t Front->");
while(dis != NULL)
{printf(" | %d | ->", dis->data);
dis= dis->ptr;
}
printf(" Rear\n ");
}
}
