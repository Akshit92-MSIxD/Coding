#include <iostream>
#include <vector>
using namespace std;

// Approach 1

vector<vector<int>> return_permutations(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> perm;

    perm.push_back({arr[0]});

    for(int i=1;i<n;i++)
    {
        vector<vector<int>> temp_perm;

        for(int j=0;j<perm.size();j++)
        {
               int length = perm[j].size();
               vector<int> temp = perm[j];

               for(int k=0;k<=length;k++)
               {
                  temp.insert(temp.begin()+k,arr[i]);
                  temp_perm.push_back(temp);
                  temp = perm[j];
               }
        }

        perm = temp_perm;
    }

    return perm;

}

int main()
{
    int n;
    cin>>n;

    vector<int> arr(n,0);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<endl<<endl;

    vector<vector<int>> perm = return_permutations(arr);
    
    vector<vector<int>> :: iterator it;
    
    for(it = perm.begin();it!=perm.end();it++)
    {
        for(int j=0;j<perm[0].size();j++)
        {
            cout<<(*it)[j]<<" ";
        }
        cout<<endl;

     }

   cout<<endl<<perm.size();
}



// Approach 2


