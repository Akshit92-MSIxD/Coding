#include <iostream>
using namespace std;
int main()
{
    int n, first , second , next = 0,sum=0;;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Fibonacci Series: ";
    for (int i = 1; i <= n; i++)
    {
        if(i == 1)
        {
            cin>>first;
        cout <<first;
            continue;
        }
        if(i == 2)
        {
            cin>>second;
            cout <<" "<<second;
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        sum=sum+second;

        cout <<" "<<next;
    }
    cout<<endl;
    cout<<"Sum of fibonacci series is : "<<sum+1;
}

