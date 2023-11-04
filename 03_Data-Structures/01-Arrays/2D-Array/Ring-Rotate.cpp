// https://nados.io/question/ring-rotate?zen=true
// T = O(n+m)
// S = O(n+m)


/*------------------------------------------------------------------------------------------------------------------------------------------------*/


 // Note : For clockwise rotation(+ve)

        //  There are two methods :

            // ALGO 1 :-

                        //  1) Reverse the whole array
                        //  2) Reverse the first r elements , then remaining elements arr.size() - r elements

                                //  OR

            // ALGO 2 (reverse of ALGO 1) : - 

                        //  1) Reverse the first arr.size() - r  , then remaining  r elements
                        //  2) Reverse the whole array 


/*------------------------------------------------------------------------------------------------------------------------------------------------*/


// Note : For anticlockwise directions(+ve)

             //   ALGO :
                    
                        //   2) Reverse the whole array
                        //   1) Reverse the first arr.size()-r elements , then remainining r elements


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/



#include <bits/stdc++.h>
using namespace std;

 vector<int>  fillOnedfromShell(vector<vector<int>> &arr , int s)
 {
    vector<int> oned;

    int minr = s-1 , minc = s-1;
    int maxr = arr.size()-s , maxc = arr[0].size()-s;

    for(int i = minr ; i<maxr;i++)
    {
        oned.push_back(arr[i][minc]);
    }
    
    for(int j = minc ; j<maxc;j++)
    {
        oned.push_back(arr[maxr][j]);
    }

    for(int i = maxr ; i>minr;i--)
    {
        oned.push_back(arr[i][maxc]);
    }

    for(int j = maxc ; j>minc;j--)
    {
        oned.push_back(arr[minr][j]);
    }
    

    return oned;

 }



 void reverse(vector<int> &oned , int left , int right)
 {
       
        while(left<right)
        {
            int temp = oned[left];
            oned[left] = oned[right];
            oned[right] = temp;

            left++;
            right--;
        }

        return;
 }


 void fillshellfromOned(vector<vector<int>> &arr , vector<int> &oned , int s)
 {
          
    int minr = s-1 , minc = s-1;
    int maxr = arr.size()-s , maxc = arr[0].size()-s;
    int index = 0;

    for(int i = minr ; i<maxr;i++)
    {
        arr[i][minc] = oned[index];
        index++;
    }

    for(int j = minc ; j<maxc;j++)
    {
        arr[maxr][j] = oned[index];
        index++;
    }

    for(int i = maxr ; i>minr;i--)
    {
        arr[i][maxc] = oned[index];
        index++;
    }
    
    for(int j = maxc ; j>minc;j--)
    {
        arr[minr][j] = oned[index];
        index++;
    }
    
     
 }

 void rotateshell(vector<vector<int>> &arr , int s , int r)
 {

     // Step 1 : Convert the shell into 1D array.
      vector<int> oned = fillOnedfromShell(arr,s);

       int sz = oned.size();
        r = r % sz;

        if(r<0) 
        {
            r+=sz;
        }


   // Step 2 : Rotate oned array by r rotations !!!

      // reverse the whole oned 
      reverse(oned , 0 , oned.size()-1);

      // reverse the elements ranging from 0 to r-1
      reverse(oned , 0 , r-1);

      //reverse the remaining  elements ranging from  r  to  oned.size() - 1
      reverse(oned , r , oned.size()-1);



    // Step 3 : Now filling the shell from oned array 

     fillshellfromOned(arr , oned , s);

     return;


 }


 void display(vector<vector<int>> &arr)
 {
      
      int nr = arr.size();
      int nc = arr[0].size();

      for(int i=0;i<nr;i++)
      {
          for(int j=0;j<nc;j++)
          {
              cout<<arr[i][j]<<" ";
          }

          cout<<endl;
      }
 }


 int main()
 {
     int nr,nc;
     cin>>nr>>nc;
     vector<vector<int>> arr(nr,vector<int>(nc));

     for(int i = 0 ; i<nr;i++)
     {
         for(int j=0;j<nc;j++)
         {
             cin>>arr[i][j];
         }
     }
 
  int s,r;

  cin>>s>>r;

    
    rotateshell(arr,s,r);

    display(arr);

 }