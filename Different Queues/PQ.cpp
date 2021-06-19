#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct node {
   int data;
   int priority;
   struct node *next;
};
node *front = NULL;

void insertPQ(int data, int priority) {
   node *temp, *ptr;
   temp = new node;
   temp->data = data;
   temp->priority = priority;
   
   if (front == NULL || priority < front->priority) {
      temp->next = front;
      front = temp;
   
   } else {
      ptr = front;
      while (ptr->next != NULL && ptr->next->priority <= priority)
      ptr=ptr->next;
      temp->next = ptr->next;
      ptr->next = temp;
   }
}
void deletePQ() {
   node *temp;
   
   if(front == NULL)
   cout<<"Priority Queue Underflow\n";
   
   else {
      temp = front;
      cout<<"Deleted item is: "<<temp->data<<endl;
      front = front->next;
      free(temp);
   }
}
void displayPQ() {
   node *ptr;
   ptr = front;
   
   if (front == NULL)
   cout<<"Priority Queue is empty\n";
   
   else { 
      cout<<"Queue elements in decreasing priority are :\n";
      while(ptr != NULL) {
         cout<<ptr->data<<" ";
         ptr = ptr->next;
      }
      cout<<endl;
   }
}
int main() {
   int ch, data, priority;
   cout<<"1.Insert\n";
   cout<<"2.Delete\n";
   cout<<"3.Display\n";
   cout<<"4.Exit\n";
   
   do {
      cout<<"Enter your choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
            cout<<"Input the value to be added in the priority queue : "<<endl;
            cin>>data;
            cout<<"Enter its priority : "<<endl;
            cin>>priority;
            insertPQ(data, priority);
            break;
            
         case 2:
            deletePQ();
            break;
            
         case 3:
            displayPQ();
            break;
            
         case 4:
            cout<<"Exit"<<endl;
            break;
            
         default :
            cout<<"Wrong choice\n";
      }
   }while(ch != 4);
      return 0;
}
