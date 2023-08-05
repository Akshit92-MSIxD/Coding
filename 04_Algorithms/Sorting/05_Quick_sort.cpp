// TC(same for bc/ac) = O(n*log 2 n)(pivot elm becomes median after every partioning) 
// TC(wc) = O(n^2) (already sorted(asc or desc) or same elements!!!)
// SC = O(1)

/* Note : Partioning can be done by choosing :

#CONCEPT : swap elm(lesser than pivot) with elm(greater than pivot)

1) Last elm as pivot elm (pi and i->) 
2) First elm as pivot elm ( i->(elm>pivot) and <-j(elm<=pivot) ==> swap)
3) Middle elm as pivot elm (mod version of striver's first elm algo ==>  created by me  ==> when <-j will cross i-> ==> if(cpi<j)=>swap(cpi,j) ,  if(cpi>i)=>swap(i,cpi) )
4) Random elm as pivot elm ( pick random pivot using rand() ==> swap(arr[cpi], arr[lo/hi]) ==> then accordingly apply first/last elm algo!!! )

Note : --> TC of Randomised quick sort will be O(n^2) for asc/desc array but it will reduce the no. of occurrences of getting the worst case!!!!
       --> But randomized QS will not work on array with same elements!!!
      
*/




// Quick sort for choosing last elm as pivot  

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr,int low , int high)
{
     int pivot = arr[high];

     int pi=0,i=0;


     while(i<high)
     {
        if(arr[i]<=pivot)
        {
            iter_swap(arr.begin()+pi ,arr.begin()+i);
            pi++;
            i++;
        }
        else
        {
            i++;
        }
        
     }

     iter_swap(arr.begin()+pi , arr.begin()+i);

     return pi; 


}

void quicksort(vector<int> &arr,int low , int high)
{
     if(low>=high)
     {
        return;
     }
     
   int pi = partition(arr,low,high);
   quicksort(arr,low,pi-1);
   quicksort(arr,pi+1,high);
}


int main()
{
    int n;

    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> arr(n,0);
 
    cout<<"Enter the elements into the array : ";
   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
   }

   quicksort(arr,0,n-1);

   cout<<"Sorted array : ";

   for(int i=0;i<n;i++)
   {
     cout<<arr[i]<<" ";
   }



   
}




// Quick sort for choosing middle elm as pivot (modified strivers algo by me!!!)

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr,int low , int high)
{
     int cpi = low + (high-low)/2;  // choosen pivot index
     int pivot = arr[cpi];

    int i,j;

    i=low;
    j=high;

     while(i<=j)
     {
        
        while(arr[i]<=arr[cpi] && i<=high)
        {
         i++;
        }

        while(arr[j]>=arr[cpi] && j>=low)
        {
         j--;
        }

        if(i<j)
        {
         iter_swap(arr.begin()+i , arr.begin()+j);
        }
        
     }

     if(cpi < j)
     {
     iter_swap(arr.begin()+cpi , arr.begin()+j);
     return j;
     }

     if(cpi>i)
     {
     iter_swap(arr.begin()+cpi , arr.begin()+i);
     return i;
     }


}

void quicksort(vector<int> &arr,int low , int high)
{
     if(low>=high)
     {
        return;
     }
     
   int pi = partition(arr,low,high);
   quicksort(arr,low,pi-1);
   quicksort(arr,pi+1,high);
}


int main()
{
    int n;

    cout<<"Enter the size of array : ";
    cin>>n;

    vector<int> arr(n,0);
 
    cout<<"Enter the elements into the array : ";
   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
   }

   quicksort(arr,0,n-1);

   cout<<"Sorted array : ";

   for(int i=0;i<n;i++)
   {
     cout<<arr[i]<<" ";
   }



   
}