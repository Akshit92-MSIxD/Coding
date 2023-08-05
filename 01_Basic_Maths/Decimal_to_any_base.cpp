#include<iostream>
using namespace std;
int DecToAny(int n, int b){

     int temp = n , digit , sum=0 , power=1;
                                                   
                                                   
     if(b==10)
     {
         return n;
     }
     else
     {
        while(temp!=0)
        {
             digit = temp % b;
             sum = sum + digit*power;
             power*=10;
             temp = temp/b;  
        }

        return sum;
     }
}
int main(){
    int n;
    int b;
    cin >> n;
    cin >> b;
    int res = DecToAny(n,b);
    cout << res << endl;
}