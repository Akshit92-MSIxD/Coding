// https://nados.io/question/print-zigzag?zen=true

// *==> Very Very Important for Recursion


    // Notes : 

    //    func(x)
    //   {
    //       --------- (Ye wala region tab chalta hai jab uppar ki taraf jate hai stack mai) (matlab ki jab stack bharta hai dheere dheere)

    //       func(x-1);

    //       -------- (ye wala region tab chalta hai jab hum niche ki taraf aate hai stack mai) (matlab ki jab stack khali hota hai dheere dheere)
    //   }


    //   func(x)
    //   {
    //       ------------ (Pre)
        

    //       func(x-1); (left call)


    //       ------------- (In)


    //       func(x-1); (right call)

    
    //       ------------- (Post)
    //   }
 
   // Euler Tree se kro ye problem jinme ek hi recursive func mai 1 se jyada function calls ho!!!!

#include<iostream>
using namespace std;


void pzz(int n){
    
    // base case
    if(n==0)
    {
        return;
    }

    cout<<n<<" "; // Pre

    pzz(n-1); // left call

    cout<<n<<" "; // In

    pzz(n-1); // right call

    cout<<n<<" "; // Post
    
}

int main(){
    int n; cin>>n;
    pzz(n);
}
