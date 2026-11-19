
 class Queue{

  int[] arr;
  int maxCapacity;
  int front;
  int rear;

  Queue()
  {
    this.maxCapacity = 10;
    this.arr = new int[maxCapacity];
    this.front = -1;
    this.rear = -1;
  }

  boolean offer(int val)
  {
      if(front == -1 && rear == -1)
      {
        arr[0]=val;
        front = rear = 0;

        return true;
      }

    if((rear+1)%maxCapacity == front)
    return false;
    
    rear = (rear + 1) % maxCapacity;

    arr[rear] = val;

    return true;

  }

  Integer poll()
  {
      if(front == -1 && rear == -1)
      return null;

      Integer removedVal = arr[front];

      if(front == rear)
      {
        front = -1;
        rear = -1;
      }
      else
      {
      front = (front + 1)%maxCapacity;
      }

      return removedVal; 
  }

  Integer peek()
  {
      if(front == -1 && rear == -1)
      return null;

      return arr[front];
  }

  int size()
  {
       if(front == -1)
       return 0;

       if(front<=rear)
       return rear-front+1;

       return maxCapacity - (front - rear) + 1;


  }

  boolean isEmpty()
  {
     return front == -1;
  }

  



 }