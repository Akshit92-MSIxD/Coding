//Brute force T = O(n2)
#include <iostream>  
#include <vector>
using namespace std;


void input(vector<int> &v , int n)
{
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
}

void selection_sort(vector<int> &v)  // using Selection Sort (O(n2))
{
    for(int i=0;i<v.size()-1;i++)
	{
		int min_index=i;
		for(int j=i+1;j<v.size();j++)
		{
			if(v[j]<v[min_index])
			{
                  min_index=j;
			}
		}
    int temp = v[i];
    v[i] = v[min_index];
    v[min_index]=temp;
	}
}

int main()
{

vector<int> v;

int n;
cin>>n;

input(v,n);

selection_sort(v);

cout<<"Second Maximum element : "<<v[n-2]<<endl;
cout<<"Second Minimum element : "<<v[1]<<endl<<endl;


return 0;

}

/* Better solution T = O(n) */

// #include <climits>   

// 	int max=INT_MIN , max2=INT_MIN, min=INT_MAX ,min2=INT_MAX,n;

// for(int i=0;i<v.size();i++)
// 	{
// 		if(v[i]>max)
// 		{
// 			max2=max;
//             max=v[i];
// 		}
// 		else if(v[i]>max2)
// 		{
//            max2=v[i];
// 		}
		
// 		if(v[i]<min)
// 		{
// 			min2=min;
//             min=v[i];
// 		}
// 		else if(v[i]<min2)
// 		{
//             min2=v[i];
// 		}
		
// 	}


