// Sparse Matrix
#include <stdio.h>
#include <conio.h>
void main()
{ clrscr();
// Defining Sparse matrix
int sarray[4][5] = { {0,0,0,0,1},
{0,0,8,2,0},
{4,2,0,0,0},
{1,0,0,0,2}
} ;
int size = 0;
// Finding total no of Non zero elements
for(int r=0;r<4;r++)
for(int c=0; c<5; c++)
if(sarray[r][c] !=0 )
size++ ;
printf("No. of Non-zero Representation: %d \n ",size);
//Making matrix for representation:(Row , Column, Value )
int rarray[3][size] ; // is a 3x7 matrix
//Generating Matrix
int k=0; // Counter for Resulting matrix
for(int row=0; row<4; row++)
for(int col=0; col<5; col++)
if(sarray[row][col] != 0)
{ rarray[0][k]=row;
rarray[1][k]=col;
rarray[2][k]=sarray[row][col];
k++;
}
//Display Resulting Matrix
printf("Triplet Representation: \n") ;
for(r=0;r<3;r++)
{printf(" \n ");
for(int c=0; c<size; c++)
printf(" %d ", rarray[r][c]);
}
getch();
}
