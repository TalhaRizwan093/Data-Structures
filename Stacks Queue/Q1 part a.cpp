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
	
};

int main(){
	
	char s[100];
	
	cout<<"Enter the word: ";
	cin>>s;
	
	int c=0;
	for( int i=0;s[i]!='\0';i++){
        c++;
}
	
	sta s1(c);

	for( int i=0;i<c;i++){
		s1.push(s[i]);
	}

	s1.display();

	bool check = true;
	int j = 0;
	
	while (j<c ){
		char a = s1.pop();
		if( a!=s[j]){
			check = false;
			break;
		}
		j++;
	} 
	
	if ( check ){
		cout<<"Palindrome.";
	}
	else{
		cout<<"Not palindrome.";
	}
	
}
