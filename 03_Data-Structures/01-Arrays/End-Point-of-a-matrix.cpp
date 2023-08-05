// https://nados.io/question/exit-point-of-a-matrix?zen=true
// T = O(rc) , if square matrix T = O(n^2)
#include <iostream>
using namespace std;


const int mr = 100, mc = 100;

void checkdir(int &dir, int &row , int &col)
{
   if(dir == 0)
     {
       col++;
     }
     else if(dir == 1)
     {
       row++;
     }
     else if(dir == 2)
     {
       col--;
     }
     else if(dir == 3)
     {
       row--;
     }
}

int** input(int** mat, int n, int m) // THODA CONFUSION HAI ISE JARUR DEKHNA FREE TIME MAI !!!
{
  mat = new int* [n];
  for (int i = 0; i < n; i++)
  {
    int* arr = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin >> arr[j];
    }
    mat[i] = arr;
  }
  return mat;
}


int main(int argc, char** argv)
{
  int n, m;
  cin >> n >> m;
  int** arr = input(arr, n, m);


  int row=0 , col = 0 , dir = 0; // dir = 0 (east) , 1(south) , 2(west) , 3(north)  | yahi sahi order hai directions ka!!!!


  while((row>=0 && row<n) && (col>=0 && col<m))
  {
      
      dir = (dir + arr[row][col]) % 4; // dir change for 1 , no change in dir for 0

      checkdir(dir,row,col);

  }


  if(row<0)
  {
    row++;
  }
  else if(row>n-1)
  {
    row--;
  }
  else if(col<0)
  {
    col++;
  }
  else if(col>m-1)
  {
    col--;
  }

cout<<endl<<row<<endl<<col;
return 0;
}

   
   // BRUTE FORCE SOLUTION CREATED BY ME :

    // while((row>=0 && row<n) && (col>=0 && col<m))
    // {
    //     while((row>=0 && row<n) && (col>=0 && col<m) && (arr[row][col] == 1)) // jese hi 1 dikhe change
    //     {
    //       dir = (dir+1) % 4; 
    //       checkdir(dir,row,col);
        
    //     }
        
    //     while((row>=0 && row<n) && (col>=0 && col<m) && (arr[row][col] == 0)) // jabtak 0 tabtak usi dir mai chalte raho
    //     {
    //       checkdir(dir,row,col);
    //     }
    // }

    // if(row<0)
    // {
    //   row++;
    // }
    // else if(row>n-1)
    // {
    //   row--;
    // }
    // else if(col<0)
    // {
    //   col++;
    // }
    // else if(col>m-1)
    // {
    //   col--;
    // }
           
    //  cout<<row<<endl<<col;