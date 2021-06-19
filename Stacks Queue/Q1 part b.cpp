using namespace std;

#include "iostream"

struct SinglyLinkedList{
    char cha;
    SinglyLinkedList *next = NULL;
};

SinglyLinkedList *first = NULL;
SinglyLinkedList *last = NULL;

void display(){
    SinglyLinkedList *curr = first;
    while(curr != NULL){
        cout<<curr -> cha<<" ";
        curr = curr -> next;
    }
}

void push(char ch){
    SinglyLinkedList *curr = new SinglyLinkedList;
    curr -> cha = ch;

    if(last == NULL)
        first = last = curr;
    else{
        last -> next = curr;
        last = curr;
    }
}

int size(){
    SinglyLinkedList *curr = first;
    int size = 0;

    while(curr != NULL){
        size++;
        curr = curr -> next;
    }

    return size;
}

char pop(){
    SinglyLinkedList *curr = first;
    char a;

    while(curr -> next != NULL && curr -> next != last){
        curr = curr -> next;
    }

    if(curr -> next == NULL){
        a = last -> cha;
        first = last = NULL;
        return a;
    }
        a = curr -> next -> cha;

        curr -> next = NULL;
        last = curr;

    return a;
}

int main(){
    string input;
    bool palinCheck = true;

    cout<<"Enter a string you want to check for palindrome: ";
    cin>>input;

    for(int i = 0; i < input.length(); i++){
        push(input[i]);
    }

    for(int i = 0; i < input.length(); i++){
        if(input[i] != pop()){
            palinCheck = false;
            break;
        }
    }

    if(palinCheck)
        cout<<"String is Palindrome";
    else
        cout<<"String is not Palindrome";
}
