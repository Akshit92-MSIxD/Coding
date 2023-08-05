#include<stdio.h>
#include<stdlib.h>
int size;    
int f=-1, r=-1;
void enqueue_front(int deque[],int x){  
    if((f==0 && r==size-1) || (f==r+1))
        printf("deque is full");  
    else if((f==-1) && (r==-1)){  
        f=r=0;  
        deque[f]=x;  
    }  
    else if(f==0){  
        f=size-1;  
        deque[f]=x;  
    }  
    else{  
        f=f-1;  
        deque[f]=x;  
    }  
}
void enqueue_rear(int deque[],int x){  
    if((f==0 && r==size-1) || (f==r+1))
        printf("deque is full");  
    else if((f==-1) && (r==-1)){  
        r=0;  
        deque[r]=x;  
    }  
    else if(r==size-1){  
        r=0;  
        deque[r]=x;  
    }  
    else{  
        r++;  
        deque[r]=x;  
    }  
}  
void display(int deque[]){  
    int i=f;  
    printf("\n Elements in a deque : ");   
    while(i!=r){  
        printf("%d ",deque[i]);  
        i=(i+1)%size;  
    }  
    printf("%d",deque[r]);  
}
void getfront(int deque[]){  
    if((f==-1) && (r==-1))
        printf("Deque is empty");   
    else 
        printf("\nThe value of the front is: %d", deque[f]);      
} 
void getrear(int deque[]){  
    if((f==-1) && (r==-1)) 
        printf("Deque is empty");  
    else 
        printf("\nThe value of the rear is: %d", deque[r]);   
} 
void dequeue_front(int deque[]){  
    if((f==-1) && (r==-1)) 
        printf("Deque is empty");  
    else if(f==r){  
        printf("\nThe deleted element is %d", deque[f]);  
        f=-1;  
        r=-1;  
    }  
    else if(f==(size-1)){  
        printf("\nThe deleted element is %d", deque[f]);  
        f=0;  
    }  
    else{  
        printf("\nThe deleted element is %d", deque[f]);  
        f=f+1;  
    }  
} 
void dequeue_rear(int deque[]){  
    if((f==-1) && (r==-1)) 
        printf("Deque is empty");
    else if(f==r){  
        printf("\nThe deleted element is %d", deque[r]);  
        f=-1;  
        r=-1;      
    }  
    else if(r==0){  
        printf("\nThe deleted element is %d", deque[r]);  
        r=size-1;  
    }  
    else{  
        printf("\nThe deleted element is %d", deque[r]);  
        r=r-1;  
    }  
}  
int main()  {  
    int *a,val;
    int choice=1;
    char chance='y';
    int way;
    printf("Enter N :");
    scanf("%d",&size);
    a=(int *)malloc(size*sizeof(int));
    printf("Enter You Way : \n");
    printf("1.Input restricted double ended queue");
    printf("\n2.Output restricted double ended queue.");
    printf("\nEnter You Way : ");
    scanf("%d",&way);
    if(way==1){
        printf("\n1.Inserting a value from the front.");
        printf("\n2.Deleting a value from the front.");
        printf("\n3.Deleting a value from the rear ");
        printf("\n4.Retrieve the front value.");
        printf("\n5.Retrieve the rear value.");
        printf("\n6.Display.");
        while(chance=='y' || chance=='Y'){
            printf("\nEnter Your Choice : ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("\nEnter Value : ");
                    scanf("%d",&val);
                    enqueue_front(a,val);
                    break;
                case 2:
                    dequeue_front(a); 
                    break;
                case 3:
                    dequeue_rear(a); 
                    break;
                case 4:
                    getfront(a);
                    break;
                case 5:
                    getrear(a);
                    break;
                case 6:
                    display(a);
                    break;
            }
            printf("\nWant to do more operation (y/n) : ");
            scanf(" %c",&chance);
        }
    }
    else{
        printf("\n1.Inserting a value from the front.");
        printf("\n2.Inserting a value from the rear.");
        printf("\n3.Retrieve the front value.");
        printf("\n4.Retrieve the rear value.");
        printf("\n5.Deleting a value from the front.");
        printf("\n7.Display.");
        while(chance=='y' || chance=='Y'){
            printf("\nEnter Your Choice : ");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("\nEnter Value : ");
                    scanf("%d",&val);
                    enqueue_front(a,val);
                    break;
                case 2:
                    getfront(a);
                    break;
                case 3:
                    getrear(a);
                    break;
                case 4:
                    dequeue_front(a); 
                    break;
                case 5:
                    dequeue_rear(a); 
                    break;
                case 6:
                    display(a);
                    break;
            }
        printf("\nWant to do more operation (y/n) : ");
        scanf(" %c",&chance);
        }
    }
    return 0;
}