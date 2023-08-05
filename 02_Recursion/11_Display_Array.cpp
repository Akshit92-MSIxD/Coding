// https://nados.io/question/display-array?zen=true

#include <iostream>
using namespace std;

void display(int arr[], int idx, int n){
   
   if(idx==n)
   {
     return;  
   }

   cout<<arr[idx]; // mai apna starting index pehle print kr deta hu (self work)
   display(arr,idx+1,n); // baaki ka tu sambhal liyo!!! (faith)
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    display(arr, 0, n);
}