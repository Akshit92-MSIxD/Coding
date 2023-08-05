// https://nados.io/question/the-state-of-wakanda-2?zen=true
// T = O(n^2)


#include <iostream>
#include <vector>
using namespace std;

void upperDiagonal_traverse(int n, vector<vector<int>> &arr)
{
     for(int gap=0 ; gap<n ; gap++) // gap btw corresponding i and j index of a particular element!!!
     {
              
         for(int i=0 , j = gap; j<=n-1 ; j++ , i++)
         {
             cout<<arr[i][j]<<endl;
         }
     }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    upperDiagonal_traverse(n, arr);

    
}

        // Brute force by me:

    //    int minc = 0 , minr = 0;
    //    int maxc = n , maxr = n;

    //    while(minc<=n-1)  // minr will stay same , only minc will update by one after each traversal in upper half!!!
    //    {
    //        int i,j;

    //        for(i=minr,j=minc;j<=maxc-1 && i<=maxr-1;j++,i++)
    //        {
    //            cout<<arr[i][j]<<endl;
    //        }

    //        minc++;
    //        maxr--;
    //    }