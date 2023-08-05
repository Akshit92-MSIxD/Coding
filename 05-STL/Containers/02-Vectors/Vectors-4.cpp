#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
                                                                                                              /* VERY VERY IMPORTANT */
    vector<int> v[N]; // array of vector<int> , matlab har element (v[i]) apne aap mai ek vector hoga !!!! , kinda 2D array hai par columns dynamic hai and rows fixed hai!!!

    for(int i=0;i<N;i++)
    {
        int num;
        cout<<"Enter the no. of integers you want to store in v["<<i<<"] vector element : ";
        cin>>num;

        for(int j=0;j<num;++j)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
        }
        cout<<endl;
    }


    cout<<endl<<endl;

   
   for(int i=0;i<N;i++)
   {
       cout<<"Elements stored in v["<<i<<"] vector element : ";
       for(int j=0;j<v[i].size();++j)
       {
           cout<<v[i].at(j)<<" ";
       }
       cout<<endl;
   }
 cout<<endl<<endl;


 cout<<(*v)[0]; // (since we know v is the name of array , so v point to its v[0] vector and *v points to base block of v[0] vector!!!  )
 cout<<(*v).at(1);
 cout<<(*v).at(2);


cout<<endl<<endl;


}