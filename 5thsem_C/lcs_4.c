#include<bits/stdc++.h>

int max(int a, int b);

int LongComSub( char *X, char *Y, int m, int n )
{
int L[m+1][n+1]; //The 2d array
int i, j;

for (i=0; i<=m; i++)
{
	for (j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		L[i][j] = 0;

	else if (X[i-1] == Y[j-1])
		L[i][j] = L[i-1][j-1] + 1;

	else
		L[i][j] = max(L[i-1][j], L[i][j-1]);
	}
}
	
return L[m][n]; // returns the value of the last cell in table.
}
int max(int a, int b)
{
	return (a > b)? a : b;
}

int main()
{
char X[] = "AGGTAB";
char Y[] = "GXTXAYB";

int m = strlen(X);
int n = strlen(Y);
printf("--------------------------\n");
printf("\t Strings \n");
printf("\t 1st: %s\n\t 2nd: %s\n", &X,&Y);
printf("Length of LCS is %d", LongComSub( X, Y, m, n ) );

return 0;
}
