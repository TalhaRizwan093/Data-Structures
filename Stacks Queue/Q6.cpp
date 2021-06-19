using namespace std;
#include <iostream>

struct que{
	int age;
	string p_name;
	string disease;
	string d_name;
	que *next = NULL;
};

que *first = NULL;
que *last = NULL;

void enque(){
	que *curr = new que;
	cout<<"Enter the age of the patient: ";
	cin>>curr->age;
	cout<<"Enter the name of the patient: ";
	cin>>curr->p_name;
	cout<<"Enter the disease of the patient: ";
	cin>>curr->disease;
	cout<<"Enter the name of doctor of the patient: ";
	cin>>curr->d_name;
	if( first == NULL){
		first = last = curr;
	}
	else if ( curr->age > first->age){
		curr->next = first;
		first = curr;
	}
	else{
		que *p = first;
		while( p->next !=NULL && p->next->age  >= curr->age){
			p = p->next;
		}
		que *k = p->next;
		p->next = curr;
		curr->next = k;
		if( k==NULL){
			last = curr;
		}
	}	
}

void deque(){
	if(first != NULL){
	first = first->next;
	}
	else{
		cout<<"No node present.";
	}
}

void display(){
	if( first == NULL){
		cout<<"No data to show.";
	}
	que *p = first;
	while( p!=NULL){
		cout<<p->age<<" "<<p->p_name<<" "<<p->disease<<" "<<p->d_name<<endl;
		p = p->next;
	}
}

int main(){
	int opt = 0;
	int choice;
	while ( opt == 0){
		cout<<" ADD/DELETE PATIENT MENU "<<endl;
		cout<<" 1 to add / 2 to delete / 3 to display: ";
		cin>>choice;
		if( choice == 1)
			enque();
		else if( choice == 3)
			display();	
		else
			deque();	
		cout<<"Press 0 to continue inserting: ";
		cin>>opt;
	}
}
