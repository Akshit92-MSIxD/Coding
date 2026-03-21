 
 
 // TC for find() ≈ O(1) (amortized → some calls may be costly, but most are very fast, so average time is near constant, because of path compression)
// TC for union() ≈ O(1) (amortized → overall cost for union operations is spread out, so average time per union operation is very low, because of size + path compression)
// This approach is faster than previous implementation because of size and path compression !!!
// SC : O(n) (we use parent[] and size[] arrays)
// *** Note : This approach is more intuitive and widely used by Competitive programmers than  rank+path-compression approach !!!

 import java.io.BufferedReader;
 import java.io.InputStreamReader;
 import java.io.IOException;

 class DisjointSet
 {
    int n;
    int[] size;    // size[i] → number of nodes in the group whose leader is i
    int[] parent;

    DisjointSet(int n)
    {
      this.n = n;
      this.size = new int[n];
      this.parent = new int[n];

      for(int i=0;i<n;i++)
      {
         size[i] = 1;
         parent[i] = i;
      }
    }

    int find(int v)
    {
        if(v == parent[v])
        return v;

        return parent[v] = find(parent[v]);
    }

    void unionBySize(int v1, int v2)
    {
        int leader1 = find(v1);
        int leader2 = find(v2);

        if(size[leader1] >= size[leader2])
        {
            parent[leader2] = leader1;         // smaller group goes under bigger group
            size[leader1] += size[leader2];   // update size of new group
        }
        else if(size[leader1] < size[leader2])
        {
            parent[leader1] = leader2;         // smaller group goes under bigger group
            size[leader2] += size[leader1];   // update size of new group
        }
    }
 }


 class Solution{

 public static void main(String[] args) throws IOException
 {
     
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

     System.out.println("Enter the total no. of vertices/values");
     int n = Integer.parseInt(br.readLine()); // please enter 8

     DisjointSet  ds = new DisjointSet(n);

    // performing union operations (merging groups)
     ds.unionBySize(0,1);
     ds.unionBySize(1,2);
     ds.unionBySize(3,4);
     ds.unionBySize(5,6);
     ds.unionBySize(6,7);
     ds.unionBySize(4,5);
     ds.unionBySize(2,7);
     
  

      while(true)
      {
        System.out.print("\nEnter any two values/vertices to check if they lie in the same group or not : ");

        String[] nums = br.readLine().split(" ");
        int v1 = Integer.parseInt(nums[0]);
        int v2 = Integer.parseInt(nums[1]);

        if(ds.find(v1) == ds.find(v2))
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
     

