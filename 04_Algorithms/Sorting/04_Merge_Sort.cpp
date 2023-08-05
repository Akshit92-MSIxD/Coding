// TC(same for bc/ac/wc) = O(n*log 2 n)
// SC = O(n)

/* Algo-1 */

#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> mergeTwoSortedArrays(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    vector<int> ans(n + m, 0);

    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (A[i] < B[j])
            ans[k++] = A[i++];
        else
            ans[k++] = B[j++];
    }

    while (i < n)
        ans[k++] = A[i++];
    while (j < m)
        ans[k++] = B[j++];

    return ans;
}

vector<int> mergeSort(vector<int> &arr,int lo , int hi)
{
    int mid = lo + (hi-lo)/2;
 
    if(lo==hi)
    {
        vector<int> tarr;
        tarr.push_back(arr[lo]);
        return tarr;
    }
    
    
     vector<int> A = mergeSort(arr,lo,mid);
     vector<int> B = mergeSort(arr,mid+1,hi); 
     vector<int> C = mergeTwoSortedArrays(A,B);

    return C;


}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    vector<int> ans = mergeSort(A,0,n-1);
    cout << "Sorted Array -> ";
    print(ans);
    return 0;
}



/* Algo-2 */

#include <iostream>
using namespace std;

void merge(int arr[],int lo , int mid , int hi)
{
         int merger[hi-lo+1];

         int i=lo , j = mid+1 , k=0;

         while(i<=mid && j<=hi)
         {
            if(arr[i]<arr[j])
            {
                merger[k++] = arr[i++];
            }
            else
            {
                merger[k++] = arr[j++];
            }
         }

         while(i<=mid)
         {
            merger[k++] = arr[i++];
         }

         while(j<=hi)
         {
            merger[k++] = arr[j++];
         }

         for(int i=lo;i<=hi;i++)
         {
            arr[i] = merger[i-lo];
         }

         return;
}

void mergeSort(int arr[],int lo , int hi)
{
       int mid = lo + (hi-lo)/2;
       
       if(lo>=hi)
       {
        return;
       }

       mergeSort(arr,lo,mid); // sort the left array
       mergeSort(arr,mid+1,hi); // sort the right array
       merge(arr,lo,mid,hi); // merge the left and right sorted array
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int arr[n];
     
     cout<<"Enter the array : ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

     cout<<"Sorted Array : ";

    for(int i=0;i<n;i++)
    {
         cout<<arr[i]<<" ";
    }
}