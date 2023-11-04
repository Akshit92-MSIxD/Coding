// The State Of Wakanda - 1
// https://nados.io/question/the-state-of-wakanda-1?zen=true

// Wave traversal of 2D arrays!!!
// T = O(n^2)

#include<iostream>
#include<vector>

using namespace std;

void columnTraversal(vector<vector<int>> &mat){


    for(int j=0;j<mat[0].size();j++) // j means cols
    {

       if(j%2==0)
       {
           for(int i=0;i<mat.size();i++) // i means rows , for even cols move down i.e (i++)
           {
               cout<<mat[i][j]<<endl;
           }
       } 
       else
       {
           for(int i = mat.size()-1 ; i>=0;i--)  // for odd cols move up i.e (i--) 
           {
               cout<<mat[i][j]<<endl;
           }      
           
       }

    }

}

int main(){
    int n;
    int m;
    cin>> n;
    cin>> m;
    
    vector<vector<int>> mat;
    for(int i= 0; i< n; i++){
        vector<int> arr;
        for(int j= 0; j< m; j++){
            int ele;
            cin>> ele;
            arr.push_back(ele);
        }
        mat.push_back(arr);
    }
    
    columnTraversal(mat);
}