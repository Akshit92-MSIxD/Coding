
// Vector of pair!!!
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    vector<pair<string,double>> vp; // OR vector<pair<string,double>> vp = { {"Akshit Rawat",19.2} , {"Ayush Rawat",17.7} , {"Hari Singh Rawat",47} };

    vp.push_back({"Akshit Rawat",19.2});  // OR can use make-pair(,) in place of { , }  !!!!
    vp.push_back(make_pair("Ayush Rawat",17.7));                                                                                    
    vp.push_back(make_pair("Hari Singh Rawat",47));                                     
    vp.push_back(make_pair("Sangeeta Rawat",41));                                     
    
    vp[2].first="Asmit Negi";   //  OR vp[2] = {"Asmit Negi",13}; , NOte : use at() function only to access the available positions , but dont use it  for insertion purpose!!!
    vp[2].second=13;
    
    cout<<"Pairs(elements) stored in a vector : ";

    for(int i=0;i<=3;i++)
    {
        cout<<"{"<<vp[i].first<<","<<vp[i].second<<"}  "; // Note :-  vp[i].first = vp.at[i].first  !!!!!! ;
    }

  
}