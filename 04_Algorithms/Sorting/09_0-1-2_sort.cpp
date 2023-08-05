#include <iostream>
using namespace std;
/// DUTCH NATIONAL FLAG PROBLEM , --->[Striver youtube channel}
void sort0_1_2(int arr[],int n)                                         /// TIME-COMPLEXITY = O[n] , SPACE-COMPLEXITY = O[1]
{
    int low=0 , high=n-1,mid=0;  /// [ 0 to low-1] mai 0 aaega
    while(mid<=high)              ///  [low to mid-1] mai 1 aaega
    {                             /// [mid to high] mai 2 aaega
       switch(arr[mid])
       {
       case 0: ///  truck wala i.e mid points to 0, ([arr[mid]=0)
        swap(arr[low++],arr[mid++]);

        break;

       case 1:  ///  truck wala  i.e mid points to 1 ,(arr[mid]=1)
           mid++;
           break;

       case 2: ///  truck wala i.e mid points to 2 , (arr[mid]=2)
           swap(arr[high--],arr[mid]);
           break;


       }
    }
return ;

}



int main()
{

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++)
    {
        cin>>arr[i];
    }
    sort0_1_2(arr,n);
    for(int i=0;i<=n-1;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;

}
