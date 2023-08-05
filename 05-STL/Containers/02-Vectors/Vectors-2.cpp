#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> v(5); // esa bhi kr sakte hai , 5 zeroes would be inserted from back (byDefault)!!! 
    
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;
    v.push_back(3);

    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }

    v[2]=2;
    cout<<endl;

    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl<<endl;


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    vector<int> vec(10,5);

    for(int i=0;i<vec.size();i++)
    {
        cout<<vec.at(i)<<" ";   // or v[i]
    }
     cout<<endl;


    vec.pop_back(); // O(1)


    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";  // or v.at(1);
    }
    cout<<endl<<endl<<endl;


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  /* Copying a vector into another vector!!!! */

  vector<int> vec1 = vec;  // O(n) !!! , both  vec1 and vec belongs to differnt memory locations(arrays) , changes in vec1 would not reflect in vec !!!
  vector<int> &vec2 = vec; // O(1) !!! , both vec2 and vec are alternative names to same vector/array !!! , changes in vec2 would reflect in vec or viceversa !!!
 

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


 vector<string> vs;

 int n;

 cout<<"Enter the no. of strings : ";
 cin>>n;

 for(int i=0;i<n;i++)
 {
     string s;
     cin>>s;
     vs.push_back(s);
 }

 for(int i=0;i<vs.size();++i)
 {
     cout<<vs.at(i)<<" ";
 }
 


}