// This question is somewhat similar to Previous Question(Print Zigzag)
// Draw Euler Tree to see how this recursive TOH is working!!!!
// (*) for n disks, a total of  2^n – 1 moves are required. 
// TC = O(2^n) , SC = O(1)
//Try Iterative approach using stack!!!

#include<iostream>
using namespace std;

void toh(int n, int A, int B, int C){

  if(n==0)
  {
    return;
  }

  toh(n-1,A,C,B);// suruwat ki n-1 disks ko C rode mai daaldo from A rode with the help of B rode (faith)

  cout<<n<<"["<<A<<" -> "<<B<<"]"<<endl; // self work (aakhri disk ko A se B mai daal diya)

  toh(n-1,C,B,A); // n-1 disks jo C rode mai hai unhe B rode mai daaldo with the help of A rode(faith)

  }

int  main() {

    int n;cin>>n;
    int n1,n2,n3;cin>>n1>>n2>>n3;
    toh(n, n1, n2, n3);
  }

