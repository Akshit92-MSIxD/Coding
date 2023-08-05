// TC(ac/wc) = O(n^2) , TC(bc) = O(n) [boolean swap variable ka use kro!!!!]
// SC = O(1)
#include<iostream>
using namespace std;


bool isSmaller(int arr[],int i,int j ){
    cout<<"Comparing "<<arr[i]<<" and "<<arr[j]<<endl;
    if(arr[i]<arr[j]){
        return true;
    }else{
        return false;
    }
}

void swap(int arr[],int i,int j){
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}


void bubbleSort(int arr[],int n){
    
    for(int c=0;c<=n-2;c++)
    {
        bool swap_once = false; // this thing makes the Best Case TC = O(n) !!!

       for(int i=0;i<=n-2-c;i++)
       {
           if(isSmaller(arr,i+1,i))
           {
           swap(arr,i+1,i);
           swap_once = true;
           }
       }

       if(swap_once==false)
       break;
    }
    
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}



int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    bubbleSort(arr,n);
    print(arr,n);
    
}