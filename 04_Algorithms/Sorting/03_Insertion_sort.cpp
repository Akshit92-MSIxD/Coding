// TC(ac/wc) = O(n^2) , TC(bc) = O(n)
// SC = O(1)
// Left side sorted  , right side unsorted and insert accordingly using reverse bubbling!!!!
#include<iostream>
using namespace std;


bool isGreater(int arr[],int j,int i ){
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


void insertionSort(int arr[],int n){
  
  for(int i=1;i<=n-1;i++)
  {

      for(int j=i;j>0;j--)
      {
          if(isGreater(arr,j-1,j))
          {
          swap(arr,j-1,j);
          }
          else
          {
          break;
          }
      }
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
    
    insertionSort(arr,n);
    print(arr,n);
    
}