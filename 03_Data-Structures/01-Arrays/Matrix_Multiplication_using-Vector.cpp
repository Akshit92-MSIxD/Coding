// https://nados.io/question/matrix-multiplication?zen=true

// If A[r1][c1] and B[r2][c2] then C = AXB is possible iff 'c1 = r2' otherwise invalid!!! 

// if AXB is possible then C[r1][c2]

#include<iostream>
#include<vector>

using namespace std;


 void displayMul(vector<vector<int>> C)
 {
     int r = C.size();
     int c = C[0].size();

     for(int i=0;i<r;i++)
     {
         for(int j=0;j<c;j++)
         {
             cout<<C[i][j]<<" ";
         }
         cout<<endl;
     }
 }


 void matMultiplication(vector<vector<int>> A , vector<vector<int>> B)
 {
     int r1 = A.size();
     int c1 = A[0].size();

     int r2 = B.size();
     int c2 = B[0].size();

     if(c1!=r2)
     {
       cout<<"Invalid input";
       return;
     }
     else
     {
         vector<vector<int>> C;

         for(int i = 0; i<r1;i++) // pehle matrix ki row
         {
             vector<int> temp;

             for(int j=0;j<c2;j++) // dusri matrix ki column 
             {
                 int sum = 0;

                 for(int k = 0 ; k < c1 ;k++)
                 {
                    sum = sum + A[i][k] * B[k][j];
                 }

                 temp.push_back(sum);
             }

             C.push_back(temp);

         }

         displayMul(C);
     }
 }

int main()
{
    int r1;
    int c1;

    cin>>r1>>c1;

    vector<vector<int>> mat1;


    for(int i=0;i<r1;i++)
    {
        vector<int> temp;

        for(int j=0;j<c1;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }

        mat1.push_back(temp);
    }


    int r2;
    int c2;

    cin>>r2>>c2;

    vector<vector<int>> mat2;

    for(int i=0;i<r2;i++)
    {
        vector<int> temp;

        for(int j=0;j<c2;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }

        mat2.push_back(temp);
    }


    matMultiplication(mat1,mat2);




}