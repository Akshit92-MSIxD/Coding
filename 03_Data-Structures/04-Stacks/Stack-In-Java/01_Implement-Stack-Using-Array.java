

import java.util.Scanner;
import java.util.EmptyStackException;

class Stack
{
  
    private int maxCapacity;
    private int peekIndex;
    private int[] arr;

    Stack(int maxCapacity)
    {
        this.maxCapacity = maxCapacity;
        this.arr = new int[maxCapacity];
        this.peekIndex = -1;
    }

    Stack()
    {
        this.maxCapacity = 100;
        this.arr = new int[100];
        this.peekIndex = -1;
    }

    private void resizeStack()
    {
        
        int[] newArr = new int[maxCapacity+100];


        for(int i=0;i<maxCapacity;i++)
        newArr[i] = arr[i];

        arr = newArr;
    }
     
    public void push(int val)
    {
        peekIndex++;

        if(peekIndex >= maxCapacity)
        resizeStack();

        arr[peekIndex] = val;
    }

    public int pop()
    {
        
        if(isEmpty())
        throw new EmptyStackException();

        int poppedVal = arr[peekIndex];
        arr[peekIndex] = 0;
        peekIndex--;

        return poppedVal;
    }

    public int peek()
    {
       
       if(isEmpty())
       throw new EmptyStackException();

       return arr[peekIndex];
    }

    public int size()
    {
       return peekIndex+1;
    }

    public boolean isEmpty(){

         if(peekIndex == -1)
         return true;

         return false;
    }
}



class Main{


  public static void main(String[] args){
           
           int n;

           System.out.println("Enter the maxCapacity of the stack : ");

           Scanner sc = new Scanner(System.in);

           n = sc.nextInt();

           Stack st = new Stack(100);

           System.out.println("Enter 0 to stop execution");
           System.out.println("Enter 1 to push()");
           System.out.println("Enter 2 to pop()");
           System.out.println("Enter 3 to peek()");
           System.out.println("Enter 4 to size()");
           System.out.println("Enter 5 to isEmpty() \n");



           int choice = -1;

           do{
              
              System.out.println("\nEnter your choice : ");
              choice = sc.nextInt();

              switch(choice){
              
               case 0 : System.out.println("Your program ended successfully !!!");
                        break;

               case 1 : System.out.println("Enter the number you want to push into the stack : ");
                        int num = sc.nextInt();
                        st.push(num);
                        System.out.println("Number : "+num+" is successfully pushed into the stack!!!");
                        break;
                
                case 2 : System.out.println("Number : "+st.pop()+" is successfully popped out from the stack !!!");
                         break;

                case 3 :
                         System.out.println("Number : "+st.peek()+" is the peek of the stack !!!");
                         break;

                case 4 : System.out.println(" Stack current size : "+st.size());
                         break;

                case 5 : System.out.println("Is current stack empty ? -> "+st.isEmpty());
                         break;
              }
             

           }
           while(choice != 0);


  }


}