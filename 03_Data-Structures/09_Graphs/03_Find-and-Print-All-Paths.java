// In this Main we have to find and print all the paths from source vertex to destination vertex in lexicographical order !!!!
// https://www.youtube.com/watch?v=DrQ-eTN2v3A&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=10 (Please watch the Euler Tree explaination of this problem!!!)

 // Approach 1 : We will return all the paths in the form of ArrayList<String> 

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

class Solution{


 ArrayList<String> getAllPathsLexicographically(ArrayList<Main.Edge>[] graph, int src, int des, boolean[] vis)
 {
       if(src == des)
       {
           ArrayList<String> base = new ArrayList<>();
           base.add(Integer.toString(src));
           return base;
       }

       vis[src] = true;

       ArrayList<String> full_path = new ArrayList<>();

       for(Main.Edge ed : graph[src])
       {
           int nbr_v = ed.v2;
          ArrayList<String> nbr_paths = new ArrayList<>();

           if(!vis[nbr_v])
           {  
              nbr_paths = getAllPathsLexicographically(graph,nbr_v,des,vis);
               for(String nbr_path : nbr_paths)
               {
                   full_path.add(Integer.toString(src) + nbr_path);
               } 
           }
       }

       vis[src] = false; // mark this unvisited so that it can be used for other possible routes also

       return full_path;


 }

 void printAllPathsLexicographically(ArrayList<Main.Edge>[] graph, int src, int des)
 {
        boolean[] vis = new boolean[graph.length];
        ArrayList<String> paths = getAllPathsLexicographically(graph,src,des,vis);

        for(String p : paths)
        System.out.println(p); 
 }



}


class Main{

   static class Edge{

      int v1,v2,wt;

      Edge(int v1, int v2, int wt)
      {
        this.v1 = v1;
        this.v2 = v2;
        this.wt = wt;
      }

   }


  public static void main(String args[]) throws IOException{
     
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int v;
    v = Integer.parseInt(br.readLine());

    int e;
    e = Integer.parseInt(br.readLine());


    // create a adjacency list

    ArrayList<Edge>[] graph = new ArrayList[v]; // right side should be raw !!!

    // Initialize each block

    for(int i=0;i<v;i++)
    {
       graph[i] = new ArrayList<>();
    }


    // Entering and Storing Edges in Adjacency List !!!

    for(int i=0;i<e;i++)
    {
        String[] edge_parts = br.readLine().split(" ");
        int v1 = Integer.parseInt(edge_parts[0]);
        int v2 = Integer.parseInt(edge_parts[1]);
        int wt = Integer.parseInt(edge_parts[2]);

        graph[v1].add(new Main.Edge(v1,v2,wt));
        graph[v2].add(new Main.Edge(v2,v1,wt));
    }


    //  Create an object of class Solution

    Solution s = new Solution();
    
    s.printAllPathsLexicographically(graph, 0, v-1);

  }



}






/*------------------------------------------------------------------------------------------------------------------------------------------*/


// // Approach 2 : We will print all the paths once we reach basecase !!! 

// import java.io.BufferedReader;
// import java.io.InputStreamReader;
// import java.io.IOException;
// import java.util.ArrayList;

// class Solution{


//  void printDFS(ArrayList<Main.Edge>[] graph, int src, int des, String path_so_far, boolean[] vis)
//  {
//     if(src == des)
//     {
//       path_so_far = path_so_far + Integer.toString(des);
//       System.out.println(path_so_far);
//     }

//     vis[src] = true;
    
//     for(Main.Edge ed : graph[src])
//     {
//        int nbr_v = ed.v2;

//        if(!vis[nbr_v])
//        {
//           printDFS(graph,nbr_v,des,path_so_far + Integer.toString(src),vis);
//        }
//     }
    
//     vis[src] = false;
//     return;

//  }


//  void printAllPathsLexicographically(ArrayList<Main.Edge>[] graph, int src, int des)
//  {
//       boolean[] vis = new boolean[graph.length];
//       printDFS(graph,src,des,"",vis); 
//  }



// }


// class Main{

//    static class Edge{

//       int v1,v2,wt;

//       Edge(int v1, int v2, int wt)
//       {
//         this.v1 = v1;
//         this.v2 = v2;
//         this.wt = wt;
//       }

//    }


//   public static void main(String args[]) throws IOException{
     
//      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//     int v;
//     v = Integer.parseInt(br.readLine());

//     int e;
//     e = Integer.parseInt(br.readLine());


//     // create a adjacency list

//     ArrayList<Edge>[] graph = new ArrayList[v]; // right side should be raw !!!

//     // Initialize each block

//     for(int i=0;i<v;i++)
//     {
//        graph[i] = new ArrayList<>();
//     }


//     // Entering and Storing Edges in Adjacency List !!!

//     for(int i=0;i<e;i++)
//     {
//         String[] edge_parts = br.readLine().split(" ");
//         int v1 = Integer.parseInt(edge_parts[0]);
//         int v2 = Integer.parseInt(edge_parts[1]);
//         int wt = Integer.parseInt(edge_parts[2]);

//         graph[v1].add(new Main.Edge(v1,v2,wt));
//         graph[v2].add(new Main.Edge(v2,v1,wt));
//     }


//     //  Create an object of class Solution

//     Solution s = new Solution();
    
//     s.printAllPathsLexicographically(graph, 0, v-1);

//   }



// }
