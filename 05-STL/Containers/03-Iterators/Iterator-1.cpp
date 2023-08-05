// Iterator is basically a pointer like structure to a containter !!!!
#include <iostream>
#include <vector>

using namespace std;

int main()
{
     vector<int> v={1,2,3,4};

     vector<int> :: iterator it = v.begin(); // it is a iterator (pointer) to a vector<int> (container) base element !!! , v.begin()-->v[0]

     cout<<*(it)<<" "<<*(it+1)<<" "<<*(it+2)<<" "<<*(it+3);
     
     // NOTE : it++(useful in accessing Non-sequential containers ) means it will move to next iterator whereas it+1 means it will move to next location !!!

      for(it=v.begin() ; it!=v.end();it++) // .end() points to location next to last element(outside boundary)!!!
      {
           cout<<*(it)<<" ";
      }
      cout<<endl<<endl;

      vector<pair<int,int>> v_p = { {1,2},{5,6},{10,11},{-1,-2} };
      vector<pair<int,int>> :: iterator i; // we can write just -->  auto it (Compiler will automatically figure out!!!)

      for(i = v_p.begin();i!=v_p.end();i++)
      {
           cout<<(*i).first<<" "<<(*i).second<<endl; // OR (*i).first = i->first 
      }


}
