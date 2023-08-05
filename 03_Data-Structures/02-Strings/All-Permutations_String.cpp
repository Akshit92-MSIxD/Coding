// https://nados.io/question/print-all-permutations-of-a-string-iteratively?zen=true
// USe other approaches too!!!
// Watch Solution video !!!


// Approach 1

#include<iostream>
#include<string>
using namespace std;

int calc_fact(int n)
{

    int fact = 1;

    while(n>1)
    {
        fact*=n;
        n--;
    }

    return fact;
}

void printallperm(string str)
{
    int  n = str.length();
    int no_of_perms =  calc_fact(n);

    for(int i=0;i<no_of_perms;i++)
    {

        string temp = str;
        int num = i;

        for(int div = n;div>=1;div--)
        {
            int rem = num%div;
            cout<<temp[rem];
            temp.erase(rem,1);
            num/=div;
        }

        cout<<endl;
      
    }
}
int main()
{
 string str;
 getline(cin,str);
 
 printallperm(str);
}






// Approach 2 (Search Find all permutations of given array iteratively!!!!) 

#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
    string str;
    vector<string> perm;

    getline(cin,str);

    string str_i;

    str_i = str[0];

    
    perm.push_back(str_i);



    for(int i=1;i<str.length();i++)
    {
         vector<string> temp_perm;
         str_i = str[i];

        for(int j=0;j<perm.size();j++)
        {
            int length = perm[j].length();
            string s = perm[j];

            for(int pos=0;pos<=length;pos++)
            {
                
               s.insert(pos,str_i);
               temp_perm.push_back(s);
               s = perm[j];
            }
        }
        perm = temp_perm;

    }


 for(int i=0;i<perm.size();i++)
 {
    cout<<perm[i]<<endl;
 }

}