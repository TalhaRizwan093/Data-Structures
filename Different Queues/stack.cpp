#include<iostream>

using namespace std;

int n = 100;
void push(char stack[], char val, int top) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop(char stack[100], int top) {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      //cout<<"The popped element is "<< stack[top] <<endl;
      top--;
   }
}
void display(char stack[100], int top) {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}


int main(){
	char stack[100];
	int topS = -1;
	char postfix[100];
	int topO = -1;
	string expression;
	cout<<"Enter expression you want to convert to postfix: ";
	cin>>expression;
	int j = 0;
	for(int i = 0; i<expression.length(); i++){
		
		if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^'){
			
			if(topS == -1){
				
				push(stack, expression[i], topS);
				topS++;
			}
			else if(expression[i] == '*' || expression[i] == '/'){
				
				if(stack[topS] == '+' || stack[topS] == '-'){
					
					push(stack, expression[i], topS);
					topS++;
				}
				else if(stack[topS] == '('){
				push(stack, expression[i], topS);
				topS++;
				}
				else{
					push(postfix,stack[topS],topO);
					topO++;
					j++;
					pop(stack,topS);
					topS--;
					push(stack,expression[i], topS);
					topS++;
				}
				
			}
			else if(stack[topS] == '('){
				push(stack, expression[i], topS);
				topS++;
			}
			else{
				push(postfix,stack[topS],topO);
				topO++;
				j++;
				pop(stack,topS);
				topS--;
				push(stack,expression[i], topS);
				topS++;
			}
		}
		else if(expression[i] == '('){
			
			push(stack,expression[i], topS);
			topS++;
			
		}
		else if(expression[i] == ')'){
			
			while(stack[topS] != '('){
				push(postfix,stack[topS],topO);
				topO++;
				j++;
				pop(stack,topS);
				topS--;
				
			}
			pop(stack,topS);
			topS--;
		}
		else{
			
			push(postfix,expression[i],topO);
			topO++;
			j++;
		}
		
		
	}
	while(topS != -1){
		push(postfix,stack[topS],topO);
		topO++;
		pop(stack,topS);
		topS--;
	}
	
	for(int i = 0; i<expression.length(); i++){
		cout<<postfix[i];
}
}
