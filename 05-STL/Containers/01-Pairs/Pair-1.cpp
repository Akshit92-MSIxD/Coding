

// Pair is a container!!! 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int,string> p;                                                                         // same as int a=9;
     p = {19,"Akshit Rawat"}; // OR  p = make_pair(19,"Akshit Rawat");
    cout<<p.first<<" "<<p.second<<endl;

     pair<int,string> &p1=p;                                                                    //  same as --> int &b=a; (pass by refrence)
     cout<<p1.first<<" "<<p1.second<<endl;                                                      // cout<<b<<endl;;
     p1.first=17.8 , p1.second="Ayush Rawat";                                                   // b=45; 
     cout<<p.first<<" "<<p.second<<endl<<endl;                                                  // cout<<a;

     int a[]={1,2,3};    // corresponding indices in a[] and b[] are related!!!!
     int b[]={1,4,9};

    /* Not Recomendable!!! , instead use vector<pair<int,int>> i.e VECTOR OF PAIR */
     pair<int,int> p_array[3]; // array of pair OR  pair<int,int> p_array[3]={{1,1},{2,4},{3,9}};

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
   

   
    // DEFAULT INPUT AT COMPILE TIME

            //  p_array[0]={1,1};    OR    p_array[0] = make_pair(1,1)
            //  p_array[1]={2,4};    OR    p_array[1] = make_pair(2,4)
            //  p_array[2]={3,9};    OR    p_array[2] = make_pair(3,9)



    // USER INPUT AT RUNTIME
 
          cout<<"Please input the related elements(pairs) from a[] and b[] : "<<endl<<endl;

            for(int i=0;i<=2;i++) 
            {
                cin>>p_array[i].first>>p_array[i].second; // input  corresponding related index elements from a[] and b[] !!!
            }
            cout<<endl<<endl;


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/            

           
            for(int i=0;i<=2;i++)
            {
                cout<<p_array[i].first<<"  "<<p_array[i].second<<endl;
            }
                                                                                      
            swap(p_array[0],p_array[2]);
            cout<<endl<<endl;

            for(int i=0;i<=2;i++)
            {
                cout<<p_array[i].first<<"  "<<p_array[i].second<<endl;
            }



}

