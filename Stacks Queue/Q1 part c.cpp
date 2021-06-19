using namespace std;
#include <iostream>

struct stu{
	char c;
	stu *next = NULL;
	//stu *prev = NULL;
};

stu *top = NULL;

void push(char);
char pop();

int main(){
	char arr[20];
	cout<<"Enter the word: ";
	cin>>arr;
	for( int i=0;arr[i]!='\0';i++){
		push(arr[i]);
	}
	int j=0;
	bool check = true;
	while(top->prev!=NULL){
		char a = pop();
		if( a!=arr[j]){
			check = false;
			break;
		}
		j++;
	}
	if(check){
		cout<<"It is palindrome.";
	}
	else{
		cout<<"Not palindrome.";
	}	
}

void push(char a){
	stu *curr = new stu;
	curr->c = a;
	if( top == NULL){
		top = curr;
	}
	else{
		curr->prev = top;
		top->next = curr;
		top = curr;
	}
}

char pop(){
	char a = top->c;
	top = top->prev;
	return a;	
}
