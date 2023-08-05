// https://nados.io/question/all-indices-of-array?zen=true
// T = O(n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
{

// base case
  if(idx == arr.size())
  {
    if(count == 0)
    {
      cout<<"NO OUTPUT";
    }
    vector<int> base(count,0);
    return base;
  }

   // self work
   vector<int> Arr;


   if(arr[idx]==data)
   {
     Arr = allIndex(arr,idx+1,data,count+1);
     Arr[count] = idx; // self work
   }
   else
   {
     Arr = allIndex(arr,idx+1,data,count);
   }

   return Arr;
}

int main() {
  int n ;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    arr.push_back(d);
  }
  int data;
  cin >> data;
  vector<int> ans = allIndex(arr, 0, data, 0);
  if (ans.size() == 0) {
    cout << endl;
    return 0;
  }
  for (int ele : ans) cout << ele << endl;

  return 0;
}


 // Solution by me : 

// vector<int> allIndex(vector<int>& arr, int idx, int data, int count)
// {
//    static vector<int> Arr;

// // base case
//   if(idx == arr.size())
//   {
//     if(count == 0)
//     {
//       cout<<"NO OUTPUT";
//     }
//     return Arr;
//   }


// // self work
//    if(arr[idx]==data)
//    {
//      Arr.push_back(idx);
//      count++;
//    }
    
//   // recursive case(faith)
//    Arr = allIndex(arr,idx+1,data,count);

//    return Arr;
// }