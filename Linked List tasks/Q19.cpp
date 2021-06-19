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
		void reverse(int size);
		LinkedList(){
			start = NULL;
			end = NULL;
		}
};
int main()
{
	LinkedList l1;
	int size,value;
	cout<<"Enter number of elements you want to add in linked list: ";
	cin>>size;
	for(int i = 1; i <= size; i++){
		cout<<"Enter data: ";
		cin>>value;
		l1.creatList(value);
	}
	
	l1.display();
	
	cout<<"Enter Size of reverse: "<<endl;
	cin>>size;
	
	l1.reverse(size);
	
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

void LinkedList::reverse(int size)
{
	
	struct node *t, *e , *z, *prev;
	int count = 0, temp_size = size,check = 0;
	t = start;
	e = start;
	while(t != NULL){
		count++;
		t = t->next;
	}
	t = start;
	
	for(int i = 0; i<count*2; i++){
		for(int j = 0; j<temp_size-1; j++){
			if(t->next == NULL){
				check = 1;
				break;
			}
			t = t->next;
			prev = t;
		}
		if(temp_size != 0 && check == 0){
			
			if( i <= size){
				cout<<t->info<<" <-> ";
			
				t = start;
				temp_size--;
				e = e->next;
			}
			else{
				cout<<t->info<<" <-> ";
				t = z;
				temp_size--;
				if(e->next!=NULL){
					e = e->next;
				}
				
				
			}		
		}
		
		else if(temp_size == 0 && check == 0){
			temp_size = size;
			t = e;
			z = e;
		}
		else{
			break;
		}
	
	}
	
	if(t->next == NULL){
		if(prev->info != e->info){
			cout<<z->info<<" <-> ";	
	}
		cout<<"NULL"<<endl;
		return;
	}
	else{
		while(z!=NULL){
		count++;
		z = z->next;
		
	}
	t = e;
	
	temp_size = count;
	for(int i = 0; i<count; i++){
		for(int j = 1; j<temp_size; j++){
			
			t = t->next;
		}
		cout<<t->info<<" <-> ";
		temp_size--;
		t = e;
		
		
	}
	cout<<"NULL"<<endl;
	}

}
