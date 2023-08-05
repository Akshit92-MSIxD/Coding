#include<iostream>
using namespace std;
int AnyToDec(int n,int b){

  int power = 1 , digit , temp=n , sum=0;

    if(b==10)
    {
        return n;
    }
    else
    {
        while(temp!=0)
        {
        digit = temp % 10;
        sum = sum + digit*power;
        power*=b;
        temp/=10;
        }
    }

    return sum;



}
int main(){
    int n;
    int b;
    cin >> n;
    cin >> b;
    int res = AnyToDec(n,b);
    cout<<res<<endl;
}