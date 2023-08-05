// https://nados.io/question/spiral-display?zen=true
// T = O(r*c)

#include <iostream>
using namespace std;

const int mr = 100, mc = 100;
void inputBound(int (&mat)[mr][mc], int n, int m)
{

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }
}

int main(int argc, char** argv)
{


  int mat[mr][mc] = {0};
  int r, c;
  cin >> r >> c;

  inputBound(mat,r,c);

  
  int maxr = r-1 , minr = 0;
  int maxc = c-1 , minc = 0;
  int count = 0; // will tell how many elements have been printed till now

 while(count<r*c)
 {
       // Dubare se why count condition ?? ==> we can stop from printing the same wall twice.

       for(int i = minr ; i <=maxr && count!=r*c;i++) // traverse from min row to max row (downward)
       {
         cout<<mat[i][minc]<<endl;
         count++;
       }
       minc++;

       for(int j = minc ; j  <= maxc  && count!=r*c ;j++) // traverse from min col to max c (right)
       {
         cout<<mat[maxr][j]<<endl;
         count++;
       }
       maxr--;

       for(int i = maxr; i>=minr  && count!=r*c; i--) // traverse from max row to min row (upward)
       {
         cout<<mat[i][maxc]<<endl;
         count++;
       }
       maxc--;

       for(int j = maxc ; j>=minc  && count!=r*c; j--) // traverse from max col to min col (left)
       {
         cout<<mat[minr][j]<<endl;
         count++;
       }
       minr++;
   
        }

        return 0;

}