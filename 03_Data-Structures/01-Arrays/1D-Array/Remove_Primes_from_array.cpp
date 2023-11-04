// https://nados.io/question/remove-primes?zen=true

#include<iostream>
#include<vector>
using namespace std;


bool is_prime(int num)
{
    for(int i = 2 ; i*i<=num ; i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    
    if(num == 0) // yaha pe num == 1 bhi aaega!!!
    {
    return false;
    }
    else
    {
        return true;
    }
}



void display(vector<int> &v)
{
    int length = v.size();

    cout<<"[";
    for(int i=0;i<=length-1;i++)
    {
        if(i<=length-2)
        cout<<v[i]<<", ";
        else
        cout<<v[i];
    }
    cout<<"]";
}



// Approach : Traversing vector from right to left (piche se) (preferred !!!!)
// #TimeComplexity: O(n2)
// #SpaceComplexity: O(1)

void removeprimes(vector<int> &v)
{
    int length = v.size();

    int counter = length - 1;

    while(counter>=0)
    {
       if(is_prime(v[counter]))
       {
         v.erase(v.begin() + counter); // v.begin() will return the iterator to 0th index , Takes linear time O(n) in worst case!!!!
       }
      counter--;
    }

    display(v);

}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    removeprimes(v);
}


/*------------------------------------------------------------------------------------------------------------------------------------------------*/



// https://nados.io/question/remove-primes

// YE sahi hai chinta na le!!!
// Vector::begin() and Vector::end() function TC = O(1)

/* Plese refer these articles :  */
//https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
// https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/


#include<iostream>
#include<vector>
using namespace std;


bool is_prime(int num)
{
    if(num == 0 || num==1)
    {
        return false;
    }

    for(int i = 2 ; i*i<=num ;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }

    return true;
}

void removeprimes(vector<int> &v)
{
     
    for(auto it=v.begin() ; it!=v.end();++it) // auto it ===  vector<int>::iterator it;
    {
        if(is_prime(*it))
        {
            v.erase(it);  // v.erase() ---> TC = O(1)
            --it;
        }
    }

}


void display(vector<int> &v)
{
    cout<<"[";
    for(auto it = v.begin();it!=v.end();++it)
    {
      cout<<*it;

      if(it!=v.end()-1)
      {
        cout<<", ";
      }
    }
    cout<<"]";
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    removeprimes(v);

    display(v);
}