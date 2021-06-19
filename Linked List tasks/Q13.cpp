#include<iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
}*start1, *end1, *start2, *end2, *merg_end, *merg_start;

class LinkedList
{
	public:
		void create_list1(int value);
		void create_list2(int value);
		void display1();
		void display2();
		void merge();
		LinkedList(){
			start1 = NULL;
			end1 = NULL;
			start2 = NULL;
			end2 = NULL;
			merg_end = NULL;
			merg_start = NULL;
		}
};

void creatMerge(int value){
	//cout<<"I am running"<<endl;
	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	if(merg_start == NULL){
		temp->next = NULL;
		merg_end = temp;
		merg_start = temp;
		temp = NULL;
	}
	else{
		
		merg_end->next = temp;
		merg_end = temp;
		
	}
	
	merg_end->next = merg_start;
	
}

int main()
{
	struct node *t;
	LinkedList l1;
	int value;
	for(int i = 0; i<5 ;i++){
		cout<<"Enter values of Circular linked list 1: ";
		cin>>value;
		l1.create_list1(value);
	}
	
	for(int i = 0; i<5 ;i++){
		cout<<"Enter values of Circular linked list 2: ";
		cin>>value;
		l1.create_list2(value);
	}
	
	
	l1.display1();
	l1.display2();
	
	l1.merge();
	
	t = merg_start;
	do
	{
		
        cout<<t->info<<" <-> ";
        t = t->next;
    }while (t != merg_start);
    cout<<"NULL"<<endl;
    
    
    //l1.display1();
    //l1.display2();
	
	
}

void LinkedList::create_list1(int value)
{
	
	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	if(start1 == NULL){
		temp->next = NULL;
		end1 = temp;
		start1 = temp;
		temp = NULL;
	}
	else{
		
		end1->next = temp;
		end1 = temp;
		
	}
	
	end1->next = start1;
	
	
	
	
}

void LinkedList::create_list2(int value)
{
	struct node *temp;
	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	if(start2 == NULL){
		end2 = temp;
		start2 = temp;
		temp = NULL;
	}
	else{
		
		end2->next = temp;
		end2 = temp;
	}
	
	end2->next = start2;
	
	
}

void LinkedList::display1()
{
	struct node  *t;
	t=start1;
	do
	{
        cout<<t->info<<" <-> ";
        t = t->next;
    }while (t != start1);
    cout<<"NULL"<<endl;
	
}

void LinkedList::display2()
{
	struct node  *t;
	t=start2;
	do
	{
        cout<<t->info<<" <-> ";
        t = t->next;
    }while (t != start2);
    cout<<"NULL"<<endl;
	
}

void LinkedList::merge()
{
	
	struct node *temp, *t1 , *t2, *t3 ,*e1 ,*e2;
	t1 = start1;
	t2 = start2;
	e1 = start1;
	e2 = start2;
	int num, prevNum, tempNum;
	int check = 0, a = 0;
	for(int i = 0; i<5 ; i++){
		
		for(int j = 0; j<5 ; j++){
			if(t1->info > e1->info){
				tempNum = t1->info;
				t1->info = e1->info;
				e1->info = tempNum;
			}
			e1 = e1->next;
			
		}
		t1 = t1->next;
	}
	
	for(int i = 0; i<5 ; i++){
		
		for(int j = 0; j<5 ; j++){
			if(t2->info > e2->info){
				tempNum = t2->info;
				t2->info = e2->info;
				e2->info = tempNum;
			}
			e2 = e2->next;
			
		}
		t2 = t2->next;
	}
	
	t1 = start1;
	t2 = start2;
	e1 = start1;
	e2 = start2;
	
	while(a < 10){
		a++;
		
		if(check == 0){
			do{
				num = t1->info;
				creatMerge(num);
				t1 = t1->next;
				check = 1;
				break;
			}while(t1 != start1);
		}
		else{
			do{
				num = t2->info;
				creatMerge(num);
				t2 = t2->next;
				check = 0;
				break;
			}while(t2 != start2);
		}
		
		
		
	}
	
	
	

	
	
}
