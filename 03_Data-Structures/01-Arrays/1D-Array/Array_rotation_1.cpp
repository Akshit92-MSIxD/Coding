#include<iostream>
using namespace std;

void rotate(int* arr, int n, int k){

k = k % 10;

if(k<0)
{
    k+=n;
}


for(int rot = 0 ; rot<k;rot++)
{
   int temp = arr[n-1];

    for(int i = n-1;i>0;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    }
 }


void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, r;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    cin>>r;
    
    rotate(arr,n,r);
    display(arr,n);
}



// k = k % 10;
// if(k<0)
// {
//     k+=n;
// }
//    reverse the array!!!!

// for(int i=0;i<=n-1;i++)
// {
//     int temp = arr[i];
//     arr[i] = arr[n-i-1];
//     arr[n-i-1] = temp;
// }

//  revrse first k elements

// for(int i=0;i<k;i++)
// {
//     int temp = arr[i];
//     arr[i] = arr[k-1-i];
//     arr[k-i-1] = temp;
// }

//   reverse remaining n-k elements!!!!

// for(int i=0;i<(n-k)/2;i++)
// {
//     int temp = arr[k+i];
//     arr[k+i] = arr[n-1-i];
//     arr[n-1-i] = temp;
// }