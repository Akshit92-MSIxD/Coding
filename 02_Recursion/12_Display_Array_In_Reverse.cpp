// https://nados.io/question/display-array-in-reverse?zen=true

#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
   
   if(idx == n)
   {
     return;
   }

  display(arr,idx+1,n); // bhai pehle tu print krwade reverse mai (faith)
  cout<<arr[idx]<<endl; // mai sirf aakri mai apna starting index aakhri mai print krdunga!!! (self work)
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}