// https://nados.io/question/saddle-price?zen=true

// Saddle point : element which is minimum in row , max in a column
// T = O(n^2)
// There would be maximum one sadding point present in a matrix!!!

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void saddle_point(int n, vector<vector<int>> &arr)
{
    
    for(int row = 0;row<=n-1;row++)
    {
        int min = 0;

        for(int col =0;col<=n-1;col++)
        {
            if(arr[row][col]<arr[row][min])
            {
                min = col;
            }

        }

        bool is_saddle_found = true;

            for(int down = 0 ; down<=n-1;down++)
            {
                if(arr[down][min] > arr[row][min])
                {
                    is_saddle_found = false;
                    break;
                }
            }  

            if(is_saddle_found == true)
            {
                int saddle_point = arr[row][min];
                cout<<saddle_point;
                return;
            }      
    }

    cout<<"Invalid input";
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n)); 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    saddle_point(n, arr);
}