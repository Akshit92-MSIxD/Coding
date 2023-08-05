// https://nados.io/question/max-of-an-array
// TC = O(n)
// SC = O(1)
//  If we consider the recursion space, it will be O(n) i.e. the maximum height of the recursion stack.

#include <iostream>
using namespace std;

int max(int arr[], int idx, int n){
    // write your code here

    if(idx==n-1)
    {
        return arr[n-1];
    }

    int max_no = arr[idx];

    int rem_max_no = max(arr,idx+1,n);

    if(rem_max_no > max_no)
    {
        max_no = rem_max_no;
    } 

    return max_no;
    
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int p = max(arr, 0, n);
    cout << p << endl;
}