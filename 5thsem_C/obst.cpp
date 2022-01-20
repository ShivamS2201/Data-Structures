
#include <iostream>
#include <conio.h>
# define SIZE 10
using namespace std;
class Optimal
{
private:
    int p[SIZE];      // Probabilities with which we search for an element
    int a[SIZE];// Elements from which OBST is to be built
    int w[SIZE][SIZE];// Weight w[i][j] of a tree having root r[i][j]
    int c[SIZE][SIZE];// Cost  c[i][j] of a tree having root r[i][j]
    int r[SIZE][SIZE];// Represents Root
    int n;            // Number of nodes
public:
    void get_data();
    int Min_Value(int,int);
    void OBST();
    void finalAns();
    };
/*  This funciton accepts the input data	*/

void Optimal::get_data()
{
    int i;
    cout<<"\n Optimal Binary Search Tree\n";
    cout<<"________________________________\n";
    cout<<"\n Enter the number of nodes   ";
    cin>>n;
    cout<<"\n Enter the data as  ....\n";
    for (i=1; i<=n; i++)
        {
            cout<<"\nArray element- "<<i<<": ";
            cin>>a[i];
        }
    for (i=1 ; i<=n ; i++)
        {
            cout<<"\nProbability of element -"<<i<<": ";
            cin>>p[i];
        }
}
/* This function returns a value in the range r[i][j-1] to r[i+1][j]
		so that the cost c[i][k-1] + c[k][j] is minimum  */

int Optimal::Min_Value(int i, int j)
{
    int m,k;
    int minimum = 32000;
    for (m=r[i][j-1] ; m<=r[i+1][j] ; m++)
        {
            if ((c[i][m-1]+c[m][j]) < minimum)
                {
                    minimum = c[i][m-1] + c[m][j];
                    k = m;
                }
        }
    return k;
}

/*  This function builds the table from all the given probabilities
 It basically computes C,r,W values
*/

void Optimal::OBST()
{
    int i, j, k, l, m;
    for (i=0 ; i<n ; i++)
        {
// Initialize
            //w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
// Optimal trees with one node
            w[i][i+1] =  p[i+1]; 
            r[i][i+1] = i+1;
            c[i][i+1] = p[i+1]; 
        }
    //w[n][n] = q[n];
    r[n][n] = c[n][n] = 0;
// Find optimal trees with m nodes
    for (m=2 ; m<=n ; m++)
        {
            for (i=0 ; i<=n-m ; i++)
                {
                    j = i+m;
                    w[i][j] = w[i][j-1] + p[j] ;
                    k = Min_Value(i,j);
                    c[i][j] = w[i][j] + c[i][k-1] + c[k][j];
                    r[i][j] = k;
                }
        }
}

/*This function builds the tree from the tables made by the OBST function */
void Optimal:: finalAns(){
    cout<<"The Optimal Binary Search Tree For The Given Nodes has ....\n";
    cout<<"\n The Root of this OBST is :: "<<a[r[0][n]];
    cout<<"\n The Cost Of this OBST is :: "<<c[0][n];
    cout<<"\n -------------------------------------------------------"<<endl;

}

/* This is the main function */
int main()
{
    Optimal obj;
    obj.get_data();
    obj.OBST();
    obj.finalAns();
    getch();
    return 0;
}
