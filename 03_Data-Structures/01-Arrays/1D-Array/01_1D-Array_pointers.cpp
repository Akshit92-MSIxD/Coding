#include <iostream>
using namespace std;
/// Relation between POINTERS and ARRAYS : ---
int main()
{
int arr[5]={10,20,30,40,50};  /// arr contain base address of array or 0 index and address of arr will also be same base address i.e [arr=&arr]
int *ptr;
ptr=arr; /// here we have not used ptr=&arr  , since arr (array-name) is itself a pointer that contains base address of array and points to 0th index of array

cout<<ptr<<" "<<&ptr<<" "<<arr<<" "<<&arr<<"\n\n"; /// arr contain base address of array or 0 index and address of arr will also be same base address i.e [arr=&arr]

for(int i=0;i<=4;i++)
{
cout<<arr[i]<<" "<<"or"<<" "<<*(arr+i)<<endl;/// we can write arr[i] as *(arr+i),*(arr+i)==>*(base address + i)==>*(base address + [sizeof_data_type(x)]*i)==>
}                                                                                                        /// ==>(value at address i.e x*i bytes further to base address)

cout<<endl;       /// we can add a integer decimal no. with address but cannot add two individual different address

for(int i=0;i<=4;i++)
{
    cout<<ptr[i]<<" "<<"or"<<" "<<*(ptr+i)<<"\n"; /// by using pointer ptr that also points to arr[0], we can easily access the array
}

}

