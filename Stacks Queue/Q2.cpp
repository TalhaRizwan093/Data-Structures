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
		if(top==-1){
			return 0;
		}
		else{
		    return s[top--];
		}
	}
	
	void display(){
		for( int i=top;i>=0;i--){
			cout<<s[i];
		}
		cout<<endl;
	}
	
	int topr(){
		return top;
	}
	
};

int main(){
	
	char s[100];
	
	cout<<"Enter the expression: ";
	cin>>s;
		int c=0;
	for( int i=0;s[i]!='\0';i++){
        c++;
}
	
	sta s1(c);
	bool check = true;
	char x;
	
	for( int i=0;i<c;i++){
		
		if(s[i] == '(' ){
		s1.push(s[i]);
		}
		
		else if(s[i]== ')' ){
			if(s1.topr()==-1){
				check = false;
				break;
			}
			else{
				s1.pop();
			}
		}
}

if( s1.topr()==-1 && check){
	cout<<"Valid.";
}
else{
	cout<<"Invalid.";
}
}
