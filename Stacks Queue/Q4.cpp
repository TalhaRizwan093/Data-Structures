using namespace std;
#include <iostream>

class sta{
	char *s;
	int size;
	int top;
	
public :
	sta(int ss){
		size = ss;
		s = new char[size];
		top = -1;
	}
	
	void push(char a){
		if(top == size-1){
			cout<<"No space.";
		}
		else{
			s[++top] = a;  
		}
	}
	
	char pop(){
		if(isempty()){
			return 0;
		}
		else{
		    return s[top--];
		}
	}
	
	char topd(){
		return s[top];
	}
	
	bool isempty(){
		if(top==-1){
			return true;
		}
		else
			return false;
	}
	
};

int pre(char);

int main(){
	
	char array[100];
	cout<<"Enter the expression: ";
	cin>>array;
	sta s(100);
	
	for ( int i=0; array[i]!='\0'; i++){
		if( array[i]>='a' && array[i] <='z'){
			cout<<array[i];
		}
		else{
			if( s.isempty()){
				s.push(array[i]);
			}
			else{
				if( array[i] == ')'){
					while ( s.topd()!='('){
						cout<<s.pop();
					}
					s.pop();
				}
				else if( array[i]=='('){
					s.push(array[i]);
				}
				else if( array[i]!=')' && pre(s.topd()) < pre(array[i])){
					s.push(array[i]);
				}
				else if(array[i]!=')' && pre(s.topd()) >= pre(array[i])){
					while( !s.isempty() && pre(s.topd())>=pre(array[i])){
						cout<<s.pop();
				    }
				    s.push(array[i]);
				}
			}
		}
	}
	while( !s.isempty()){
		cout<<s.pop();
	}
}

int pre(char a){
	if( a == '+' || a == '-')
		return 0;
	else if( a == '/' || a == '*')
		return 1;
	else if( a== '(' )
		return -1;		
}
