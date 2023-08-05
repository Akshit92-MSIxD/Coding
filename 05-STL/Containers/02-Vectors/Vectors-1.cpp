// Vector is an array with dynamic size!!!

#include <bits/stdc++.h>
using namespace std;

void print_Vector(vector<int> v)  // passing vector by value!!!
{
   cout<<"size of vector : "<<v.size()<<endl;   // v.size()-->O(1)

   for(int i=0;i<v.size();++i)
   {
     cout<<v.at(i)<<"  ";  // OR  vector<int> ko print krne ke liye normal v[index] wala method bhi use kr sakte hein !!!!!
   }

   cout<<endl<<endl;

}

void input_value(vector<int> &v)   // passing vector by reference!!!!
{
    int num;
    cout<<"Please Enter how many values do you want to store sequentially in a vector : ";
    cin>>num;

    for(int i=0;i<num;++i)
    {
        int x;
        cin>>x;
        print_Vector(v); // optional(Concept!!!) statement!!!
        v.push_back(x); // vector mai hum directly input ni le sakte !!!!
    }
}

int main()
{
 
 vector<int> v;       // same as int v[?]; but with dynamic size!!!! , vector of int means  dynamic array of int!!! , abhi ke liye v ka size zero hai!!!
 input_value(v);
 print_Vector(v);

 vector<pair<int,int>> vp;     // vector of pair means dynamic array of pairs!!!! 




}