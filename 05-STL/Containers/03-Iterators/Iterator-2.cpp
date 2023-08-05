#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v= {1,2,3,4,5,6};

    // Range based loop (ALternative easy and shortcut way to iterate through content of containers!!!)

    for(int &value : v)    // agar refrence use ni kroge to copy create hogi v vectors ke andar ki values ki!!!  
    {
        cout<<value<<" ";
    }
    cout<<endl<<endl;


//-------------------------------------------------------------------------------------------------------------------------------------------------------------


    vector<pair<int,int>> v_p = {{1,2},{3,4},{8,9},{0,1}};

    for(pair<int,int> &value : v_p)   // or auto &value : v_p      
    {
        cout<<value.first<<" "<<value.second<<endl;
    }



}