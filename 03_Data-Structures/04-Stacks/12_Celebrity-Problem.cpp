
// Hint : Use elimination technique to eliminate 1 candidate out of 2 candidates for becoming the potential celebrity :)

/* Hint : Just keep in mind that we have to find the potential celebrity first(may or may not be a celebrity) then check
 if he/she is really a celebrity or not :) */

// Note : First read brute force by me under submissions in GFG :)

//****Best optimal approach for this problem : Two pointers approach(i=0 and j=n-1 ....think :)  read gfg two pointer approach :))

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1( Brute force by me  + optimal approach using stacks)

/* Instead of using stack space, we can also solve it using Two Pointers or Recursion. But the algorithm will remain the same, i.e. we will 
have to follow the elimination approach. [Time Complexity: O(N), The recursive function is called n times.
                                         Auxiliary Space: O(N), Recursive call of N times use stack of size N.]

It is just that two pointers will work on the matrix itself to eliminate the candidates and will be taking constant O(1) extra space .

Consider the case when we are not given with the matrix (array of strings), instead given an API to check whether person i knows person j.
In this case, the two-pointer approach (which we have not discussed) will not work (as it works on the matrix itself). Hence, only stack
or recursive solutions will work, which will take O(n) space. */

// This problem can also be solved using GRAPHS :)