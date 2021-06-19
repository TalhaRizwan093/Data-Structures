#include<iostream>

using namespace std;

struct node
{
    int data;
    int power;
    struct node *next;
}*start1, *end1,*start2, *end2,*add_start,*add_end;

class LinkedList
{
	public:
		void creatList1(int value, int power);
		void creatList2(int value, int power);
		void creatList3(int value, int power);
		void display1();
		void display2();
		void display3();
		void add();
		LinkedList(){
			start1 = NULL;
			end1 = NULL;
			start2 = NULL;
			end2 = NULL;
			add_start = NULL;
			add_end = NULL;
		}
};
void desend(node *start){
	struct node *t ,*e;
	int pow, data;
	e = start;
	t = start;
	while(t != NULL){
		while(e != NULL){
			if(t->power > e->power){
				pow = t->power;
				data = t->data;
				t->power = e->power;
				t->data = e->data;
				e->power = pow;
				e->data = data;
			}
			e = e->next;
		}
		t = t->next;
	}
}

void creatList(int value, int power){
	struct node *temp;
	temp = new(struct node);
	temp->data = value;
	temp->power = power;
	temp->next = NULL;
	if(add_start == NULL){
		
		add_start = temp;
		add_end = temp;
		temp = NULL;
		
	}
	else{
		add_end->next = temp;
		add_end = temp;
	}
}
int main()
{
	LinkedList l1;
	int size,value, power;
	cout<<"Enter number of elements you want to add in ploynomial 1: ";
	cin>>size;
	for(int i = 1; i <= size; i++){
		cout<<"Enter data: ";
		cin>>value;
		cout<<"Enter power: ";
		cin>>power;
		l1.creatList1(value, power);
	}
	
	cout<<"Enter number of elements you want to add in ploynomial 2: ";
	cin>>size;
	for(int i = 1; i <= size; i++){
		cout<<"Enter data: ";
		cin>>value;
		cout<<"Enter power: ";
		cin>>power;
		l1.creatList2(value, power);
	}
	l1.display1();
	l1.display2();
	l1.add();
	struct node *t;
	t=add_start;
	while(t!=NULL){
		cout<<t->data<<"|"<<t->power<<" <-> ";
        t = t->next;
	}
	cout<<"NULL"<<endl;
}

void LinkedList::creatList1(int value, int power)
{
	
	struct node *temp;
	temp = new(struct node);
	temp->data = value;
	temp->power = power;
	temp->next = NULL;
	if(start1 == NULL){
		
		start1 = temp;
		end1 = temp;
		temp = NULL;
		
	}
	else{
		end1->next = temp;
		end1 = temp;
	}
	
	
	
}

void LinkedList::creatList2(int value, int power)
{
	
	struct node *temp;
	temp = new(struct node);
	temp->data = value;
	temp->power = power;
	temp->next = NULL;
	if(start2 == NULL){
		
		start2 = temp;
		end2 = temp;
		temp = NULL;
		
	}
	else{
		end2->next = temp;
		end2 = temp;
	}
	
	
}


void LinkedList::display1(){
	
	struct node *t;
	t = start1;
	while(t!=NULL){
		cout<<t->data<<"|"<<t->power<<" <-> ";
        t = t->next;
	}	
	cout<<"NULL"<<endl;
}

void LinkedList::display2(){
	
	struct node *t;
	t = start2;
	while(t!=NULL){
		cout<<t->data<<"|"<<t->power<<" <-> ";
        t = t->next;
	}	
	cout<<"NULL"<<endl;
}

void LinkedList::display3(){
	
	struct node *t;
	t = add_start;
	while(t!=NULL){
		cout<<t->data<<"|"<<t->power<<" <-> ";
        t = t->next;
	}	
	cout<<"NULL"<<endl;
}

void LinkedList::add()
{
	
	struct node *t1, *t2;
	int num = 0 , count1= 0, count2 = 0, iterate = 0, total_size = 0;
	int pow1, pow2, check = 0;
	t1 = start1;
	t2 = start2;
	while(t1 != NULL){
		count1++;
		t1 = t1->next;
	}
	while(t2 != NULL){
		count2++;
		t2 = t2->next;
	}
	total_size = count1 + count2;
	t1 = start1;
	t2 = start2;
	desend(start1);
	desend(start2);

	while(t1 != NULL){
		pow1 = t1->power;
		while(t2 != NULL){
			pow2 = t2->power;
			if(pow1 != pow2){
				t2 = t2->next;
			}
			else{
				check = 1;
				break;
			}
			
		}
		t2 = start2;
		if(check == 1){
			break;
		}
		
		t1 = t1->next;
	
	cout<<check;
	t1 = start1;
	t2 = start2;
	if(check == 1){
		while(true){
		if(t1->power < t2->power){
			iterate++;
			t2 = t2->next;
			
		}
		else if(t1->power > t2->power){
			iterate++;
			t1 = t1->next;
		}
		else{
			iterate++;
			t1 = t1->next;
			t2  = t2->next;
		}
		if(t1 == NULL && t2 == NULL){
			break;
		}
		
		
	}
		t1 = start1;
		t2 = start2;
		for(int i = 1; i<=iterate; i++){
			if(t1->power > t2->power){ 
				creatList(t1->data,t1->power);
				t1 = t1->next;
				
			}
			else if(t1->power < t2->power){
			
				creatList(t2->data,t2->power);
				t2 = t2->next;
			
				
			
			}
		else{
			creatList(t2->data+t1->data,t1->power);
			t1 = t1->next;
			t2  = t2->next;
		}
		
		
	} 
	}
	else{
		
		while(t1 != NULL){
			creatList(t1->data,t1->power);
			t1 = t1->next;
		}
		while(t2 != NULL){
			creatList(t2->data,t2->power);
			t2 = t2->next;
		}
		desend(add_start);
		
	}
	
	
}
	

}

