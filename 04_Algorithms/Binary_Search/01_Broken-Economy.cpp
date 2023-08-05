// https://nados.io/question/broken-economy?zen=true

// ceil : smallest value greater than equal to data
// floor : largest value less than equal to data

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;


    int low = 0 ,high = n-1,ceil=0,floor=0;

    while(low<=high)
    {
        int mid = low +(high-low)/2;

        if(arr[mid]==data)
        {
            ceil = floor = arr[mid];
            break;
        }
        else if(data > arr[mid])
        {
           low = mid + 1;
           floor = arr[mid]; 
        }
        else
        {
            high = mid - 1;
            ceil = arr[mid];
        }
    }

    cout<<ceil<<endl<<floor;


    
   
}