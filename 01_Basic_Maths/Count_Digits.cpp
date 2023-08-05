#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;

    int count=0;
   
    while(n)   // for(int i=n;i!=0;i=i/10)           // for only n>=1
    {          //  count++;
       count++;
       n/=10;
    }
    cout<<count;
    
}