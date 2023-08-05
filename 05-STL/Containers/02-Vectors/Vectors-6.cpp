#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<vector<vector<int>>> v;

//kinda 3D array , jaha har element 2D array jesa hai jisme har element apni rows and column ko kam jyada kr sakta hai , also bot saree 2D array bana sakte hai bina size diye!!

    v = {   { {1,2,3,4} , {10,20,30,40} }   ,   { {-1,-2,-3,-4} , {10,11,12} , {0,1,0} , {8,8}}   ,   { {-4,-8,-16,-32} , {0,100,200} }  } ;


    cout<<v.size()<<endl;

    v.push_back({{5,5,5,5},{20,20,20,20}});

    cout<<v.size()<<endl;

    


/* CASE : INPUT AT RUNTIME (EASY BUT TRICKY!!!!) , endl goal is to pushback a vector of vector of int inside a vector!!! */


       vector<vector<vector<int>>> vec;

       int N;

       cout<<"Enter the no. of vector<vector<int>> elements you want to store in a vector : ";
       cin>>N;
       cout<<endl;



       // Function for taking input :

        for(int i=0;i<N;++i)
        {
            vector<vector<int>> TEMP;
            int n;

            cout<<"Enter the no. of vector<int> elements you want to store inside vector<vector<int>> : ";
            cin>>n;

            for(int j=0;j<n;++j)
            {
                vector<int> temp;

                int num;

                cout<<"Enter the no. of integer elements you want to store inside  vector<int> : ";
                cin>>num;

                for(int k=0;k<num;++k)
                {
                    int x;
                    cin>>x;
                    temp.push_back(x);
                }

                TEMP.push_back(temp);     
            }

            vec.push_back(TEMP);
            cout<<endl;
        }

        cout<<endl<<endl;



     // Function for printing elements : 

     for(int i=0;i<vec.size();++i)
     {
         cout<<" Elements in vec["<<i<<"] vector : \n\n";
         for(int j=0;j<vec[i].size();++j)
         {
             cout<<"Elements in vec["<<i<<"]["<<j<<"] vector : ";
             for(int k=0;k<vec[i][j].size();++k)
             {
                 cout<<vec[i][j][k]<<" ";
             }
             cout<<endl;
         }
         cout<<endl<<endl;
     }






}

