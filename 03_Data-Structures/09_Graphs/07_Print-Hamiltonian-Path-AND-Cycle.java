// Hamiltonian Path : A path in a graph that visits every vertex exactly once.
// Hamiltonian Cycle : A cycle in a graph that visits every vertex exactly once and and has an edge connecting the last vertex back to the starting vertex.

// ***** https://www.geeksforgeeks.org/problems/hamiltonian-path2522/1 (Based on Hamiltonian path) 
// ***** https://leetcode.com/problems/unique-paths-iii/ (Although a normal DFS + Backtracking Question but concept is somewhat related !!!)

// TC : O(V!) [worst case will be this much in case of a complete graph] --> Please draw a recursive tree for this and then find TC !!!
// SC : O(V+E) , O(V) [ recursive stack space]

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;


class Solution{
            // TC : O(V!)
   void dfs(ArrayList<ArrayList<Integer>> graph, int curr_v , int orgSrc, int count_visNodes, String psf, boolean[] vis)
   {   
        vis[curr_v] = true;

       if(count_visNodes == graph.size()) // if this is true --> every vertice/node has been visited exactly once
       {
           boolean hasCycle = false;

           for(int nbr_v : graph.get(curr_v))
           {
              if(nbr_v == orgSrc)
              {
                 hasCycle = true;
                 break;
              }
           } 
       
       if(hasCycle == true)
       {
       System.out.println(psf+"*");
       }
       else
       {
        System.out.println(psf);
       }

       }
   

       for(int nbr_v : graph.get(curr_v))
       {
           if(!vis[nbr_v])
           {
            dfs(graph,nbr_v,orgSrc,count_visNodes+1,psf+nbr_v,vis);
           }
       }


       vis[curr_v] = false;
       
   }


  void printHamiltonianPathAndCycle(ArrayList<ArrayList<Integer>> graph)
  {
      boolean[] vis = new boolean[graph.size()];

      for(int i=0;i<graph.size();i++)
          dfs(graph,i,i,1," " + i,vis);
  }

}

 // Driver Code

class Main{

 public static void main(String args[]) throws IOException{

   BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

   int v;
   v = Integer.parseInt(br.readLine());

   int e;
   e = Integer.parseInt(br.readLine());

   
   ArrayList<ArrayList<Integer>> graph = new ArrayList<>();

   for(int i=0;i<v;i++)
   {
     graph.add(new ArrayList<>());
   }


   for(int i=0;i<e;i++)
   {
      String edge = br.readLine();

      int v1 = Integer.parseInt(edge.split(" ")[0]);
      int v2 = Integer.parseInt(edge.split(" ")[1]);

      graph.get(v1).add(v2);
      graph.get(v2).add(v1);
   }


   Solution s1 = new Solution();
   s1.printHamiltonianPathAndCycle(graph);
  
 }


}