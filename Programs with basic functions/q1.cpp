#include<iostream>
#include<cstdio>
#include<cstdlib>
/*
 * Node Declaration
 */
using namespace std;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;
 
/*
 Class Declaration 
 */
class double_llist
{
    public:
        void create_list(int value);
        void add_end(int value);
        void start_sum();
        void display_dlist();
        double_llist()
        {
            start = NULL;
			 
        }

};

void add_end(int value){
	
	struct node *t, *temp;
	temp = new(struct node);
	t = start;
	
	while(t->next != NULL){
		t = t->next;
		
	}
	t->next = temp;
	temp->prev = t;
	temp->info = value;
	temp->next = NULL;
	
	
	
	cout<<"Element Inserted"<<endl;
	
}

int main()
{
    int choice, element, position;
    double_llist dl;
    while (1)
    {
    	cout<<"-------------------------------------------------------------------"<<endl;                
        cout<<"1.Create List  ";
        cout<<"2.Add at end  ";
        cout<<"3.Start Sum  ";
        cout<<"4.Display  ";
        cout<<"0.Quit"<<endl;        
        cout<<"-------------------------------------------------------------------"<<endl;         
        cout<<"Enter your choice : ";
		cin>>choice;
        switch ( choice )
        {
        case 1:
        	cout<<"Enter the element: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            break;
        
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_end(element);
            cout<<endl;
            break;
        case 3:
        	cout<<"Start adding: ";
        	dl.start_sum();
        	break;
        case 4:
        	
        	dl.display_dlist();
        	break;
        case 0:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}

void double_llist::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}

void double_llist::add_end(int value){
	if(start == NULL){
		cout<<"First creat the list."<<endl;
		return;
	}
	struct node *t, *temp;
	temp = new(struct node);
	t = start;
	
	while(t->next != NULL){
		t = t->next;
		
	}
	t->next = temp;
	temp->prev = t;
	temp->info = value;
	temp->next = NULL;
	
	
	
	cout<<"Element Inserted"<<endl;
	
}

void double_llist::start_sum(){
	int sum = 0;
	struct node *s, *e, *t;
	t = start;
	s = start;
	e = start;
	while(e != NULL){
		e = e->next;
	}
	
	cout<<s->info;
	cout<<e->info;
	
	while(s != e){
		sum = s->info + e->info;
		//if(sum % 2 != 0){
		//	add_end(sum);
		//}
		s = s->next;
		e = e->prev;
		sum = 0;
	}
	
	
}



void double_llist::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
