// https://nados.io/question/last-index?zen=true
// T = O(n)
#include <iostream>
using namespace std;

int lastIndex(int arr[], int idx, int x, int n){
    
    // base case
    if(idx == n)
    {
        return -1;
    }


    int li = lastIndex(arr,idx+1,x,n); // faith

   // self work
    if(li == -1)   //(Sabse pehle dost no jo bheja hai us hisab se decide hoga)
    {
        if(arr[idx] == x)
        {
            return idx;
        }
    } 
        return li;
}

int main(){
    int n;
    cin >> n;
    int d;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> d;
    int p = lastIndex(arr, 0, d, n);
    cout << p << endl;
}