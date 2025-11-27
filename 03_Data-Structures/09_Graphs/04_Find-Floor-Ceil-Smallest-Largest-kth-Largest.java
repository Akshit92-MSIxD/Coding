// import java.io.BufferedReader;
// import java.io.InputStreamReader;
// import java.io.IOException;
// import java.util.ArrayList;

// class Solution{
    
//     Main.Path  getSmallestPathObject(ArrayList<Main.Edge>[] graph, int src, int des, boolean[] vis)
//     {
//         if(src == des)
//         return (new Main.Path(Integer.toString(des),0));

//         vis[src] = true;

//         Main.Path ans = new Main.Path("",10000000); // We could have used Integer.MAX_VALUE in place of 10000000 but it would lead to overflow in case of vertex which is not visited but we cannot visit its neighbour !!!! (Please make euler tree to understand this better!!!) 
        
//         for(Main.Edge ed: graph[src])
//         {
//             int nbr_v = ed.v2;
//             Main.Path subans = null;

//             if(!vis[nbr_v])
//             {
//               subans = getSmallestPathObject(graph,nbr_v,des,vis);

//                if((subans.weight + ed.wt) <= ans.weight)
//                {
//                  ans.weight = subans.weight + ed.wt;
//                  ans.seq = Integer.toString(src) + subans.seq;
//                }
//             }

//         }

//             vis[src] = false;
//             return ans;

//     }
     
//     Main.Path getSmallestPath(ArrayList<Main.Edge>[] graph, int src, int des)
//     {     
//          boolean[] vis = new boolean[graph.length];
//           return getSmallestPathObject(graph,src,des,vis);
//     }

// }

// class Main{


//     static class Edge{

//         int v1,v2,wt;

//         Edge(int v1, int v2, int wt)
//         {
//             this.v1 = v1;
//             this.v2 = v2;
//             this.wt = wt;
//         }


//     }

//     static class Path{
      
//       String seq;
//       int weight;

//       Path(String seq, int weight)
//       {
//         this.seq = seq;
//         this.weight = weight;
//       }

//     }

  

//    public static void main(String args[]) throws IOException{

//      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//      int v;
//      v = Integer.parseInt(br.readLine());

//      int e;
//      e = Integer.parseInt(br.readLine());

//      ArrayList<Main.Edge>[] graph = new ArrayList[v];

//      for(int i=0;i<v;i++)
//      graph[i] = new ArrayList<>();

//      for(int i=0;i<e;i++)
//      {
//         String[] edge_parts = br.readLine().split(" ");
//         int v1 = Integer.parseInt(edge_parts[0]);
//         int v2 = Integer.parseInt(edge_parts[1]);
//         int wt = Integer.parseInt(edge_parts[2]);

//         graph[v1].add(new Edge(v1,v2,wt));
//         graph[v2].add(new Edge(v2,v1,wt));
//      }

//      Solution s1 = new Solution();
     
//      Path small_path = s1.getSmallestPath(graph,0,v-1);

//      System.out.println("Smallest Path : "+small_path.seq+"@"+small_path.weight);
     




//    }


// }


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.PriorityQueue;

class Solution{

    static class Pair{

        String path;
        int wt;

        Pair(String path, int wt)
        {
            this.wt = wt;
            this.path = path;
        }
    }

    static String spath; 
    static int spathwt = Integer.MAX_VALUE;;

    static String lpath;
    static int lpathwt = Integer.MIN_VALUE;;

    static String cpath;
    static int cpathwt = Integer.MAX_VALUE;

    static String fpath;
    static int fpathwt = Integer.MIN_VALUE;

    PriorityQueue<Pair> pq = new PriorityQueue<>((p1,p2)->p1.wt-p2.wt);

    
    void  dfs(ArrayList<Main.Edge>[] graph, int src, int des,int criteria,int k, boolean[] vis, String psf, int wtsf) // psf : path_so_far , wtsf : weight_so_far  
    {
           if(src == des)
           {
               if(wtsf < spathwt)
               {
                spathwt = wtsf;
                spath = psf;
               }
               else
               {
                 lpathwt = wtsf;
                 lpath = psf;
               }

               if(wtsf > criteria && wtsf < cpathwt)
               {
                cpathwt = wtsf;
                cpath = psf;
               }

               if(wtsf < criteria && wtsf > fpathwt)
               {
                fpathwt = wtsf;
                fpath = psf;
               }


               if(pq.size() < k)
               {
                     pq.add(new Pair(psf,wtsf));
               }
               else
               {
                      if(pq.peek().wt < wtsf)
                      {
                        pq.add(new Pair(psf,wtsf));
                        pq.poll(); // we can use remove() also but it throws exception  when PQ is empty
                      }
               }


  
           }

           vis[src] = true;

           for(Main.Edge ed : graph[src])
           {
               int nbr_v = ed.v2;
               int wt_with_nbr_v = ed.wt;

               if(!vis[nbr_v])
                   dfs(graph,nbr_v,des,criteria,k,vis,psf+Integer.toString(nbr_v),wtsf+wt_with_nbr_v);
           }

           vis[src] = false;
           return;
    }
     
     void multisolver(ArrayList<Main.Edge>[] graph, int src, int des, int criteria, int k)
    {     
         boolean[] vis = new boolean[graph.length];

           dfs(graph,src,des,criteria,k,vis,Integer.toString(src),0);

           System.out.println("Smallest path  : "+spath+"@"+spathwt);
           System.out.println("Largest path  : "+lpath+"@"+lpathwt);
           System.out.println("Just larger path than "+criteria+ " : "+cpath+"@"+cpathwt);
           System.out.println("Just smaller path than "+criteria+ " : "+fpath+"@"+cpathwt);
           System.out.println(k+"th largest path : "+pq.peek().path+"&"+pq.peek().wt);  
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

     ArrayList<Main.Edge>[] graph = new ArrayList[v];

     for(int i=0;i<v;i++)
     graph[i] = new ArrayList<>();

     for(int i=0;i<e;i++)
     {
        String[] edge_parts = br.readLine().split(" ");
        int v1 = Integer.parseInt(edge_parts[0]);
        int v2 = Integer.parseInt(edge_parts[1]);
        int wt = Integer.parseInt(edge_parts[2]);

        graph[v1].add(new Edge(v1,v2,wt));
        graph[v2].add(new Edge(v2,v1,wt));
     }

     int src,des,criteria,k;
      
      src = Integer.parseInt(br.readLine());
      des = Integer.parseInt(br.readLine());
      criteria = Integer.parseInt(br.readLine());
      k = Integer.parseInt(br.readLine());


     Solution s1 = new Solution();
      s1.multisolver(graph,src,des,criteria,k);

   }

}