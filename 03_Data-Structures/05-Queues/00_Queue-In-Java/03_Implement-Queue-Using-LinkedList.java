

class Node{

  private int val;
  private Node next;

  Node(int val){
     this.val = val;
     this.next = null;
  }

  public int getVal(){return val;}
  public void setVal(int val){this.val=val;}

  public Node getNext(){return next;}
  public void setNext(Node next){this.next = next;}


}


class Queue{

 Node head;
 Node tail;
 int size;

  Queue(){
    head = null;
    tail = null;
    size = 0;
  }


  void offer(int val)
  {
      if(head == null)
      {
      head = new Node(val);
      tail = head;
      }
      else
      {
        tail.setNext(new Node(val));
        tail = tail.getNext();
      }
      size++;
  }


  Integer poll()
  {
         if(head == null)
         return null;

         int polledVal = head.getVal();
         
         if(head == tail)
         {
           head = tail = null;
         }
         else
         {
            head = head.getNext();
         }

         size--;

         return polledVal;
  }

  Integer peek()
  {
        if(head == null)
        return null;

        return head.getVal();
  }

  boolean isEmpty()
  {
    if(head == null)
    return true;

    return false;
  }

  int size()
  {
        return size;
  }


}