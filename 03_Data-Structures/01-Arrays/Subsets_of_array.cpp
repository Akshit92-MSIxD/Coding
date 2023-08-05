// Printing power set of array question !!!

// for n elements subsets = 2^n

// Add more better approaches later!!! using  "Recursion & Backtracking" and Hashing

// NOTE : This algorithm will result in printing duplicate subsets if there are duplicates present in
// the array. To avoid that, we can create a unique set of all subsets using hashing,  and insert all
// subsets in this unique set.


#include <bits/stdc++.h>
using namespace std;

int dec_to_bin(int num)
{
    int base = 2;

    int place = 1;
    int binary = 0;

    while(num!=0)
    {
        int rem = num%base;
        binary+=rem*place;
        num/=2;
        place*=10;
    }
    return binary;
}

void printSubsets(vector<int> arr) // T = O(2^n) , brute force
{
    int n = arr.size();
    int total_no_of_subsets = (int)(pow(2,n)+0.1);

    for(int i=0;i<total_no_of_subsets;i++)
    {
        int binary = dec_to_bin(i);
        int div = (int)(pow(10,n-1)+1e-8);

        for(int j=0;j<n;j++)
        {
            int digit = binary/div;

            if(digit==0)
            {
                cout<<"-\t";
            }
            else
            {
                cout<<arr.at(j)<<"\t";
            }

            binary%=div;
            div/=10;
        }
        cout<<endl;
    }

}
int main()
{
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }

    printSubsets(arr);
}