#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;

struct node
{
    int info;
    struct node *next;
}*start, *end ,*duplicate_start , *duplicate_end;

class LinkedList
{
	public:
		void create_list(int value);
		void add_end(int value);
		void display_list();
		int  size();
		void remove(int index);
		void duplicate();
		void ReverseDisplay();
		void Delete_duplicate();
		void Palindrome();
		LinkedList(){
			start = NULL;
			end = NULL;
			duplicate_start = NULL;
			duplicate_end = NULL;
		}
};

int main()
{
	int choice, position, element,number_of_elements;
	LinkedList l1;
	while(1){
		cout<<"-------------------------------------------------------------------"<<endl;                
        cout<<"1.Create List  ";
        cout<<"2.Add Element  ";
        cout<<"3.Display  "<<endl;
		cout<<"4.Size of List  ";
        cout<<"5.Delete Element  ";
    	cout<<"6.Duplicate List  ";
    	cout<<"7.Reverse Display  "<<endl;
    	cout<<"8.Delete duplicate elements  ";
    	cout<<"9.Palindrom Check  ";
		cout<<"0.Quit"<<endl;        
        cout<<"-------------------------------------------------------------------"<<endl; 
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
        	case 1:
        		if(start != NULL)
        		{
        			cout<<"List is already created "<<endl;
        			break;
				}
				
        		cout<<"Enter the element: ";
            	cin>>element;
            	l1.create_list(element);
            	cout<<endl;
            	break;
            case 2:
            	cout<<"How many elements do you want to enter in list: ";
            	cin>>number_of_elements;
            	for(int i = 0; i<number_of_elements; i++){
            		cout<<"Enter the element: ";
            		cin>>element;
            		l1.add_end(element);
            		
				}
            	cout<<endl;
            	break;
            case 3:
            	l1.display_list();
            	cout<<endl;
            	break;
            case 4:
            	cout<<"Size of the list is: "<<l1.size()<<endl;
            	cout<<endl;
            	break;
            
            case 5:
            	cout<<"Enter the index for deletion: ";
            	cin>>position;
            	l1.remove(position);
            	cout<<endl;            
            	break;
            
            case 6:
            	l1.duplicate();
            	cout<<endl;
            	break;
            
            case 7:
            	l1.ReverseDisplay();
            	cout<<endl;
            	break;
            
            case 8:
            	l1.Delete_duplicate();
            	cout<<endl;
            	break;
        	
            case 9:
            	l1.Palindrome();
            	cout<<endl;
            	break;
            	
            case 0:
            	exit(1);
            default:
            	cout<<"Wrong Choice"<<endl;
            	
		}
	}
	
	return(0);
}

void LinkedList::create_list(int value)
{
	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	
	start = temp;
	end = temp;
	temp = NULL;
	
	
	
}

void LinkedList::add_end(int value)
{
	if(start == NULL)
	{
		cout<<"First create List "<<endl;
		return;
	}
	struct node *temp;                   //temp1 end->temp
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	end->next = temp;
	end = temp;
}

void LinkedList::display_list()
{
	struct node *t;
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    t = start;
    cout<<"The Link List is :"<<endl;
    while (t != end->next)
    {
        cout<<t->info<<" <-> ";
        t = t->next;
    }
    cout<<"NULL"<<endl;
}

int LinkedList::size()
{
	int count = 0;
	struct node *t;
    if (start == NULL)
    {
        cout<<"List empty"<<endl;
        return(0);
    }
    t = start;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
	return count;
}

void LinkedList::remove(int index)
{
	int count = 1;
	struct node *t, *prev;
    if (start == NULL)
    {
        cout<<"List empty,nothing to delete"<<endl;
        return;
    }
    t = start;
    if(index == 2)
    	prev = t;
    	
    while (t != NULL)
    {
    	t = t->next;
        count++;
    	if(count == index-1)
        	prev = t;
        if(count == index)
        	break;
        
		
    }
    if(index == 1)
    {
    	start = start->next;
    	
	}
	else{
		prev->next = t->next;
	}
	
    cout<<"Element at "<<index<<" is successfully removed "<<endl;
    
}

void LinkedList::duplicate()
{
	int count = 0;
	struct node *t, *q, *i;  //pointers to treverse over the link list
    if (start == NULL)
    {
        cout<<"List empty,nothing to duplicate"<<endl;
        return;
    }
    t = start;
    q = start;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    
    for(int i = 0; i<count; i++){
    	struct node *duplicate_node;
    	duplicate_node = new(struct node);
    	duplicate_node->info = q->info;
    	duplicate_node->next = NULL;
    	if(duplicate_start == NULL){
    		
    		duplicate_start = duplicate_node;
    		duplicate_end = duplicate_node;
    		duplicate_node = NULL;
    		
		}
		else
		{
    		duplicate_end->next = duplicate_node;
    		duplicate_end = duplicate_node;
    		
    		
		}
		q = q->next;
		
    	
	}
	i = duplicate_start;
	while(i != NULL)
	{
		cout<<i->info<<" <-> ";
        i = i->next;
	}
	cout<<" NULL "<<endl;
    
    
}

void LinkedList::ReverseDisplay()
{
	struct node *e, *t;
	int count = 0,temp_count = 0;
	e = start;
	t = start;
	while (t != NULL)
    {
        count++;
        t = t->next;
        
    }
    temp_count = count;
	for(int i = 1; i<=count; i++)
	{
		for(int j = 1; j<=temp_count-1; j++){
			e = e->next;
		}
		cout<<e->info<<" <-> ";
		e = start;
		temp_count = temp_count - 1;
		
	}
	cout<<" NULL "<<endl;
	
}

void LinkedList::Delete_duplicate()
{
	struct node *t, *e, *prev;
	int count = 0;
	t = start;
	e = start;
	
	while( t != NULL){
		
		
		
		while(e != NULL){
			
			if(t->info == e->info){
				
				if(count != 0){
					prev->next = e->next;
					
					
				}
				else{
					
					count++;
					
				}
				
				
			}
			prev = e;
			e = e->next;
			
		}
		prev = start;
		count = 0;
		t = t->next;
		e = start;
	}
	cout<<"Duplicate items are successfully deleted"<<endl;
	
}

void LinkedList::Palindrome()
{
	struct node *t, *i, *e;
	int count = 0,temp_count = 0;
	t = start;
	i = start;
	e = start;
	int num1,num2;
	stringstream linklist1 , linklist2;
	
	while (i != NULL)
    {
        count++;
        i = i->next;
        
    }
	
	while(t!=NULL){
		num1 = t->info;
		linklist1 << num1;
		
		t = t->next;
	}
	string String1 = linklist1.str();
	
	temp_count = count;
	
	for(int i = 1; i<=count; i++)
	{
		for(int j = 1; j<=temp_count-1; j++){
			e = e->next;
		}
		num2 = e->info;
		linklist2 << num2;
		e = start;
		temp_count = temp_count - 1;
		
	}
	string String2 = linklist2.str();
	
	
	if(String1 == String2){
		cout<<"Link List is palindrom"<<endl;
	}
	else
		cout<<"Link list is not a palindrom"<<endl;
	
	
}

