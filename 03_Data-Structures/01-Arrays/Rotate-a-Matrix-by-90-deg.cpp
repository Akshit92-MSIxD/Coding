// https://nados.io/question/rotate-by-90-degree?zen=true
// T = O(n^2)
// Must condition : Square matrix

// / After taking tripose : 

// for clockwise rotation --> reverse row wise(horizontally)
// for anti-clockwise rotation --> reverse column wise (vertically)


#include <iostream>
// #include <algorithm>       // swap function use kr sakte hai!!!
#include <vector>
using namespace std;



void reverse_row_wise(vector<vector<int>> &mat , int row)
{
    int left = 0 ;
    int right = mat[0].size() - 1;

    while(left<right)
    {
        int temp = mat[row][left];
        mat[row][left] = mat[row][right];
        mat[row][right] = temp;
        left++;
        right--;
    }
}

void reverse_matrix(vector<vector<int>> &mat)
{
      int n = mat.size();

      for(int row=0 ; row<n;row++)
      {
         reverse_row_wise(mat,row);
      }
}

void tripose(vector<vector<int>> &mat)
{
    int n = mat.size();

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}


void rotate(vector<vector<int>> &mat)
{
    tripose(mat);
    reverse_matrix(mat);
}


void display(vector<vector<int>> &mat)
{
    int  n = mat.size();

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
             cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;

    cin>>n;

    vector<vector<int>> mat;

    for(int i=0;i<n;i++)
    {
        vector<int> temp;

        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }

        mat.push_back(temp);
    }


    rotate(mat);

    display(mat);



}