using namespace std;

#include<iostream>

class PatientQueue{
	
	string *name;
	int *age;
	string *disease;
	int size;
	int front, rear;
	
public:
	PatientQueue(int s){
		size = s;
		name = new string[size];
		age = new int[size];
		disease = new string[size];
		front = -1;
		rear = -1;
	}
	PatientQueue(){
		size = 20;
		name = new string[size];
		age = new int[size];
		disease = new string[size];
		front = -1;
		rear = -1;
	}
	
	void display(){
		if(is_empty())
			cout << "Queue is empty";
		else{	
			for(int i = 0; i <= rear; i--){
				cout<<"\nPatient's Name is: " << name[i];
				cout<<"\nPatient's Age is: " << age[i];
				cout<<"\nPatient's Disease is: " << disease[i]<<endl;
			}
		}
	}
	
	bool is_empty(){
		if(rear == -1)
			return true;
		else
			return false;
	}
	
	bool is_full(){
		if(rear == size - 1)
			return true;
		else
			return false;
	}
	
	void priortize(){
		if(front != rear){
			int temp_age;
			string temp_name, temp_disease;
			for(int i = 0; i <= rear; i++) {		
				for(int j = i+1; j <= rear; j++){
					if(age[i] < age[j]) {
						temp_age = age[i];
						age[i] = age[j];
						age[j] = temp_age;
						
						temp_name = name[i];
						name[i] = name[j];
						name[j] = temp_name;
						
						temp_disease = disease[i];
						disease[i] = disease[j];
						disease[j] = temp_disease;
					}
				}
			}
		}
	}
	
	void enqueue(string p_name, int p_age, string p_disease){
		if(is_full())
			cout<<"Queue is Full";
		else {
			if(rear == -1)
				front = rear = 0;
			else
				rear++;
			name[rear] = p_name;
			age[rear] = p_age;
			disease[rear] = p_disease;
		}
		priortize();
	}
};

int main(){
	string p_name, p_disease, temp_name;
	int p_age, ch;
	
	PatientQueue p1;
	
	do{
		cout<<"\nPress 1 to add patient";
		cout<<"\nPress 2 to display patients";
		cout<<"\nPress 0 to exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		if(ch == 1){
			cout<<"Enter Patient's Name: ";
			cin >> p_name;
			cout<<"Enter Patient's Age: ";
			cin >> p_age;
			cout << "Enter the disease patient is suffering from: ";
			cin >> p_disease;
			p1.enqueue(p_name, p_age, p_disease);
		} else if(ch == 2){
			p1.display();
		}
	} while(ch != 0);
}
