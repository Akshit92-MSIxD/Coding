
class Queue{

  int[] arr;
  int maxCapacity;
  int front;
  int rear;
  int size;

  Queue()
  {
    this.maxCapacity = 10;
    this.arr = new int[maxCapacity];
    this.front = -1;
    this.rear = -1;
    this.size = 0;
  }


  void resizeQueue()
  { 
     int newMaxCapacity = maxCapacity*2;
     int[] newArr = new int[newMaxCapacity];

     for(int i=0;i<size;i++)
      newArr[i] = arr[(front+i)%maxCapacity];

      arr = newArr;
      maxCapacity = newMaxCapacity;

      front = 0;
      rear = size-1;
  }

  boolean offer(int val)
  {

      if(size == maxCapacity)
      resizeQueue();

      if(size == 0)
      {
        arr[0]=val;
        front = rear = 0;

        size++;

        return true;
      }
    
    rear = (rear + 1) % maxCapacity;

    arr[rear] = val;
    size++;

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
      size--;

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
    return size;

  }

  boolean isEmpty()
  {
     return size == 0;
  }

  



 }