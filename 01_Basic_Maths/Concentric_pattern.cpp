#include <iostream>
using namespace std;


int main()
{
    int n;

    cin>>n;

    int rows , cols,i=0;

    rows=cols=2*n-1;


    for(int r=0;r<rows;r++)
    {
        for(int j=0;j<cols;j++)
        {
            if(j>=i && j<=cols-1-i)
            {
                cout<<n-i<<"\t";
            }
            
            else
            {
            int temp = n - j;

            if(n-j<=0){
                temp = -temp;
                temp+=2;
            }

            cout<<temp<<"\t";

            }

        }

        cout<<endl;
        r<(rows/2) ? i++:i--;
    }

}