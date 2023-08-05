
// For finding the kth smallest element in O(n)

/* NOTE :  kth smallest element will be at (k-1)th index if sorted!!!
           worst case : O(n^2)*/

// This problem can also be solved by : Max-heap / Min-heap / setDS / Map .......(please do this problem with other approaches!!!) 

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int partition(vector<int> &arr , int low , int high )
{

    int cpi = low + rand()%(high-low); // choosen pivot index
    cout<<"cpi : "<<cpi<<" ";
    int pivot = arr[cpi];


    iter_swap(arr.begin()+low , arr.begin()+cpi);

    cpi = low;

    int i=low , j = high;

    while(i<=j)
    {
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }

        while(arr[j]>pivot && j>=low)
        {
            j--;
        }
         
         if(i<j)
         {
        iter_swap(arr.begin()+i , arr.begin()+j);
         }
    }

    iter_swap(arr.begin()+cpi , arr.begin()+j);
    cout<<"pi : "<<j<<endl;
    return j;


}


int kth_smallest(vector<int> &arr , int low , int high , int k)
{
 
 int pi = -1;

    while(true)
    {
        pi = partition(arr,low,high);

        if(pi>k-1) // kth smallest elm is on left side!!!
        {
          high = pi-1;
        }
        else if(pi<k-1) // kth smallest elm is on right side
        {
            low = pi + 1;
        }
        else    // kth smallest elm and pivot index is same
        {
            return arr[pi];
        }
    }

    
}

int main()
{

  cout<<"Enter the size of the array : ";
  int n;
  cin>>n;
 vector<int> arr(n,0);

 cout<<"Enter the elements inside the array : ";

 for(int i=0;i<n;i++)
 {
    cin>>arr[i];
 }

int k;

    do{
        cout<<"Enter the value of k : ";
        cin>>k;

        if(k>n || k<1)
        cout<<"value of k out of bounds please try again!!!\n\n";

    }while(k>n || k<1);


 int kelm = kth_smallest(arr,0,n-1,k);

 cout<<k<<"th smallest element is : "<<kelm<<endl;

}
