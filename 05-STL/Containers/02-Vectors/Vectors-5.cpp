#include <iostream>
#include <vector>
using namespace std;


int main()
{
    /* CASE 1 : INPUT AT COMPILE TIME (EASY!!!) */


                vector< vector<int> > vec ; // kinda 2d array hai but rows and columns dynamic hai!!!


                vec={{1,2,3,4} , {10,20,30,40} , {100,200,300,400,500}}; // Input dene ka ek tarika compile time pe !!!

                cout<<vec.size()<<endl;

                vec.push_back({-1,-2,-3,-4,-5}); // pushing new vector elment vec[3] inside the vector !!!

                cout<<vec.size()<<endl;

                for(int i=0;i<vec[0].size();++i)
                {
                    cout<<vec[0][i]<<" ";
                }
                cout<<endl; 
                
                vec[0].push_back(5); // agr hum vec[0][4]=5 krte to 5 to chale jata 4th index pe but v.size() apne ko change ni krta (NOT RECOMMENDABLE!!!)

                cout<<vec[0].size()<<endl;

                for(int i=0;i<vec[0].size();++i)
                {
                    cout<<vec[0][i]<<" ";
                }
 

                                                                                 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



    /* CASE 2 : INPUT AT RUNTIME (EASY BUT TRICKY THAN ABOVE CASE !!!!) , endl goal is to pushback a vector of int  inside a vector!!! */

             

                vector<vector<int>> v;

                int N;
                cout<<"\nEnter the no. of vector<int> elements you want to store in a vector : ";
                cin>>N;   
                cout<<endl;
        

        // Function for taking input : 

                for(int i=0;i<N;i++)
                {
                      vector<int> temp;
                      int n;

                      cout<<"Enter the number of integer elements you want to store in a vector v["<<i<<"] : " ;
                      cin>>n;

                      for(int j=0;j<n;++j)
                      {
                             int x;
                             cin>>x;
                             temp.push_back(x);    
                      }

                      v.push_back(temp);

                }
                cout<<endl<<endl;



        // Function for printing elements : 

                for(int i=0;i<v.size();i++)
                {
                   cout<<"Elements in vector v["<<i<<"] : ";
                   for(int j=0;j<v[i].size();++j)
                   {
                     cout<<v[i][j]<<" ";
                   }
                   cout<<endl;
                }

                cout<<endl;


}