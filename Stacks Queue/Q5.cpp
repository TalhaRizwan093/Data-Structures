using namespace std;
#include <iostream>

class sta{
	int *s;
	int size;
	int top;
	
public :
	sta(int ss){
		size = ss;
		s = new int[size];
		top = -1;
	}
	
	void push(int a){
		if(top == size-1){
			cout<<"No space.";
		}
		else{
			s[++top] = a;  
		}
	}
	
	int pop(){
		if(top==-1){
			return 0;
		}
		else{
		    return s[top--];
		}
	}
	
	bool isempty(){
		if(top==-1){
			return true;
		}
		else
			return false;
	}
	
};

int main(){
	
	char array[100];
	cout<<"Enter valid postfix expression: ";
	cin>>array;
	
	sta s(100);
	int x,a,b,c;
	
	for( int i=0; array[i]!='\0'; i++){
		if( array[i]>='0' && array[i] <= '9'){
			x = array[i] - 48;
			s.push(x);
		}
		else if ( array[i]=='+' || array[i]=='-' || array[i]=='*' || array[i]=='/'){
			a = s.pop();
			b = s.pop();
		        if( array[i]=='+'){
					c = a+b;
					s.push(c);
				}
				else if( array[i]=='-'){
					c = b-a;
					s.push(c);
				}
				else if( array[i]=='*' ){
					c = a*b;
					s.push(c);
				}
				else{	
					c = b/a;
					s.push(c);
				}
		}
	}
	cout<<s.pop();
}
