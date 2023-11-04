// https://nados.io/question/search-in-a-sorted-2d-array?zen=true

#include <iostream>
#include <vector>
using namespace std;

// Approach : 

// move left when target element is less than current element ==> col-- , row(const)
// move down if target element is greater than current element ==> row++ , col(const

bool searchMatrix(vector<vector<int>>& matrix, int target) // T = O(n+m) / O(n)
{
    int n = matrix.size();

    int row = 0 , col = n-1; // Start traversing from first row last column

    while(row<n && col>=0)
    {
        if(target == matrix[row][col])
        {
            cout<<row<<endl<<col;
            return 1;
        }
        else if(target < matrix[row][col])
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    return 0 ;
     

}

int main() 
{
    int n, target;
    cin>>n;
    vector<vector<int>> mat(n, vector<int> (n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>mat[i][j];
    cin>>target;

    if(!searchMatrix(mat, target)) cout<<"Not Found\n";
}

        //Approach :  Linear Search in a partcular row [T=O(n*m)] or [T=O(n^2)]

        // for(int col=0;col<n;col++)
        // {
        //     if(matrix[row][col] == target)
        //     {
        //         cout<<row<<endl<<col;
        //         return 1;
        //     }
        // }



    // Approach : Binary Search in a particular row [T = O(n*logm)] or [T=O(nlogn)]

//    for(int row = 0;row<n;row++)
//    {
//        int low = 0 , high = n-1;

//        while(low<=high)
//        {
//            int mid = low + (high-low)/2;

//            if(target == matrix[row][mid])
//            {
//                cout<<row<<endl<<mid;
//                return 1;
//            } 

//            else if(target>matrix[row][mid])
//            {
//               low = mid + 1;
//            }
//            else
//            {
//                high = mid - 1;
//            }
//        }
//    }

//    return 0;