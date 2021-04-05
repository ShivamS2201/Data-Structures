#include <stdio.h>
#include <stdlib.h>
struct node
{
int num;
struct node *next;
struct node *prev;
};
void create(struct node **, int ); // Creates a new node and enters the number.
int max(struct node *); //Finds the maximum number from the entered values.
void release(struct node **); // Deletes the stored values once the code ends.
int main()
{
struct node *p = NULL; // is the initial list in which entry takes place.
int n,size;
printf("Enter the length of list: \n");
scanf("%d", &size);
printf("Enter data into the list\n");
create(&p,size); // function call for calling the list.
n = max(p); // function call for max.
printf("The maximum number entered in the list is %d.\n", n);
release (&p); // releases the captured space in memory.
return 0;
}
int max(struct node *head)
{
struct node *max, *q; // one is for storing max element, other to traverse.
q = max = head;
while (q != NULL)
{ if (q->num > max->num)
{
max = q;
}
q = q->next;
}
return (max->num);
}
void create(struct node **head, int size)
{
int ele, ch;
struct node *temp, *rear;
for(int i=0;i<size;i++)
{
printf("Enter element %d :",i+1);
scanf("%d", &ele);
temp = (struct node *)malloc(sizeof(struct node));
temp->num = ele;
temp->next = NULL;
temp->prev = NULL;
if (*head == NULL)
{ *head = temp;
}
else
{ rear->next = temp;
temp->prev = rear;
}
rear = temp;
}
printf("\n");
}
void release(struct node **head)
{ struct node *temp = *head;
*head = (*head)->next;
while ((*head) != NULL)
{
free(temp);
temp = *head;
(*head) = (*head)->next;
}
}
