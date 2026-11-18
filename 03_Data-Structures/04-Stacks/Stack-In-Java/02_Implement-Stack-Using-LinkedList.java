
import java.util.Scanner;
import java.util.EmptyStackException;
import java.util.NoSuchElementException;

class Node
{
    int val;
    Node next;

    Node(int val)
    {
        this.val = val;
        this.next = null;
    }
}


class LinkedList
{
    private Node head;

    LinkedList()
    {
        this.head = null;
    }

    void addFirst(int val)
    {
       if(head == null)
       {
          head = new Node(val);
       }
       else
       {
          Node newHead = new Node(val);
          newHead.next = head;
          head = newHead;
       }
    }

    int removeFirst()
    {  

        if(head == null)
        throw new NoSuchElementException();

        int removedVal = head.val;
        head = head.next;

        return removedVal;
    }

    int getFirst()
    {
         if(head == null)
         throw new NoSuchElementException();

         return head.val;
    }
}



class Stack
{
 
 private LinkedList list;
 private int size;

 Stack()
 {
    this.list = new LinkedList();
    this.size = 0;
 }

 void push(int val)
 {
    list.addFirst(val);
    size++;
 }

 int pop()
 {

    int poppedVal = list.removeFirst();
    size--;

    return poppedVal;
 }

 int peek()
 {
    return list.getFirst();
 }

 int size()
 {
    return size;
 }

 boolean isEmpty()
 {
    return size == 0;
 }

}


class Main{


  public static void main(String[] args){
           
           int n;

           Scanner sc = new Scanner(System.in);

           Stack st = new Stack();

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

