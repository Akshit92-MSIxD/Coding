#include <iostream>
using namespace std;




/*---------------ek baar paper mai diagram banale ni aara to pepcoding ka video dekh sumit sir wala 2D array-demo wala --------------------------*/

/* METHOD - 1 */ 

int** input(int** mat , int r, int c)
{
    mat = new int*[r];  //--->  making array of pointers to integers  of size r and storing its first block in 'mat' variable
    
    for(int i = 0 ;i<r;i++)
    {
      mat[i] = new int[c];   // --> each block of mat i.e mat[i] stores the address of starting block of  1D-array of size c

      for(int j=0;j<c;j++)
      {
        cin>>mat[i][j];
      }
    }
    
    return mat;
}



/* METHOD - 2 */

// Vector wala



/*------------------------------------------------------------------------------------------------------------------------------------------------*/

void output(int** mat , int r,int c)
{
    for(int  i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
} 

int main()
{
    int r,c;
    
    cin>>r>>c;
    
    int** mat = input(mat,r,c);
    
    output(mat,r,c);
    
    
}