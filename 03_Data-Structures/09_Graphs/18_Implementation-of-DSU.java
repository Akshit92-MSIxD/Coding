
/* 
 This approach becomes very slow for large inputs.

 Example:
 If number of nodes = 10^5
 and we perform 10^5 union operations,

 Each union takes O(n) ≈ 10^5 time,
 So total work = 10^5 × 10^5 = 10^10 operations

 This is too large and will cause TLE (Time Limit Exceeded)   */




// TC for find() = O(n)  → in worst case, we may go through all nodes
// TC for Union() = O(n) → because find() is called inside it
// SC : O(n) → we use an array of size n

import java.io.BufferedReader; // used to take input efficiently
import java.io.InputStreamReader; // helps BufferedReader read input from Keyboard
import java.io.IOException;

class DSU{

int n;
int parent[];  // stores parent of each node

 DSU(int n , int[] parent){
   this.n = n;
   this.parent = parent;
 }

// find function → returns the ultimate leader (root) of a node
int find(int v)
{
    // if node is its own parent → it is the leader
   if(v == parent[v])
   return v;
    
   // otherwise go to its parent recursively
   return find(parent[v]);
}

// union function → merges two groups
void union(int v1, int v2)
{
    
    int leader1 = this.find(v1); // find leader of node(v1) or group which v1 belongs to !!!
    int leader2 = this.find(v2); // find leader of node(v2) or group which v2 belongs to !!!
   
  // if both leaders are different → they belong to different groups
    if(leader1 != leader2)
        parent[leader2] = leader1;  // connect second group under first group

}

}


class Solution{

 public static void main(String[] args) throws IOException
 {
     
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

     System.out.println("Enter the total no. of vertices/values");
     int n = Integer.parseInt(br.readLine()); // please enter 8

     int[] parent = new int[n];
     
    // Initially, every node is its own parent (separate groups)
     for(int i=0;i<n;i++)
      parent[i] = i;

     DSU  DSUobj = new DSU(n, parent);

    // performing union operations (merging groups)
     DSUobj.union(0,1);
     DSUobj.union(1,2);
     DSUobj.union(3,4);
     DSUobj.union(5,6);
     DSUobj.union(6,7);
     DSUobj.union(4,5);
     DSUobj.union(2,7);
     
  

      while(true)
      {
        System.out.print("\nEnter any two values/vertices to check if they lie in the same group or not : ");

        String[] nums = br.readLine().split(" ");
        int v1 = Integer.parseInt(nums[0]);
        int v2 = Integer.parseInt(nums[1]);

        if(DSUobj.find(v1) == DSUobj.find(v2))
        System.out.println("Result : Same group !!!");
        else
        System.out.println("Result : Different group !!! ");

        System.out.print("\nDo you want to check for more values ? (Yes/No) : ");
        String response = br.readLine();

        if(response.equals("No"))
        break;

      }

 }
}
     

