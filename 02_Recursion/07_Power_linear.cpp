// https://nados.io/question/power-linear?zen=true

#include<iostream>
using namespace std;

float power(int x,int n){

  if(n==0)
  {
    return 1;
  }
  
  if(x==1 || (x==0 && n>=1))
  {
    return x;
  }

    float ans;

  if(n>=1) // used to handle for postive(+) power of n!!!!
  {
     float xpnm1 = power(x,n-1);
     ans = xpnm1 * x*1.0;
  }
  else if(n<0) // used to handle for negative(-) power of n!!!!
  {
     float xpnp1 = power(x,n+1);
     ans = (1.0/x)*xpnp1;
  }

  return ans;

}


int main(){
    int n,x; cin>>x>>n;
    cout<<power(x,n);
    return 0;
}