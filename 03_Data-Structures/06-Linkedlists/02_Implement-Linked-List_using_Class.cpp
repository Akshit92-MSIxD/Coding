// https://leetcode.com/problems/design-linked-list/description/(Design LinkedList Leetcode :) )

#include <iostream>
using namespace std;

// This class would define the Node

class Node
{
public :

int data;
Node * next;

 Node()
 {
    data = 0;
    next = NULL;
 }

 Node(int data)
 {
   this->data = data;
   this->next = NULL;
 }

};



// This class would define the Linkedlist

class LinkedList
{
   public:

   Node * head;

   LinkedList()
   {
      head = NULL;
   }
    
   void insertNode(int);  // insert node at the last of linkedList [Note : insert node at front , insert node at particular position is also easy:)]

   void deleteNode(int);  // delete node from particular position in a linkedlist 

   void printList();

};

void LinkedList::insertNode(int data)
{
      Node* newNode = new Node(data);

      if(head == NULL)   // head ==> this->head !!!
      {
         head = newNode;
         return;
      }
      
            Node* currentNode = head;

            while(currentNode->next != NULL)
            {
               currentNode = currentNode->next;
            }

            currentNode->next = newNode;
            return;
         
}


void LinkedList::deleteNode(int position)
{
     if(head==NULL)
     {
        cout<<"\nThe list is already empty!!!\n";
        return;
     }

     if(position<1)
     {
      cout<<"\nposition cannot be negative!!!\n";
      return;
     }

    Node * temp1 = head;

    if(position == 1)
    {
      head = head->next;
      delete temp1;
      return;
    }

    // Calculating the length of Linkedlist

    temp1 = head;
    int listlen = 0;

    while(temp1!=NULL)
    {
      listlen++;
      temp1 = temp1->next;
    }


    if(position > listlen)
    {
      cout<<"\nposition out of bound!!!\n";
      return;
    }

    temp1 = head;

    for(int i=1;i<position-1;i++)
    {
          temp1 = temp1->next;
    }

    Node* temp2 = temp1->next; // temp2 points to the node to be deleted !!!

    temp1->next = temp1->next->next;

    delete temp2;

    return;
    
}


void LinkedList::printList()
{
   if(head == NULL)
   {
      cout<<"\nList is empty!!!\n";
      return;
   }

   Node * currentNode = head;
  
   cout<<"\nElements of the list are : ";

   while(currentNode!=NULL)
   {
      cout<<currentNode->data<<" ";
      currentNode = currentNode->next;
   }
   cout<<endl<<endl;
   return;
}



int main()
{

LinkedList list1;

list1.insertNode(10);
list1.insertNode(20);
list1.insertNode(30);
list1.insertNode(40);
list1.insertNode(50);
list1.insertNode(60);
list1.insertNode(70);

list1.printList();

list1.deleteNode(4); // will delete node from position 4 of list1

list1.printList();


}

