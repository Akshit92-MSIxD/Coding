

// TC for find() ≈ O(1) (amortized → some calls may be costly, but most are very fast, so average time is near constant, because of path compression)
// TC for union() ≈ O(1) (amortized → overall cost for union operations is spread out, so average time per union operation is very low, because of rank + path compression)
// This approach is faster than previous implementation because of rank and path compression !!!
// SC : O(n) (we use parent[] and rank[] arrays)

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class DSU{

 int n;
 int[] rank;  // rank array → helps keep tree height small / it tells the "upper bound height" of the tree and not the current height !!!
 int[] parent;  // parent array → stores leader of each node


  DSU(int n){
    this.n = n;
    this.rank = new int[n];
    this.parent = new int[n];
    
     // Initially every node is its own parent and rank is 0
    for(int i=0;i<n;i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }

  }

 int find(int v)
 {     
       // if node is its own parent → it is the leader
      if(v == parent[v])
      return v;
      
      // path compression → while going up the tree , we make all nodes on the recursive path point directly to the leader to speed up future searches !!!
      // or we can say that this will flatten the tree or reduce the tree height !!!
      return parent[v] = find(parent[v]); 
 }

  // union function → merges two groups
 void union(int v1, int v2)
 {  
      // find leaders of both nodes
     int leader1 = find(v1);
     int leader2 = find(v2);
     
    // get ranks of both leaders
     int r1 = rank[leader1];
     int r2 = rank[leader2];

     if(r1 > r2)   
     {
        parent[leader2] = leader1;   // attach smaller rank rank tree under bigger rank tree or make leader 1 the direct parent of leader 2!!!
     }
     else if(r1 < r2)
     {
        parent[leader1] = leader2;  // "  " or make leader 2 the direct parent of leader 1!!!
     }
     else
     {
        parent[leader2] = leader1;    // choose anyone to be the new leader since their ranks are equal !!!
        rank[leader1]++;              // equal rank trees increase the height after getting merged/union with one another !!!
     }
 }
}

class Solution{

 public static void main(String[] args) throws IOException
 {
     
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

     System.out.println("Enter the total no. of vertices/values");
     int n = Integer.parseInt(br.readLine()); // please enter 8

     DSU  DSUobj = new DSU(n);

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
     

