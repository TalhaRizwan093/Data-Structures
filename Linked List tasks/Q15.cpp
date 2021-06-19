#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
}*start, *end;

class LinkedList
{
	public:
		void creatList(int value);
		void display();
		void swap(int index);
		LinkedList(){
			start = NULL;
			end = NULL;
		}
};
int main()
{
	LinkedList l1;
	int size,value,kNode;
	cout<<"Enter number of elements you want to add in linked list: ";
	cin>>size;
	for(int i = 1; i <= size; i++){
		cout<<"Enter data: ";
		cin>>value;
		l1.creatList(value);
	}
	
	l1.display();
	
	cout<<"Enter k node which you want to swap: ";
	cin>>kNode;
	l1.swap(kNode);
	l1.display();
	
}

void LinkedList::creatList(int value)
{
	
	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	if(start == NULL){
		
		start = temp;
		end = temp;
		temp = NULL;
		
	}
	else{
		end->next = temp;
		end = temp;
	}
	
	
}

void LinkedList::display(){
	
	struct node *t;
	t = start;
	while(t!=NULL){
		cout<<t->info<<" <-> ";
        t = t->next;
	}	
	cout<<"NULL"<<endl;
}

void LinkedList::swap(int index)
{
	
	struct node *t1, *t2;
	t1 = start;
	t2 = start;
	int count = 0 , k = 0, num;
	
	while(t1 != NULL)
	{
		count++;
		t1 = t1->next;
	}
	k = count - index + 1;
	t1 = start;
	if(count == 1 || count == 2){
		cout<<"There is no kth term for "<<count<<endl;
		return;
	}
	else{
		for(int i = 1; i<index; i++){
			t1 = t1->next;
	}
		for(int i = 1; i<k ; i++){
			t2 = t2->next;
	}
		num = t1->info;
		t1->info = t2->info;
		t2->info = num;
	
	}

	
}

