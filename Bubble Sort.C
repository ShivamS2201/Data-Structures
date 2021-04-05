#include <stdio.h>
#include <conio.h>
void main()
{ int i,j,n,temp,a[15];
printf("What is the number of elements? - ");
scanf(“%d”, &n);
clrscr();
printf("Number of elements: %d \n \n", n);
printf("Please Enter the array elements : \n");
for(i = 0; i<n; i++)
{ scanf(“%d”,&a[i]);
}
clrscr();
printf("Before Sorting\n");
for(i = 0; i<n; i++)
{ printf("\t %d ",a[i]);
}
for(i=0;i<n;i++)
{ for(j=0;j<n -i ;j++) //n-i to decrement the size of list after every pass.
{ if(a[j] > a[j+1])
{ temp=a[j];
a[j] = a[j+1];
a[j+1] = temp;
// swaping using third variable
}
}
}
printf("\t %d ",a[i]);
for(i = 0; i<n; i++)
{ printf("\t %d ",a[i]);
}
getch();
}
