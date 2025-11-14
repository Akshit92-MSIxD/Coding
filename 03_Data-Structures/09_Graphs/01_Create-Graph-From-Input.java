
// Basically in this code we are trying to implement adjacency list to represent graph !!!
// In this code you will see important concepts about BufferedReader , InputStreamReader, System.in and readLine() of BufferedReader class
// *** IMP : Please read every comment in this code !!!!
// In Java everything is treated as  an object that means variables(identifiers) of non-primitive types store references(pointers/addresses) to actual object not the actual values except primitive types : byte , short , int , float , char , double , boolean !!!
// Reference varibles(of non-primitive types) can be stored on heap or stack but the actual objects they refer to is always stored on the heap in java!!!!
// Make sure to intialize each reference varible of non-primitive type using new keyword(or another initializer) before using it otherwise it will cause a runtime error in java !!!


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;


 class Solution{

 // Make Edge static so main (static) can create Edge objects without an instance of Solution !!!
 static class Edge{

       Edge(int v1, int v2 , int wt)
       {
         this.v1 = v1;
         this.v2 = v2;
         this.wt = wt;
       }
      int v1;   
      int v2;
      int wt;
  }


 public static void main(String[] args) throws IOException
 {
   // System.in reads/return data from console in byte(raw) format --> InputStreamReader --> convert each byte/group_of_bytes into different character --> BufferedReader --> will arrage those characters and return a single text/string until it founds newline character !!!
   BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
   
   System.out.println("\nEnter the total number number of vertices : ");
   int v = Integer.parseInt(br.readLine()); // graph vertices

   System.out.println("Enter the total number number of edges : ");
   int e = Integer.parseInt(br.readLine()); // graph edges

   System.out.println();


// This creates an array of size 'v' on the heap.
// Each element of this array is meant to hold a separate ArrayList<Edge> reference,
// but right now all of them are null.
   ArrayList<Edge>[] graph = new ArrayList[v];  // This is adjacency list !!! , ArrayList[v] we cannot write ArrayList<Edge>[v] (since in java create an array of raw type is allowed only !!!)


 // Now we allocate memory for each individual ArrayList<Edge> object. (Everything in Java is an object except primitive types!!!)
// This ensures every slot in the 'graph' array points to a valid, empty ArrayList<Edge>.
   for(int i=0;i<v;i++)
   {
    graph[i] = new ArrayList<Edge>(); // this will create an empty  ArrayList<Edge> object on heap and then assign its reference to graph[i] !!!
   }

   // Now its time to create different objects of type Edge and assign their reference to required vertices !!!
   
   for(int i=0;i<e;i++)
   {
      
      String[] edge_info = br.readLine().split(" "); // br.readline() will return edge as a single text/string(including space) and split() will split that single string based on spaces in that single text and return array of new strings !!!
      int v1 =  Integer.parseInt(edge_info[0]);
      int v2 =  Integer.parseInt(edge_info[1]);
      int wt =  Integer.parseInt(edge_info[2]);

      graph[v1].add(new Edge(v1,v2,wt)); // storing edge(v1 to v2) at vertex v1 in graph array !!!
      graph[v2].add(new Edge(v2,v1,wt)); // storing edge(v2 to v1) at vertex v2 in graph array !!!
   }

       System.out.println();

   // Now its time to print all the edges from a particular vertex for all vertices !!!

   for(int i=0;i<graph.length;i++)
   {  
       System.out.print("Edges from Vertex "+i+" : ");
      for(int j=0;j<graph[i].size();j++)
      {
         System.out.print((graph[i].get(j)).v1+"->"+(graph[i].get(j)).v2+" with weight of "+(graph[i].get(j)).wt+" , ");
      }
      System.out.println("\n");
   }


   }


}