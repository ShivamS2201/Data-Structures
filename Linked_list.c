#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include <stdlib.h>
struct node
{ int data;
struct node *p;
};
struct node *head = NULL; //Declared Globally
void addatbeg(int); //add a node in beginning
void display(); // Display the linked list
void insertpos(); // Insert at a specified position
void delepos();
void main()
{ clrscr() ;
addatbeg(30);
addatbeg(40);
addatbeg(50);
display();
insertpos();
display();
delepos();
display();
getch();
}
void addatbeg(int ele)
{struct node *temp; //Pointer
temp = (struct node *)(malloc(sizeof(struct node))) ;
temp->data = ele;
if(head==NULL)
{temp->p = NULL;
head = temp;
}
else
{ temp->p = head; // The ptr of new node points to prev node that was head.
head = temp; //Temp becomes head.
}
}
void insertpos()
{ struct node *insert = head; //Pointer to traverse till the given position.
struct node *temp;
temp = (struct node *)(malloc(sizeof(struct node))) ; //New pointer to store values.
int val, pos=0;
printf("\n Enter the value to be inserted: ");
scanf("%d", &val);
printf("\n Enter the position: ");
scanf("%d", pos);
temp->data = val;
for(int i =0;i<pos;i++)
{insert = insert->p ;
if(insert == NULL)
{ printf("Cannot Insert here");
return;
}
}
temp->p = insert->p;// temp holds the next node
insert->p = temp; // The prev node points to temp now.
}
void delepos()
{ struct node *del = head; //Pointer to traverse till the given position.
struct node *temp;
temp = (struct node *)(malloc(sizeof(struct node))) ; //New pointer to store new values.
int pos=0;
printf("\n Enter the position of element: ");
scanf("%d",&pos);
for(int i =0;i<pos;i++)
{del = del->p ;
if(del == NULL)
{ printf("Overflow");
return;
}
}
temp->p = del->p;// temp holds the next node
free(temp); // The prev node points to temp now.
printf(" Deleted node pos: %d ", pos);
}
void display()
{ printf("\n ") ;
struct node *display = head; //A pointer pointing to the head node of linked list
while(display != NULL)
{ printf("%d ", display-> data);
display = display->p;
}
}
