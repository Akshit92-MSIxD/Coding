// https://nados.io/article/print-stair-paths

// TC = O(3^n)
/*  SC = O(1) , if we consider the space taken by the recursion call stack, then space complexity will be O(n) as the maximum depth of the recursion    
    at any point can be equal to the length of the numeric string. */

#include <iostream>
#include <string>
using namespace std;

void printStairPaths(int ss , int ds , string ans)   // Modified signature by me :)
{
 
    if(ss==ds)
    {
        cout<<ans<<endl;;
        return;
    }

    if(ss>ds)
    {
        return;
    }


    printStairPaths(ss+1,ds,ans+'1');
    printStairPaths(ss+2,ds,ans+'2');
    printStairPaths(ss+3,ds,ans+'3');
 
}

int main(){

    int n;
    cin >> n;
    printStairPaths(0,n,"");
}




// --------------------------------------------------------------------------------------------------------------------------------------------------------



#include <iostream>
using namespace std;

void printStairPaths(int n, string psf){         // Signature Given by Pepcoding
    
    if(n==0)
    {
        cout<<psf<<endl;
        return;
    }

    if(n<0)
    {
        return;
    }


    printStairPaths(n-1,psf+'1');
    printStairPaths(n-2,psf+'2');
    printStairPaths(n-3,psf+'3');
    
    
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}
